#include <iostream>

template <int N>
struct Fibonacci
{
    static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0>
{
    static const int value = 0;
};

template <>
struct Fibonacci<1>
{
    static const int value = 1;
};

int main(int argc, char **argv)
{
    std::cout << Fibonacci<10>::value << std::endl;
    return 0;
}
