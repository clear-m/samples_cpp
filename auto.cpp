#include <utility>
#include <type_traits>

template <typename Container>
void f(Container &&container)
{
    for (auto &&value : std::forward<Container>(container))
    {
        //
    }
}

template <typename T>
auto get_value(T x)
{
    return ++x;
}

template <typename T>
auto g(T x) // CE
{
    if (x > 0)
    {
        return 0;
    }
    else
    {
        return 1u;
    }
}

template <typename T>
auto g2()
{
    if constexpr (std::is_same_v<T, int>)
    {
        return 0;
    }
    else
    {
        return 1u;
    }
}

template <typename T>
auto &get_value_ub(T x)
{
    return ++x;
}

template <typename T>
auto g3(T x) -> T // auto with ruturn type
{
    return ++x;
}

auto g4(auto x) // since C++20
{
    return x;
}

void g5(auto... x) // since C++20
{
}

template <auto N> // auto as a template numeric parameters
struct Example
{
};

template <typename T>
void h(T t)
{
}

int main(int argc, char **argv)
{
    auto x = get_value(1); // int x, since 1 is int
    // auto& xx = get_value(1); // CE - cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    auto &&xxx = get_value(1);       // lifetime expansion
    const auto &xxxx = get_value(1); // lifetime expansion
    // auto&& xxxxx = get_value_ub(1); // UB - reference to local variable ‘x’ returned
    {
        // since C++11
        auto x = 5;
        auto &y = x;
        const auto &z = y;
        auto &&t = x; // int & t - reference collapsing
        auto &&tt = std::move(x);
        int *p = new auto(5);
    }
    // auto r = g(5); // CE - inconsistent deduction for auto return type: ‘int’ and then ‘unsigned int’
    //
    auto a = g2<int>(); // OK - two separate functions generated
    auto b = g2<double>();
    //
    auto aa = g3(5); // OK - two separate functions generated
    auto bb = g3(5.0);

    Example<2> ei;
    Example<'a'> ec;

    auto lst = {1, 2, 3, 4, 5}; // initilizer list ok
    // h({1, 2, 3, 4, 5}); // cant pass as T - CE - no matching function for call to ‘h(<brace-enclosed initializer list>)’
    return 0;
}
