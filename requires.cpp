
#include <cassert>
#include <type_traits>
#include <utility>

template <typename T>
    requires requires(T x) { x + x; }
T sum(T a, T b)
{
    return a + b;
}

template <typename T>
concept Addable = requires(T a, T b) {
    a + b;
};

template <Addable T>
T sum2(T a, T b)
{
    return a + b;
}

template <typename T>
T sum3(T a, T b)
    requires Addable<T>
{
    return a + b;
}

template <typename T, typename U>
    requires std::convertible_to<decltype(std::declval<T>().f(std::declval<U>())), int>
int call_f(T &obj, U arg)
{
    return obj.f(arg);
}

template <typename T>
    requires std::equality_comparable<T> && std::is_default_constructible_v<T>
T create_default()
{
    return T{};
}

int main(int argc, char **argv)
{
    {
        sum(1, 2);
        // sum("a", "b"); // CE: constraints not satisfied
    }
    {
        sum2(1, 2);
        // sum2("a", "b"); // CE: constraints not satisfied
    }
    {
        sum3(1, 2);
        // sum3("a", "b"); // CE: constraints not satisfied
    }
    {
        struct test_convertible
        {
            int f(int x)
            {
                return x * x;
            }
        };
        struct test_not_convertible
        {
            int *f(int *x)
            {
                *x = (*x) * (*x);
                return x;
            }
        };
        test_convertible t1;
        call_f(t1, 1);
        // test_not_convertible t2;
        // int x{1};
        // call_f(t2, &x); // CE: constraints not satisfied
    }
    {
        create_default<int>();
        struct S
        {
            S() = delete;
        };
        // create_default<S>(); // CE: constraints not satisfied
    }
    return 0;
}
