#include<iostream>

using namespace std;

/*

*/

/*
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
*/

void swap(int &&a, int &&b) {
    int tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

// void funcB(int && b) {cout << "here";}

// void funcA(int && a) {
//     /*...*/
//     funcB(std::forward(a));
//     /*...*/
// }

class A {
    std::string s;
public:
    /* 1 - 2 копи */ //A(const std::string s) : s(s) {}; - совершенно не нежуен
    /* 2 - 1 копия */A(const std::string & s) : s(s) {};
    /* 3 - 0 копий */A(std::string && s) : s(std::move(s)) {};
};

int && fu() {return std::move(42);} 

//std::auto_ptr
//Си++98/03 :   std::auto_ptr - появилось и должно было при работе с неокторыми ресурсами записывать количество пользователей
//  и не удалять, пока есть пользователи и только потом затереть реализовано чаще всего через семафоры
//  оно не работает так, как надо, потому не будем использовать 

//Си++11/14 :   std::unique_ptr - вместо авто птр. это тип шаблонизированный, который вырождается. он почти всегда вырождается
//  до обычного указателя. для него запрещено копирование (только перемещаемый). при выхоже из блока память будет уничтожаться
//  по умолчанию delete, но можно написать свое. гарантируется перемещение ресурса. 
//              std::shared_ptr - указатель, доступный одновременно нескольким владельцам. уничтожение объекта, когда
//  количества владельцев = 0. там много проверок и потому оно работает медленнее. при многопоточности можно словить блокировки
//              std::weak_ptr - слабый указатель (указатель слабой связности ) позволяет сокротить проверки на пользователей 
//  можно уничтожить даже если им кто-то пользуется. позволяет пользоваться тем объектом, который может быть уничтожен, пока
//  им будут пользоваться. 

//В Си++ !!для виртуальных функций!!
//override - говорит о том, что виртуальная функция перегружена
//final - дальнейшая перегрузка этой виртуальной функции невозможна

class C {
public:
    virtual void f();
    virtual void g() const;
    void h();
};

class D : public C {
public: 
    void f() final;
    void g() const override;
    void h();
};

int main() {
    // int a = func();
    // int& ra = a;
    // //int& rb = func(); - так нельзя
    // int && rva = func(); // а так можно
    // //int && rvb = a; - так нельзя

    A a("Hello"); 
    //  создается временный объект std::string 

    //auto f = [](){};
    //void f(decltype(f));
    int b = fu();
    cout << b;

    return 0;
}