#include <iostream>

template <int... Ns>
struct Fibonacci;

template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

template <int N, int... Ns>
struct Fibonacci<N, Ns...> {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
    static constexpr int next = Fibonacci<N - 1, N, Ns...>::value;
};

int main(int argc, char **argv)
{
    std::cout << Fibonacci<10>::value << std::endl; // Output: 55
    return 0;
}

//TODO: think of generator later
// template <size_t... Is>
// struct sequence {};

// template <size_t N, size_t... Is>
// struct generate_sequence : generate_sequence<N - 1, N - 1, Is...> {};

// template <size_t N>
// struct generate_sequence<N> : sequence<> {};

// int main(int argc, char **argv)
// {
//     generate_sequence<10> seq;
//     return 0;
// }
