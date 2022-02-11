#include <iostream>
#include <iterator>
#include <algorithm>


//вопрос - а можно ли создавать разделители для шаблонов? (тип мне нужен отдельный вид шаблонов
//для любых массивов и отдлельно для обычных типов данных)



int main() {
    std::cin.unsetf(std::ios::skipws);

    std::istream_iterator<char> eos;
    std::istream_iterator<char> it(std::cin);
    std::ostream_iterator<char> ot(std::cout);

    std::cout << __cplusplus << std::endl;
/*
    while(it != eos) {
        *ot = *it;
        ++it;
    }
*/

    std::copy(it,eos,ot);
    return 0;
}