#include <ranges>
#include <vector>
#include <algorithm>
#include <iostream>

// For Range-based for loop (since C++11)
struct RangesCompatible
{
    RangesCompatible()
    {
        int i{0};
        std::generate(&v[0], &v[10], [&i](){  return ++i;} );
    }
    int * begin()
    {
        return &v[0];
    }
    int * end()
    {
        return &v[10];
    }

    int v[10];
};

// TODO
// Немодифицирующие операции диапазонов
// Диапазоны предоставляют ряд немодифицирующих операций, которые позволяют работать с последовательностями элементов без изменения их содержимого. Вот некоторые примеры:
// std::ranges::all() - возвращает диапазон, содержащий все элементы исходного диапазона.
// std::ranges::any_of() - проверяет, удовлетворяет ли хотя бы один элемент диапазона заданному предикату.
// std::ranges::count_if() - подсчитывает количество элементов в диапазоне, удовлетворяющих заданному предикату.
// std::ranges::find() - находит первый элемент в диапазоне, равный заданному значению.

// Модифицирующие операции диапазонов
// Диапазоны также предоставляют модифицирующие операции, которые позволяют изменять содержимое последовательностей. Вот несколько примеров:
// std::ranges::sort() - сортирует элементы диапазона в порядке возрастания.
// std::ranges::unique() - удаляет из диапазона последовательные дубликаты элементов.
// std::ranges::transform() - применяет заданную функцию преобразования ко всем элементам диапазона.
// std::ranges::remove_if() - удаляет из диапазона все элементы, удовлетворяющие заданному предикату.

// Улучшения в C++23
// В готовящемся стандарте C++23 планируется ряд улучшений для диапазонов, включая:
// Поддержку параллельного выполнения алгоритмов диапазонов.
// Возможность использования проекций при сортировке, чтобы сортировать по выбранным элементам.
// Дополнительные алгоритмы, такие как std::ranges::contains() и std::ranges::equal().

int main(int argc, char **argv)
{
    // Range-based for loop (since C++11)
    RangesCompatible rc;
    for (auto item : rc)
    {
        std::cout << item << std::endl;
    }

    auto even = [](int i){ return (i % 2) == 0; };
    auto half = [](int i){ return i / 2; };

    std::vector<int> numbers_in{100, 55, 80, 2, -1};
    auto numbers_out = numbers_in | std::ranges::views::filter(even) | std::ranges::views::transform(half);
    for (auto i : numbers_out) {
        std::cout << i << std::endl;
    }

    return 0;
}
