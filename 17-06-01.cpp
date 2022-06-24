#include <iostream>
#include <compare>

using namespace std;

/*
Трехстороннее сравнение <=>
1) == // -----------------------------\
2) != //не нужно в С++20               -  не нужно в Си++20
3) <  // -----------------------------/
4) <= //
5) >  // yt ye;yj d Cb++20
6) >= //

строго упорядоченные - stron_oredering
частично упорядоченные
слабо упорядоченные - weak_ordering

if((a<=>b) == std::strong_ordering::equal) 
надо <compare>



*/

class MagicPivo {
    auto name  = u8"Default";
    auto action = [](){cout << "Adopt 0.5" << endl;};
public:
    [[nodiscard]] auto operator <=> (const &MagicPivo) const noexcept = default;

};

[[nodiscard]] auto operator <=> (const &MagicPivo rhs) const noexcept {
    auto cmp = name <=> rhs.name;
    if(cmp != 0) return cmp;
    return 0;
}

int main() {


    return 0;
}