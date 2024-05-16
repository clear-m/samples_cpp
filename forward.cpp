#include <iostream>
#include <cassert>
#include <utility>

bool foo(int &&x)
{
    std::cout << " RValue X: " << x << "\n";
    return true;
}

bool foo(int &x)
{
    std::cout << " Lvalue X: " << x << "\n";
    return false;
}

template <typename T>
bool forward_wrapper(T &&arg)
{
    return foo(std::forward<T>(arg));
}

template <typename T>
bool wrapper(T &&arg)
{
    return foo(arg);
}

// TODO: add tests here
template <typename T>
struct is_lvalue_reference: std::false_type {};

template <typename T>
struct is_lvalue_reference<T&> : std::true_type {};

template <typename T>
T &&forward(std::remove_reference_t<T> &value) //  preserve the value category of the argument
{
    return static_cast<T &&>(value);
}

template <typename T>
T &&forward(std::remove_reference<T> &&value) //  preserve the value category of the argument
{
    //static_assert(!std::is_lvalue_reference_v<T>);
    static_assert(!is_lvalue_reference<T>::value);
    return static_cast<T &&>(value);
}

template <typename T>
std::remove_reference_t<T> &&move(T &&value) // transfer ownership of an object's resources
{
    return static_cast<std::remove_reference_t<T> &&>(value);
}

int main(int argc, char **argv)
{
    int x = 5;
    assert(!wrapper(x));
    assert(!wrapper(42));
    assert(!forward_wrapper(x));
    assert(forward_wrapper(42)); // it is only one with rvalue overload
    return 0;
}
