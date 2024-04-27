#include <type_traits>
#include <iostream>
#include <cassert>

// определение возвращаемого значения функции
template <typename F, typename... Args>
using invoke_result_t = std::invoke_result_t<F, Args...>;

int add(int a, int b) {return a + b; }

//проверка типа на целочисленность
template <typename T>
constexpr bool integral() {
    return std::is_integral_v<T>;
}

template <typename T>
void print_if_integral(T value) {
    if constexpr (integral<T>()) {
        std::cout << "Value is integral: " << value << std::endl; 
    } else {
        std::cout << "Value is not integral" << std::endl;
    }
}

 //создание типа с const-модификатором
 template <typename T>
 using add_const_t = std::add_const_t<T>;

int main(int argc, char** argv) {
    //
    invoke_result_t<decltype(add), int, int> result = add(1, 2);
    assert((std::is_same<invoke_result_t<decltype(add), int, int>, int>::value));
    //
    print_if_integral(42);
    print_if_integral(3.14);
    assert(integral<int>());
    assert(!integral<double>());
    //
    int x{42};
    add_const_t<int> y = x;
    assert((std::is_same<const int, add_const_t<int>>::value));

    return 0;
}