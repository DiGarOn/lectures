#include <iostream>

using namespace std;

export module A;
module : private;
export fun2();
export fun() {
    fun2();
}
void fun2() {
    cout << "hello";
}

/*

Модули  Си++20
module, import, export

export module name раздел attributes; - задает нам в данной единице трансляции интерфейс модуля
export определение
export {определение 1, определение 2}

export import имя атрибуты; - 
export import раздел атрибуты;
export import заголовочник атрибуты;

module; - помечает глобальную часть модуля
module : private; - если надо разделить интерфецсную часть от реализации. тут идет скрытая часть подуля




*/

int main() {


    return 0;
}