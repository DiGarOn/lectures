#include <iostream>
#include <string>

using namespace std;

size_t pow(size_t g, size_t k, size_t m) {
    //рассмотрим немного крайних случаев
    if(g == 0) {
        if(k == 0) {
            cout << "0^0 не определен" << endl;
            return m+1; //можно обработать, ведь по модулю м не может вернуться число большее м
        } else {
            return 0; //0 в любой степени - 0
        }
    } else { 
        if(k == 0) {
            return 1; //люое число в 0й степени = 1 
        } else {
            size_t res = 1; //результат
            size_t val = g; //переменная, которая накапливает степени по модулю (1, 2, 4, 8...)
            while(k > 0) {
                if(k & 1) { //сравниваю последний бит (последнюю цифру в двичной записи) с 1
                    res *= val; //тк степень представлена в двичном виде, то и умножать результат будем на числа в степенях степеней двойки
                    res = res % m; 
                }
                val *= val; 
                val = val % m;
                k = k >> 1; //побитовый сдвиг вправо, по сути производит челочисленное деление на 2 за 1 такт процессора
            } 
            return res;
        }
    }
}

//решение работает примерно за логарифм

int q = 3;
int R = 256;

int h(string s) {
    int res = 0;
    int val = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        res = (res + (int(s[i]) * val)%R)%R;
        val = (val*q)%R;
    }
    return res;
}

int main() {
    string s = "ABACB";

    cout << h(s);

    return 0;
}