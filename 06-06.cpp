#include <iostream>

using namespace std;

/*
План:
    аттрибуты - Си++11
    inline  - namespace - Си++11
    _____________________________
    inline - переменные - Си++17
    Шаблоны - СИ++17

Аттрибуты:
    [[имя_аттрибута]] сущность;

    [[noreturn]]
    void my_exit_func();

    void [[noreturn]] myexit_func();

noreturn - не возвращает управление
carries_dependency - зависит от семантики переноса
    можно обращаться к внутренней части. можно писать свои , может быть список аттрибутов через запятую
___________________________________________ Си++11
deprecated - говорит, что этим не надо пользоваться
deprecated("message") - почему не стоит польщоваться (например эта функция заменена на что-то другое)
___________________________________________ Си++14
fallthrogh - в switch, когда хотите сказать, Что несколько условий свича логически соединены (их надо перескочить)
    switch(simbol) {
        case '0':
        case '1':
            //и тд и тп
        case '9': process_digit(simbol); break;
        case 'A':
        case 'B':
            //...
        default: // ...
    }

nodiscard - аттрибут, который применяется к функции и сообщает о том, что ее сообщаемое значение не может быть откинуто 
nodiscard("massage") - Си++20

[[nodiscard]]
char* make_string() {
    return new char[255];
}

maybe_unused - для компилятора, чтобы он не удалил переменную, которая возможно не используется. нужно чаще всего для дебага
_____________________________________________ Си++17
likely - используется для ветвления или типа того. подсказка, что скорее всего этот путь при ветвлени будет использщоваться наиболее часто 
unlikely - антипод лайкли
no_unique_address - когда в классе дозрена элементов могут быть просто путые (вырожденные) объекты, у которых нет ничего, но они занимают место. 
    их можно пометить эти тогда память под них не будет выделяться 
_____________________________________________ Си++20

1pAB0Fe-F - число с плавоющей точкой в 16-ти ричной системой

анчиная с Си++17 можно созджавать вложенные пространства имен:
    namespace A::B{...} - сейчас

    namespace A{namespace B{...}} - заньше

Си++11;
    namespace X {
        inline namespace A {
            int p = 0 - X::p - корректно 
        }
    } - при определении пространства имен приводит к тому, что все элеенты этого пространства имен считаются перекрывающими

с Си++17:
    class C {
        inline static int x = 7; - inline переменные
    } - то же, что и инлайн функции, только вот. с точки зрения организации доступа к данным пример с классом и статиком не обязателен

operato ++(bool) - нельзя

throw() <=> noexcept - с 17 нельзя
throw(имя типа) - запрещено к использования

noexcept с 17го стандарта - часть сигнатуры

Аттрибуты Си++17:
    [[using gnu::имя1, имя2]][[noreturn]]
    void ...
    [[gnu::имя1, gnu::имя2, noreturn]]

Си++11:
auto sum() {return 0;}

tempalte <typename T1, typename ... ARGS>
T1 sum(T1 t, ARGS... args) {
    return t+sum(args); //Cи++ 17 fold expression //1) return(args+...+0); //2) reeturn(args+...);
}

autoptr - нельзя

auto y{3} // - просто инт  
auto x = {3}; //- сразу инициализиружщий лист

//напомнить про пример исключения копирования 

if constexpr(условие)

template<typename Args>
T1 sum(Args... args) {}

auto [a,b] = getValues();

Си++20: Новый любимый оператор 
operator <=>





*/

int main() {


    return 0;
}