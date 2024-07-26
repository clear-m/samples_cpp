#include <type_traits>
#include <cassert>
#include <iostream>

template <class T, T v>
struct integral_constant
{
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
    constexpr operator value_type() const noexcept
    {
        return value;
    };
    constexpr value_type operator()() const noexcept
    {
        return value;
    };
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <typename T, typename U>
struct are_same : false_type
{
};

template <typename T>
struct are_same<T, T> : true_type
{
};

template <typename T>
struct is_pointer : false_type
{
};

template <typename T>
struct is_pointer<T *> : true_type
{
};

// SFINAE (Substitution Failure Is Not An Error)
template <typename T, typename = void>
struct has_hello : std::false_type
{
};

template <typename T>
struct has_hello<T, std::void_t<decltype(&T::hello)>> : std::true_type
{
};

// SFINAE (overloads)
template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
do_stuff(T& t) {
    std::cout << "do_stuff integral\n";
    return t;
}

template <typename T>
typename std::enable_if<std::is_class<T>::value, T>::type
do_stuff(T& t) {
    std::cout << "do_stuff class\n";
    return t;
}

struct A
{
    void hello() {}
};

struct B
{
};

int main(int argc, char **argv)
{
    static_assert(are_same<int, int>::value);
    static_assert(!is_pointer<int>::value);
    static_assert(is_pointer<int *>::value);

    static_assert(has_hello<A>::value);
    static_assert(!has_hello<B>::value);

    int i{42};
    do_stuff(i);
    B b{};
    do_stuff(b);

    return 0;
}
