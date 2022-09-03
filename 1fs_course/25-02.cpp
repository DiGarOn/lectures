#include <iostream>
#include <list>
#include <map>

using namespace std;

/*

Функторы (функциональные объекты)
все, что нужно вызывать 
Класс, в котором перегружен "()"


std::bind2nd + std::plus() -> transform

ПЛАН:
1) введение в функторы 
2) Расширенные возможности применения функторов 
3) Си++11: любда вырражения 
4) СИ++11: режимы захвата Л.В.


*/

template<typename T>
T fun(T a, T b) {
//  return a+b;
    return plus(a,b);
}

template<typename T>
class avg {
    T average;
    size_t num;
public:
    const T & value() const { 
        if(num != 0) return average/num;
        return average; 
    }
    avg() : average(), num(0) {}
    void operator () (const T& val) { average += val; num += 1; } 
};

struct record {
    std::string firstname;
    std::string lastname;
    std::string middlename;
};

struct student {
    std::pair<double, size_t> pos;  //GPA и рейтинг
    struct record & name;          //ФИО

    student(double gpa, size_t rate, record & rec) : pos(gpa, rate), name(rec) {}
};


int main() {
    list<int> c;
    c.push_back(1);
    /*...

    avg<int> avg_int;
    for_each(c.begin(), c.end(), avg_int);

    cout << avg_int.value();
*/
    //-----------------------------------------------------

    int avg_int = 0;
    size_t num = 0;
    //= - по значению
    //& - по ссылке
    //  - по 
    for_each(c.begin(), c.end(), [&](int val){avg_int += val; num += 1;}); //лямбда 
    cout << avg_int/num;

    std::list<record> db;

    std::map<size_t, student, [](const student & a, const student & b) {
        int match = a.name.lastname < b.name.lastname;
        if(match == 0) return a.name.firstname < b.name.firstname;
        return match;
    }>table;

    record rec;
    size_t unq = 0;
    rec.firstname = "Faith";
    rec.lastname = "Sofia";
    rec.middlename = "";
    //stud.pos.first = 3.14;
    //stud.pos.second = 0;
    //stud.name = rec;
    db.push_back(rec);

    table[unq]=student(3.14, 0, db.back());
    unq++;

    return 0;
}