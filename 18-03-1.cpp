#include <iostream>
#define MAX_THREADS 5
//#include <Windows.h>
#include <thread>
#include <random>
#include <chrono>

using std::cout;
using std::endl;
using std::flush;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(1, 10);
/*
void thread_func() {
    int t = distrib(gen);
    cout << "thread "
        << std::this_thread::get_id()
        << " waiting for " << t << 's' << endl;
    std::this_thread::sleep_for(std::chrono::seconds(t));
}
*/
class thread_class {
public: 
    void thread_func() {
        int t = distrib(gen);
        cout << "thread "
            << std::this_thread::get_id()
            << " waiting for " << t << 's' << endl;
        std::this_thread::sleep_for(std::chrono::seconds(t));
    }
};

int main() {
    std::thread * threads[MAX_THREADS];
    thread_class th_cl;
    cout << "Main Thread "
        << std::this_thread::get_id()
        << endl;
    for(size_t i = 0; i  <MAX_THREADS; ++i) {
        cout << "Creating thread "
            << i << " ..." << flush;
        threads[i] = new std::thread(&thread_class::thread_func, &th_cl);
    }
    int rc;
    for(size_t i = 0; i < MAX_THREADS; ++i) {
        cout << "Waiting thread "
            << i << " ..." << flush;
        //rc = pthread_cond_wait(&cond, &mutex);
        //checkResults("pthread_cond_wait()\n", rc);
        //switch (ret){}
        threads[i]->join();
    }

    for(size_t i = 0; i < MAX_THREADS; ++i)
        delete threads[i];
    return 0;
}