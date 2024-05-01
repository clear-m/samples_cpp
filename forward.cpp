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

int main(int argc, char **argv)
{
    int x = 5;
    assert(!wrapper(x));
    assert(!wrapper(42));
    assert(!forward_wrapper(x));
    assert(forward_wrapper(42)); // it is only one with rvalue overload
    return 0;
}
