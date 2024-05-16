#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>

int main(int argc, char **argv)
{
    {
        // Алгоритмы сортировки и поиска
        {
            std::vector<int> v{5, 2, 9, 1, 7};
            std::sort(v.begin(), v.end()); // O(N log(N)) - §25.4.1.1/3
            std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()}); // O(N)
            std::stable_sort(v.begin(), v.end()); // N log²(N) - 25.4.1.2/3
            bool found = std::binary_search(v.begin(), v.end(), 7);
        }
        {
            std::vector<int> v = {1, 3, 5, 7, 9};
            {
                // Найти позицию элемента, который не меньше 4 == 5 
                auto it = std::lower_bound(v.begin(), v.end(), 4);
                if (it != v.end())
                {
                    std::cout << "Элемент, который не меньше 4, находится на позиции: " << std::distance(v.begin(), it) << std::endl;
                }
                else
                {
                    std::cout << "Элемент, который не меньше 4, не найден" << std::endl;
                }
            }
            {
                // Найти позицию элемента, который больше 4 == 5
                auto it = std::upper_bound(v.begin(), v.end(), 4);
                if (it != v.end())
                {
                    std::cout << "Элемент, который больше 4, находится на позиции: " << std::distance(v.begin(), it) << std::endl;
                }
                else
                {
                    std::cout << "Элемент, который больше 4, не найден" << std::endl;
                }
            }
        }
    }
    {
        // Алгоритмы сравнения
        {
            std::vector<int> v1{1, 2, 3}, v2{1, 2, 3};
            bool are_equal = std::equal(v1.begin(), v1.end(), v2.begin());
        }
        {
            std::vector<std::string> vec1 = {"apple", "banana", "cherry"};
            std::vector<std::string> vec2 = {"apple", "banana", "dates"};

            bool result = std::lexicographical_compare(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
            if (result)
            {
                std::cout << "Первый диапазон лексикографически меньше второго." << std::endl;
            }
            else
            {
                std::cout << "Первый диапазон не лексикографически меньше второго." << std::endl;
            }
        }
        {
            std::vector<int> vec1 = {1, 2, 3};
            std::vector<int> vec2 = {1, 2, 4};

            bool result = std::lexicographical_compare(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());

            if (result)
            {
                std::cout << "Первый диапазон лексикографически меньше второго." << std::endl;
            }
            else
            {
                std::cout << "Первый диапазон не лексикографически меньше второго." << std::endl;
            }
        }
    }
    {
        // Алгоритмы преобразования
        {
            std::vector<int> v = {1, 2, 3};
            std::transform(v.begin(), v.end(), v.begin(), [](int x)
                           { return x * x; });
        }
        {
            std::vector<int> numbers = {1, 2, 3, 4, 2, 5};

            std::replace(numbers.begin(), numbers.end(), 2, 6);

            for (const auto &num : numbers)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        {
            std::vector<int> numbers = {1, 2, 3, 4, 5};

            std::replace_if(numbers.begin(), numbers.end(), [](int x)
                            { return x % 2 == 0; }, 0);

            for (const  auto&num : numbers)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
    {
        // Алгоритмы копирования
        std::vector<int> v1 = {1, 2, 3}, v2(3);
        std::copy(v1.begin(), v2.end(), v2.begin());
        // TODO: add std::move()
    }
    {
        // Алгоритмы генерации
        {
            std::vector<int> v(5);
            std::generate(v.begin(), v.end(), []()
                          { static int i = 0; return i++; });
            for (const auto &num : v)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        {
            std::vector<int> numbers(5);                  // Создаем вектор из 5 элементов
            std::iota(numbers.begin(), numbers.end(), 1); // Заполняем вектор значениями от 1

            // Выводим содержимое вектора
            for (const auto &num : numbers)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        {
            int arr[5];                                    // Создаем массив из 5 элементов
            std::iota(std::begin(arr), std::end(arr), 10); // Заполняем массив значениями от 10

            // Выводим содержимое массива
            for (const auto &num : arr)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
