#include <type_traits>
#include <functional>
#include <cstdint>
#include <cmath>
#include <iostream>

template <typename T>
concept IsInteger = std::is_integral_v<T>;

template <IsInteger T>
T add(T a, T b)
{
    return a + b;
}

template <typename T>
concept IsFloatingPoint = std::is_floating_point_v<T>;

template <IsFloatingPoint T>
T naive_abs(const T x) // it is naive - use platform std::abs instead
{
    constexpr T zero{0.0};
    constexpr T minus_one{-1.0};
    if (x < zero)
    {
        return x * minus_one;
    }
    return x;
}

template <IsFloatingPoint T>
T naive_sqrt(T x)
{
    T y{1.0};
    constexpr T tolerance{0.001};
    while (naive_abs(x / y - y) > tolerance)
    {
        y = (y + x / y) / 2.0;
    }
    return y;
}

// + requires
template <typename T>
concept Printable = requires(T t) {
    { std::cout << t } -> std::same_as<std::ostream &>; // T must have an overloaded std::cout operator that returns an std::ostream&
};

template <Printable T>
void print(T t)
{
    std::cout << t << std::endl;
}

template <typename T>
concept EqualityComparable = requires(T a, T b) {
    { a == b } -> std::same_as<bool>;
};

template <typename T>
concept Copyable = requires(T a) {
    { a = a } -> std::same_as<T &>;
};

template <typename T>
concept Movable = requires(T a) {
    { std::move(a) } -> std::same_as<T &&>;
};

template <typename F, class... Args>
concept Invocable = requires(F &&f, Args &&...args) {
    std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
};

template <Invocable<int, double> F>
void call_with_ints(F &&f)
{
    f(42, 3.14);
}

// + std concepts
#include <concepts>
// Example 1: Using std::invocable
template <std::invocable<int> F>
void call_function(F func)
{
    func(5);
}

// Example 2: Using std::regular_invocable
template <std::regular_invocable<int, int> F>
void call_function(F func)
{
    func(5, 10);
}

// Example 3: Using std::predicate
template <std::predicate<int> P>
void check_predicate(P predicate)
{
    if (predicate(5))
    {
        std::cout << "5 is true." << std::endl;
    }
    else
    {
        std::cout << "5 is false." << std::endl;
    }
}

// Example 4: Using std::relation
template <std::relation<int, int> R>
void check_relation(R relation)
{
    if (relation(5, 10))
    {
        std::cout << "5 is less than 10." << std::endl;
    }
    else
    {
        std::cout << "5 is not less than 10." << std::endl;
    }
}

int main(int argc, char **argv)
{
    int a = add(3, 5);
    // INFO: below is CE - no matching function for call to ‘add(double, double)’,
    // expression ‘is_integral_v<T> [with T = double]’ evaluated to ‘false’
    // double bb = add(3.0, 5.0); // CE
    auto b = naive_abs(-9.0);
    auto c = naive_sqrt(9.0);
    print(123);

    auto lambda = [](int i, double d) { /* ... */ };
    call_with_ints(lambda);        // ОК
    call_with_ints(std::plus<>{}); // ОК, std::plus<> callable с int и double
    // call_with_ints([](int) { /* ... */ }); // CE: не callable с double

    call_function([](int a) {});
    call_function([](int a, int b) {});
    check_predicate([](int a)
                    { return true; });
    check_relation([](int a, int b)
                   { return a < b; });
    return 0;
}
