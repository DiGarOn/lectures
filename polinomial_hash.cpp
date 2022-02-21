#include <iostream>
#include <string>

using namespace std;

/*

* * * *   *       * * * * * *  * * * * *   * * * *     * * * * *   *       *       |   | 1, 
*      *  * *   * *     *          *       *      *        *        *     *        |   | 1, 
*       * *  * *  *     *          *       * * * *         *         *   *         | x6| 1, 
*       * *   *   *     *          *       * *             *           *           |   | 1, 
*      *  *       *     *          *       *   *           *           *           |   | 1, 
* * * *   *       * * * * * *      *       *     *     * * * * *       *           |   | 1, 

[*, ,*, ,*, ,*, , ] [*, , , , , , , ,*] [*, ,*, ,*, ,*, ,*]   [*, ,*, ,*, ,*, ,*]   [*, ,*, ,*, ,*, , ]   [*, ,*, ,*, ,*, ,*]   [*, , , , , , , ,*]       |   | 1, 
[*, , , , , , ,*, ] [*, ,*, , , ,*, ,*] [ , , , ,*, , , , ]   [ , , , ,*, , , , ]   [*, , , , , , ,*, ]   [ , , , ,*, , , , ]   [ ,*, , , , , ,*, ]       |   | 1, 
[*, , , , , , , ,*] [*, , ,*, ,*, , ,*] [ , , , ,*, , , , ]   [ , , , ,*, , , , ]   [*, ,*, ,*, ,*, , ]   [ , , , ,*, , , , ]   [ , ,*, , , ,*, , ]       | x6| 1, 
[*, , , , , , , ,*] [*, , , ,*, , , ,*] [ , , , ,*, , , , ]   [ , , , ,*, , , , ]   [*, ,*, , , , , , ]   [ , , , ,*, , , , ]   [ , , , ,*, , , , ]       |   | 1, 
[*, , , , , , ,*, ] [*, , , , , , , ,*] [ , , , ,*, , , , ]   [ , , , ,*, , , , ]   [*, , , ,*, , , , ]   [ , , , ,*, , , , ]   [ , , , ,*, , , , ]       |   | 1, 
[*, ,*, ,*, ,*, , ] [*, , , , , , , ,*] [*, ,*, ,*, ,*, ,*]   [ , , , ,*, , , , ]   [*, , , , , ,*, , ]   [*, ,*, ,*, ,*, ,*]   [ , , , ,*, , , , ]       |   | 1, 


*/

/*
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
*/

int q = 1000;
int R = 123987123;

int h(string s) {
    int res = 0;
    int val = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        res = (res + (int(s[i]) * val)%R)%R;
        val = (val*q)%R;
    }
    return res;
}

string str = "01234567890abcdefgjklmnopqtsuvwhyzABCDEFGJKLMNOPQTSUVWHYZ";

string create_string() {
    int len = rand() % 20;
    string res = "";
    for(int i = 0; i < len; i++) {
        res += str[rand()%str.size()];
    }
    return res;
}

int main() {

/*
    string s = "";
    for(int k = 0; k < str.size(); k++) {
        s += str[k];
        int c = h(s);
        string b = s;
        for(int j = 0; j < str.size(); j++) {
            for(int i = 0; i < 50; i++) {
                b += str[j];
                int d = h(b);
                if(c == d) {
                    cout << s << endl;
                    cout << b << endl;
                    exit(0);
                }
            }
            b = s;
        }
    }
*/

/*
    string s1, s2;
    s1 = create_string();
    s2 = create_string();
    
    while(!((s1 != s2) && (h(s1) == h(s2)))) {
        //cout << "s1: " << s1 << endl;
        //cout << "s2: " << s2 << endl;
        s1 = create_string();
        s2 = create_string();
    }
    
    cout << "s1: " << s1 << endl;
    //tNbC5VySk9Zlcv92
    cout << "s2: " << s2 << endl;
    //kpLDh5OTsnqNN037o
    s1 = "tNbC5VySk9Zlcv92";
    s2 = "kpLDh5OTsnqNN037o";
    cout << h(s1) << " : " << h(s2);
*/


//    string s = "hash";
//    cout << h(s);

    string s1, s2;
    s1 = create_string();
    s2 = create_string();
    
    while(!((s1 != s2) && (h(s1) == h(s2)))) {
        //cout << "s1: " << s1 << endl;
        //cout << "s2: " << s2 << endl;
        s1 = create_string();
        s2 = create_string();
    }
    
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    //aPSJt0Z0P1Hf
    //2VpjAEhs0yJdY
    //s1 = "aPSJt0Z0P1Hf";
    //s2 = "2VpjAEhs0yJdY";
    cout << h(s1) << " : " << h(s2)  << endl;

    s1 = "tNbC5VySk9Zlcv92";
    s2 = "kpLDh5OTsnqNN037o";
    cout << h(s1) << " : " << h(s2);
    return 0;
}