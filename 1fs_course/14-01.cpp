#include <iostream>

using namespace std;

/*

Си++:
____теория
    основа: ключевые слова и конструкции
    ооп состовляющая: классы, наследование, полеморфизм
    +исключения
___Си++: практика
    основы системы ввода/вывода
    файловые потоки
осталось:
    шаблоны(template)
    средства библиотеки: STL


    Обобщенное программирование (Мета программирование):
*/

template<typename T, typename U = size_t>
size_t find_min(const T *a, U s) {
    U i = 0;
    if(a != 0) {
        T m = a[0];
        for(U j = 1; j < s; ++j) {
            if(a[j] < m) {m = a[j]; i = j;}
        }
    }
    return i;
}
/*
template<typename T>
class Q {
public:
    Q();
};

template<typename T>
Q<T>::Q() {
    ;
}

class W {
private:
    ;
public:
    template<typename T>
    W operrator +(const T&) {
        ;
    }
};
*/


/*
    STL:
        контейнеры 
        итераторы
        функторы
        алгоритмы
*/


int main() {
    

    return 0;
}