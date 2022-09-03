#include <iostream>
#include <vector>
#include <functional>
#include <array>

using namespace std;

/*

auto - автоматический вывод типа 
советуют - auto x = {3};
decltype - ключевое слово, которое вместо своего написания подсталяет тип своего аргумента
decltype(int) - все заменится на инт 
void(int a, float b) {
    typedef decltype(a*b) type;
    type t = ...;
}

template<typename T>
decltype(auto) func(int a, Tb) -> decltype(a*b) { ... } //хвостовой вывод типа. упрощает мозговые затраты
auto func(int a, Tb) -> decltype(a*b) { ... } - тоже можно 

std::vector<std::functional<std::array<int>&>> - с 11 стандарта нет ошибок

using std::vector<std::pair<T, T>> = vp;
vp<int> vec_pair_int;
vp<double> vec_pair_double;

constexpr - ключевой тип для переменных или функций . для переменных - это конст (значение гарантированно известно на этапе компиляции).
    для функций - функция получает возможность быть вычисленной в момент компиляции 

static_assert 
#define assert(n) \ 
    do { if(!(n)) {cerr << "assertion" << #n << "failed"; abort()}} while(0);

assert(y == 1);

static_assert(условие, сообщение);
__func__ 

*/


int main() {


    return 0;
}