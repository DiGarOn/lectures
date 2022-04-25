#include <Windows.h>
#include <thread>
#include <random>
#include <chrono>

using std::cout;
using std::endl;
using std::flush;

std::random_device rd;
std::mt19937 gen(rd);
std::uniform_int_distribution<> distrib(1, 10);

void thread_func() {
    int t = distrib(gen);
    cout << "thread "
        << std::this_thread::get_id()
        << " waiting for " << t << 's' << endl;
    std::this_thread::sleep_for(std::chrono::seconds(t));
}
/*
5) Параллельные потоки 
... 5.3) C++ std::thread

6) Синхронизация при параллельных вычислениях  
6.1) взаимные исключения

память - ресурс
поток - ресурс
threads - класс ресурсоемких объектов

Процесс(process) - это программа в стадии выполнения 
ОС с разделением времени 
ОС с реальным временем 

forc - копирование процесса в юникс системах 

Поток(thread) - это элемент процесса, представляющий собой какую-то функцию, которая выполняется в данный момент 

Критическая секция(critical section) - блок кода/часть программы, в котором происходит работа с данными.  И если эти данные изменятся, то происзрйдет калапс
Критической секцией называетс я блок кода, в котором выполняется работа с данными, результат которой зависит от неизменности этих данных.

конкуренция (data race) - 1 или более потоков конкурируют за доступ/за владением ресукром

взаимное исключение (mutex) - ограничения доступа к критическим секциям

тупиковая ситуация (olead lock) - тупиковой ситуацией называется состояние программы, в котрой ее работа не модет быть продолжена в результате 
    отсутствия доступа к ресурсам

CV - conditional value - 

7я глава Майерса

*/

/*
#include <mutex>
std::mutex mut;
void thread_fun() {
    std::lock_guard<std::mutex> P(mut); - решет проблему. тогда модно не писать unlock и не будет зависания мутекса 
    cout << value;
    value += 1;
    //if(...) return ; - так же вохзомжно создаст тупик
    cout << value;
    mut.unlock(); // - если закомментировать - будет тупик  
}
*/
/*
void thread_func() {
    cout << "Thread " 
        << std::this_thread::get_id()
        << endl;
}
*/
int main() {
    std::thread * threads[MAX_THREADS];
    cout << "Main Thread "
        << std::this_thread::get_id()
        << endl;
    for(size_t i = 0; i  <MAX_THREADS; ++i) {
        cout << "Creating thread "
            << i << " ..." << flush;
        threads[i] = new std::thread(thread_func);
    }
    int rc;
    for(size_t i = 0; i < MAX_THREADS; ++i) {
        cout << "Waiting thread "
            << i << " ..." << flush;
        rc = pthread_cond_wait(&cond, &mutex);
        //checkResults("pthread_cond_wait()\n", rc);
        //switch (ret){}
        threads[i]->join();
    }

    for(size_t i = 0; i < MAX_THREADS; ++i)
        delete threads[i];
    return 0;
}