
#include <cassert>
#include <type_traits>
#include <utility>
#include <ranges>
#include <array>

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

template <typename T>
concept IntConvertiable = requires(T x) {
    {x} -> std::convertible_to<int>;
};

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
    {
        // modernize
        auto bubble_sort = [](auto &arr)
            requires std::ranges::range<decltype(arr)>
        {
            auto n = arr.size();
            for (int i = 0; i < n - 1; i++)
            {
                // last i elements are already in place
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        std::swap(arr[j], arr[j + 1]);
                    }
                }
            }
        };
        std::array arr{3, 1, 4, 2, 5};
        std::array sorted{1, 2, 3, 4, 5};
        bubble_sort(arr);
        assert(arr == sorted);
    }
    return 0;
}
