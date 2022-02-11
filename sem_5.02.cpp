#include <iostream>

using namespace std;

template<typename T> struct has_foo{
private:  // Спрячем от пользователя детали реализации.
    static int detect(...);  // Статическую функцию и вызывать проще.
    template<typename U> static decltype(std::declval<U>().foo()) detect(const U&);
public:
    static constexpr bool value = std::is_same<void, decltype(detect(std::declval<T>()))>::value;  // Вот видите, готово.
};

struct Print_detector
{
	static auto check(void*) -> void; // раз уж С++11, напишем в постфиксной форме - так красивее и однообразнее :)
	template<class T>
	static auto check(T* p) -> decltype(p->Print())*; // указатель на чего бы то ни было отличается от не-указателя

	typedef void* match_type; // но мы ожидаем конкретно void Print(), поэтому проверяем на void*
};

// менее громоздкий способ писать метафункции - это наследоваться от готовых
template<class T> struct has_Print : std::is_same<Print_detector::match_type, decltype(Print_detector::check((T*)nullptr))> {};


struct P { void Print(); };
struct Q0 { };
struct Q1 { void Print(); };
struct Q2 { int  Print(); };
struct Q3 { int  Print(); };

struct WW {void foo();};
struct WQ {};

int main()
{
	std::cout << has_Print<P >::value << std::endl;
	std::cout << has_Print<Q0>::value << std::endl;
	std::cout << has_Print<Q1>::value << std::endl;
	std::cout << has_Print<Q2>::value << std::endl;
	std::cout << has_Print<Q3>::value << std::endl;
    int a = 5;
    std::cout << (typeid(int) == typeid(a)) << std::endl;
    cout << "______________________" << std::endl;
    std::cout << boolalpha << has_foo<WW>::value << std::endl;
    std::cout << boolalpha << has_foo<WQ>::value << std::endl;
}

