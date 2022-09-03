#include <iostream>
#include <thread>
#include <future>

//using namespace std;

/*

5) Параллельные потоки
.
.
.
6) Синхронизация 
7) (Придумать название) std::async
ЛР: Исключения - на модуль 4
    контейнеры/алгоритмы
    потоки/таймер
    



std::future<int> - тип данных шаблонизированный языка с++ с 11 стандарта - нужен для того, Чтобы получить результат, который будет нужен 
в будущем

std::promise<int> p;
std::future<int> fut = p.get_future();

*/

template<typename T>
size_t find_min_(T* a, size_t s) {
    T m = a[0];
    size_t i = 0;
    for(size_t j = 1; j < s; ++j) {
        if(a[j] < m) {
            m = a[j];
            i = j;
        }
    }
    return i;
}

template<typename T>
size_t find_min(T* a, size_t s, size_t p = 2) {
    //T res[p];

    std::future<size_t> *res = new std::future<size_t>[p];
    for(size_t i = 0; i < p; ++i) 
        res[i] = std::async(find_min_, a+i*(s/p), s/p);//!!!
    
    size_t *val = new size_t[p];
    for(size_t i = 0; i < p; ++i) val[i] = res[i].get();
    size_t m = find_min_(val, p);
    delete[]val;
    delete[]res;
    return m;
}

int main() {
    //std::promise<int> p;
    //std::future<int> fut = std::async(0, [](){return 42;});

    //0 - стратегия выполнения (std::lunch::async, std::lunch::deffered)

    //fut.wait
    //fut.eait_for(...)
    //fut_get
    
    

    return 0;
}