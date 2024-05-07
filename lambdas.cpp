#include <algorithm>
#include <functional>
#include <stdexcept>
#include <cassert>

template <typename R>
auto square()
{
    if (std::is_arithmetic_v<R>)
    {
        return [](R x) -> R
        {
            return x * x;
        };
    }
    throw std::runtime_error("not an arithmetic value");
}

int main(int argc, char **argv)
{
    // ф-ии высшего порядка
    auto add = [](int a, int b)
    { return a + b; };
    auto multiply = [](int a, int b)
    { return a * b; };
    auto high_order_function = [](auto func, int a, int b)
    {
        return func(a, b);
    };
    assert(high_order_function(add, 1, 1) == 2);
    assert(high_order_function(multiply, 2, 2) == 4);
    // предикаты
    std::vector<int> unsorted{3, 4, 5, 1, 2};
    const std::vector<int> sorted{1, 2, 3, 4, 5};
    std::sort(unsorted.begin(), unsorted.end(), [](auto a, auto b) { return a < b; });
    assert(unsorted == sorted);
    // функциональные объекты
    std::function<int(int)> integer_square{square<int>()};
    assert(integer_square(3) == 9);
    std::function<float(float)> real_square{square<float>()};
    assert(real_square(2.0) == 4.0);
    return 0;
}
