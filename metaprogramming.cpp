#include <type_traits>
#include <cassert>

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

// SFINAE
template <typename T, typename = void>
struct has_hello : std::false_type
{
};

template <typename T>
struct has_hello<T, std::void_t<decltype(&T::hello)>> : std::true_type
{
};

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
    return 0;
}
