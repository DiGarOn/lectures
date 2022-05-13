#include <iostream>
#include <functional>
using namespace std;

/*

for - по диапозону
default, delete
пречисление с областью видимости 
inicialiser_list
дилигирующие конструкторы
инициализация членов класса 
унаследование конструкторов 
long long
nullptr
noexcept

1) lonh long - тип данных (long long int) отличается от long int и не может быть рассмотрено как состовная часть
    (нельзя написать long long long / short long long). занимает минимум 64 бита в памяти. 

2) nullptr - спецаильный тип данных для обозначения нулевого указателя. в отличие от 0 и NULL = (void*)0 - не указатель
    double d = 3.14;
    double * pd1 = 0;
    double * pd2 = &d;
    double * pd3 = nullptr;
    pd1 == pd3 - верно, но (0 != nullptr)

void func(int);
void func(char *) - сюда пихать nullptr, чтобы вызвать от 0

3) throw    - (throw 42;) для запуска исключения 
            - class A {
            public:
                void func() throw() { - ограничение типов запускаемвых исключений
                    throw std::runtime_error("LOL") - ошибка
                 } 
            }
noexcept - ключевое слово. пишется после скоробо функции (функции запрещено запускать какие-либо исключения)
    на эту функцию отключается механизм проверки исключений. на все функции, окторые находятся внутри нее это правила
    распростроняются

4) перечисление с огбластью видимости - 
    enum class colors : int { - тип можно не указывать (по умолсчанию int)
        red,
        green,
        blue
    }
    enum class week { moday, tuseday}
    enum colors c;
    if(c == colors::red); - yes
    if(c == 0); - no
    if(c == week::monday); - no

5) for по диапозону (range-for range based for)
    for(i (элемент): mas (коллекция)) {}

    коллекция - все, у чего есть начало и конец. статический массив относится к коллекции

    for(const auto &i : {1,3,7,9}) { cout << i << endl;}

6) default, delete
    default -  
    delete - 

    class Matrix4x4 {
        int data[16];
    public:
        Matrix4x4(Matrix4x4&&) = delete; // запретили перемещащий конкруткор 
        Matrix4x4&& operator = (Matrix4x4&&) = delete // запретили перемещающий оператор присваивания 
        Matrix4x4(const Matrix4x4&) = default; // сделат побитовую копию 
        Matrix4x4& operator = (Matrix4x4&) = default; // сделает побитовую копию 
    }

7) инициализация членов

    class Matrix {
        size_t rows = 10;
        size_t cols = 10;
    public:
        Matrix() {}
        Matrix(size_t rows) : rows(rows) {}
        Matrix(size_t cols) : cols(cols) {}
        Matrix(size_t rows, size_t cols) : cols(cols), rows(rows) {}
    };

8) делигирующие конструкторы
    
    class A {
        int * p;
        std::string state;
    public:
        A(size_t n) {p = new int[n];}
        A(size_t n, std::string s) : A{n}, state{s} {}
    }

9) унаследованные конструкторы

    class Base {
    pyblic:
        Base(size_t n);
        void internal();
    };
    class Derived : protected Base {
    public:
        using Base::Base(size_t n); // тперь так можно 
        using void Base::internal();
    }

*/

int main() {
    double d = 3.14;
    double * pd1 = 0;
    double * pd2 = &d;
    double * pd3 = nullptr;
    cout << (pd1 == pd3);
    //std::function;
    return 0;
}