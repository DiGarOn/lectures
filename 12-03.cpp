
/*
План: 
1) принципы архитекьуры Фон-Неймона
2) Классификация ЦПУ
3) Таксономия Флинна
4) Классификация по фоступу к памяти
5) Параллельные потоки 
    5.1) потоки posix threads  
    5.2) WIN.API
    5.3) C++11 std::thread
6)
    6.1) MPI
    6.2) OpenMP

Принципы Фон-Неймона
1) двоичная система
2) Адресуемая память 
3) однородность памяти 
4) принцип программного управления 
5) посмледовательность выполнения 

Классификация ЦПУ
набор команд:
    CISK - complex
    RISK - redused SSE

Таксономия Флиння
    
    SISD - Single Instruction set/Single Data set 
    SIMD - Single Instruction set/Multiple Data set
    MISD - Multiple Instruction set/Single Data set - не существует      
    MIMD - Multiple Instruction set/Multiple Data set 

    Shared Memory
    
    Uniform
    Memory
    Access
    (UMA)

    S
    M - multi
    P - processing

    NUMA
    DSM
    
    !ВАЖНО!:
    векторные инструкции -> 2
    многопроцессорные системы ->3
    вычислительные кластеры ->4

    Параллельные потоки 
        Начало
           |
        |_____|
           |
    1   создание потока
           |
        |______|
           |
        _________
        ---------
           |
    2   функци потока
           |
        ___________
        ----------
           |
        |________|
           |
    3   синхронизация 
           |
        |_________|
           |
        конец 
*/
//POSIX Threads Введение 
//#include <pthread.h>
//pthread_t //тип дпнных, который сопоставляется с одним потоком. в явном виде айдишник не достается через библиотеку
//pthread_create //создание потока
//pthread_exit //закрытие потока
//pthread_join //снхронизация потоков
//pthread_self() возвращает pthread_t
/*
#include<iostream>
#define THREAD_NUM 4
#include <pthread.h>

void * thread_func(void *) {
    for(size_t i = 0; i < 2; ++i)
        std:: cout << pthread_self() << std::endl << std::flush; //flush - протолкнуть буфер до устройства назначения 
    pthread_exit(0);
    return 0;//не выполнится , но требование синтаксиса
}

int main() {
    pthread_t threads[THREAD_NUM];
    for(size_t i = 0; i < THREAD_NUM; ++i) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }
    for(size_t i = 0; i < THREAD_NUM; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
*/

/*

//CreateThread
//GetCurrentThreadId
//ExitThread
//WaitForSingleObject
//CloseHandle
#include<iostream>
#define THREAD_NUM 4
#include <windows.h>

DWORD WINAPI thread_func(void *) {
    for(size_t i = 0; i < 2; ++i)
        std:: cout << GetCurrentThreadId() << std::endl << std::flush; //flush - протолкнуть буфер до устройства назначения 
    ExitThread(0);
    return 0;//не выполнится , но требование синтаксиса
}

int main() {
    HANDLE threads[THREAD_NUM];
    for(size_t i = 0; i < THREAD_NUM; ++i) {
        threads[i] = CreateThread(NULL, 0, thread_func, NULL, 0, NULL);
    }
    for(size_t i = 0; i < THREAD_NUM; ++i) {
        WaitForSingleObject(threads[i], INFINITE);
    }
    return 0;
}
*/

//С++11 str::thread
//#include <thread>
//std::thread()
//std::join
//join()
//get_id()

#include <thread>
#include <iostream>
#define THREAD_NUM 4

void * thread_func(void *) {
    for(size_t i = 0; i < 2; ++i)
        std:: cout << std::this_thread::get_id() << std::endl << std::flush; //flush - протолкнуть буфер до устройства назначения 
    return 0;
}

int main() {
    std::thread * threads[THREAD_NUM];
    for(size_t i = 0; i < THREAD_NUM; ++i) {
        threads[i] = new std::thread(thread_func, NULL);
    }
    for(size_t i = 0; i < THREAD_NUM; ++i) {
        threads[i]->join();
    }
    return 0;
}