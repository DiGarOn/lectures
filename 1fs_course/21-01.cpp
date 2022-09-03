#include <iostream>

using namespace std;

//template<class CharType, class Attr = char_traits<CharType>, class Allocator = allocator<T> > class basic_string;

/*
bool used[1000] = {false};
int dfs (int v){
    used[v] = true;
    for (auto x : aboba[x]){
        if (!used[x]){
            mx = max()
            return dfs(x);
        }
    }
}
*/


/*

класс string
std::basic_string<  class CharType, 
                    class Attr = char_traits<CharType>, 
                    class Allocator = allocator<t> >;

typoedef basic_string<char> string;
#include <string>

некоторые конструкторы basic_string 
basic_string(size_type len, CharType ch, const Allocator &a = Allocatoor());
basic_string(CharType *str, const Allocator &a = Allocatoor());
basic_string(CharType *str, size_type len, const Allocator &a = Allocatoor());

методы класса basic_string
операции сравнения ==, <, <=, !=, >, >=

некоторые методы класса std::string
string &append(comst string& str);
template<class InIter>
    string& append(InIter start, InIter end);

string &assign(const string &str);
string &assign(const string& str, size_type ind, syze_type len);
template<class InIter>
    string& assign(InIter start, InIter end);

reference at(size_type ind); 
||
char&
-----------------------------------------------------------696 Шилдт
int compare(const string& s);  можно самим ввести правила сравнения 

size_type copy(CharType *s, size_type len, size_type ind = 0) const;

|   iterator begin();  |  !!
|   inerator end();    |  !!

size_type find(const string &str, size_type ind = 0) const;

reference operator[](size_type ind);
const_referrevce operator[](size_type ind) const;

iterator rbegin(); // != end()
iterator rend();
*/

/*

Концепция итераторов 
Особый тип, который позволяет получить доступ к элементу контйнера путем применения оператопрации разыменования

вывода (Output) /// вводв (Input) / прямого доступа (Forward) / двунаправленный (Bidirectional) / происзвольного доступа (Random access)




*/

string::iterator; 





int main() {


    return 0;
}