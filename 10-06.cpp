#include <iostream>
#include <vector>
#include <variant>

using namespace std;

/*

Новые возможности Си++20
    std::any - показывает, что функция может возврать что-угодно. это тип данных. подменяет собой любой другой. 
    std::optional<T> - функция возвращает либо тип Т, либо ничего не возвращает. тип данных.
    std::variant<T, S, V, ...> - функция возвращает один из указанных типов данных. НЕ может вернуть ничего. 

Старые/новые возможности Си++20
    Концепты - это проверка на этапе компиляции на выполнение некоторого условия над некоторыми данными
    
template<ForwardIterator Iter, class V> //- определен концепт ForwardIterator. выполняется проверка

requires Assignable<Iter::value_type ,V> // - requires - указывает о наличии или создании концепта - второй способ написать то, что строкой выше

void fill(Iter, const&V);

fill(0, 0); //-не вызовется
int *p;
fill(p, 0); //-можно так

    requires - ключевое слово 
    <iterator> ForwardIterator
    Assignable

template<typename T> concept C1 = true;
requires concept;

//создание концепта
template<class T>
concept Integral = std::is_integral<T>::value; //- проверка, что тип целочисленный. если не тру, то концепт не удовлетворится и не скомпилируется
//функция должна быть constexpr  (выполняться на этапе компиляции, тк проверка происходит там)

template<class T>
concept SignedIntegral = Integral<T> && std::is_signed<T>::value;

template<class T>
concept Addable = requires (T a, T b) {a+b;};

template<class T, class U>
concept Swappable = requires (T && t, U && u) {std::swap(std::forward<T>(t), std::forward<U>(u));
                                                std::swap(std::forward<U>(u), std::forward<T>(t));};

template<class T> 
concept A = requires(T x) {
    {x + 1} -> std::same_as<int>;
};

struct Discipline {
    std::string name = "unknown";
    size_t students = 0;
    double gpa = 0.;
};

Discipline PL = {"ЯП"};
//designated initializer
Discipline PL = {.name = "PL", .students = 0, .gpa = 0.};

new -> make_unique
std::shared_ptr = make_unique<int>();


enum class fruits {apple, banana, orange};
enum class coloues {green, orange, yellow};
void func() {
    using enum fruits;
    using enum colours; // error
}

constinit - если какая-то переменная даже объявлена статической или константной, то никто не гарантирует, что она получит свое значение при компиляции.
    отложено быть не может и переменная получит значение в момент инийиализации. либо константой либо constexpr 
consteval - для функций. это функции, которые гарантированно будут вычислены в момент компиляции. Гарантированно не попадает в рантайм


*/

class Object {
public:
    void Act() const;
    void Mut1();
    void Mut2();
};

class Visitor {
public:
    void visit(Object *);
};

struct Malt{};
struct Hops{};
struct Yast{};
struct VisitPackage {
    void operator()(const Malt &) {cout << "Malt" << endl;}
    void operator()(const Hops &) {cout << "Malt" << endl;}
    void operator()(const Yast &) {cout << "Malt" << endl;}
};

int main() {

    std::variant<Malt, Hops, Yast> package = {Malt()};

    std::visit(VisitPackage(), package);
/*
    std::vector<Object *> objs;
    for(const auto & i:objs) {
        i->Act();
    }
    
    //Паттерн Посетитель
    Visitor v;
    for(const auto & i:objs) {
        v.visit(i);
    }
*/

    return 0;
}