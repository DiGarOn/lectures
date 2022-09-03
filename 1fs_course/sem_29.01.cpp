#include <iostream>

using namespace std;

/*
template<typename T>
T mal(T a, T b) {
    return(a>=b?a:b);
}
*/
/*
template<typename t1, typename t2>
void print(t1 a, t2 b) {
    cout << a << " " << b << endl;
}
*/
/*
void print(int a, int b) {
    cout << "int " << a << " " << b << endl; 
}
*/
/*
template<typename t1, typename t2>
void print(t1 a, t2 b) {
    cout << a << " " << b << endl;
}
*/

template<typename t>
void print_average_mark(const char* name, t a, t b, t c) {
    t d = (a + b + c)/3;
    cout << name << "\'s average mark: " << d << endl;
}

void print_average_mark(const char* name, const char A, const char B, const char C) {
    int a, b, c;

    if(A == 'A') a = 5;
    if(A == 'B') a = 4;
    if(A == 'C') a = 3;
    if(A == 'D') a = 3;
    if(A == 'F') a = 2;

    if(B == 'A') b = 5;
    if(B == 'B') b = 4;
    if(B == 'C') b = 3;
    if(B == 'D') b = 3;
    if(B == 'F') b = 2;

    if(C == 'A') c = 5;
    if(C == 'B') c = 4;
    if(C == 'C') c = 3;
    if(C == 'D') c = 3;
    if(C == 'F') c = 2;


    int d = (a + b + c)/3;
    cout << name << "\'s average mark: " << d << endl;
}



template<typename t>
void print_average_mark(const char* name, t a, t b) {
    t d = (a + b)/2;
    cout << name << "\'s average mark: " << d << endl;
}

void print_average_mark(const char* name, const char A, const char B) {
    int a, b, c;

    if(A == 'A') a = 5;
    if(A == 'B') a = 4;
    if(A == 'C') a = 3;
    if(A == 'D') a = 3;
    if(A == 'F') a = 2;

    if(B == 'A') b = 5;
    if(B == 'B') b = 4;
    if(B == 'C') b = 3;
    if(B == 'D') b = 3;
    if(B == 'F') b = 2;


    int d = (a + b)/2;
    cout << name << "\'s average mark: " << d << endl;
}

int main() {
    /*
    int a, b;
    a = 5;
    b = 6;
    cout << mal<int>(a, b) << endl;
    cout << mal(a,b) << endl;
    char c = 'r';
    cout << mal<int>(a, c);
    */

   const char *name1 = "Dmitriy";
   const int mark_1_1 = 5;
   const int mark_2_1 = 4;
   const int mark_3_1 = 3;

   print_average_mark(name1, mark_1_1, mark_2_1, mark_3_1);
    
    const char *name2 = "Alex";
    const double mark_1_2 = 4.45;
    const double mark_2_2 = 3.55;
    const double mark_3_2 = 2.0;

    const char *name3 = "Max";
    const float mark_1_3 = 5.0;
    const float mark_2_3 = 4.455;
    const float mark_3_3 = 1.5;

    print_average_mark(name2, mark_1_2, mark_2_2, mark_3_2);
    print_average_mark(name3, mark_1_3, mark_2_3, mark_3_3);

    const char *name4 = "ALLALALALA";
    const char mark_1_4 = 'A';
    const char mark_2_4 = 'B';
    const char mark_3_4 = 'C';

    print_average_mark(name4, mark_1_4, mark_2_4, mark_3_4);

    const char *name5 = "Dmitriy1";
    const int mark_1_5 = 5;
    const int mark_2_5 = 4;
    print_average_mark(name5, mark_1_5, mark_2_5);

    return 0;
}