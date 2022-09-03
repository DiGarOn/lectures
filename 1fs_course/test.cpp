#include <iostream>

using namespace std;

#define MUL(a,b) a*b

#define COUNT 7*24*60*60

//11111011

int main() {

    uint8_t a = 0;
    a = a|8;
    a = a & 251;

    cout << a;

    return 0;
}