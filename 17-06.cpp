#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

/*

Возможности Си++20 для манипулирования битовыми посмледовательностями :
    <bit>
    rotl(val, n)
    rotr(val, n)
    countl_zero(val)
    countr_zero(val)
    countl_one(val)
    countr_one(val)
    popcount(val) - количество единичных битов 
    has_signable_bit(val)
    bit_floor(val) - окр до предыдущего кратного двойке
    bit_ceil(val) - окр до следующего кратного двойке
    bit_width(val)

    contigous - итератор (по непрерывному диапазону данных. расширение итератора произвольного доступа. накладывает ограничение на то, что 
        аддресуемая память расположена последовательно)
    std::span - (C++20) - ивд/рамка/кусок - используется стандартно при работе с матрицами (например в виде строки или столбца
        не содержат данные. предоставляют доступ к объектам, которые где-то есть. с ними можно итерировать) (требует contigous iterator)
        hпедусмотрены операции и объекты меняются еще и в начальном объекте + есть стандартные функции
    std::string_view (Си++17) - возможность солздать строку или подстроку на основе уже существующего объекта std::string
        он не позволяет изменять объекты внутри строки. работа только на чтение 

    диапазоны (Ranges) - нова часть стандартной библиотеки
    std::ranges. все элементы в простанстве имен std::ranges. 
    std::rangeds::views 
    ||
    std::views 
    концепция итераторов меняется. начинают принимать не пару (итератор на начало и на конец), а диапазон, который содержит в себе
        все необходимую информацию. это абстракция, которая инкапсулирует иформацию об отрывке памяти 

    sentinel - позволяет сделать не конечную последовательность, а счетную
        идейно - итератор, но по факту - не итератор
    

    

*/

int main() {
    std::vector<int> coll{25,42,2,0,122,5,7};
    std::ranges::sort(coll);

    // auto v = coll   |std::views::filter([](auto e){return e%3 == 0;})
    //                 |std::views::transform([](auto e){return e*e;})
    //                 |std::views::take(3);

    auto v = std::views::common(coll.begin(), EndValue<0>{});

    //std::ranges::for_each(coll.begin(), EndValue<0>{}, [](auto e){std::cout << e << ',';});
    std::ranges::for_each(v.begin(), v.end(), [](auto e){std::cout << e << ',';});
    std::cout << '\b' << std::endl;

    return 0;
}