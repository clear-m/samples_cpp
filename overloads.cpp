#include <iostream>

// Операторы new, delete, new[] и delete[] имеют особые правила перегрузки и рассматриваются отдельно.
// Для перегрузки функций должно отличаться одно из:
// Количество параметров
// Типы параметров
// Порядок типов параметров

// Перегрузка методов в работает аналогично.
// Можно определить несколько методов с одним и тем же именем в классе,
// если они отличаются по количеству, типам или порядку параметров.

// IN SUMMARY:
// Имя должно быть одинаковым.
// Параметры должны отличаться.
// Возвращаемый тип не учитывается при разрешении перегрузки.
// Перегрузка шаблонных функций
template <typename T>
T sum(T a, T b)
{
    return a + b;
}

template <typename T1, typename T2>
auto sum(T1 a, T2 b)
{
    return a + b;
}

int sum(int x, int y)
{
    std::cout << "Non-template func: " << x << ", " << y << std::endl;
    return x + y;
}

// Перегрузка шаблонных методов
class MyOtherClass
{
public:
    template <typename T>
    T square(T value)
    {
        return value * value;
    }
    int square(int value)
    {
        std::cout << "Non-template method: " << value << std::endl;
        return value * value;
    }
    template <typename T1, typename T2>
    auto multiply(T1 a, T2 b)
    {
        return a * b;
    }
    template <typename T>
    auto multiply(T a, int b)
    {
        std::cout << "Partially specialized method: " << a << ", " << b << std::endl;
        return a * b;
    }
};

// Частичная специализация шаблонных функций
template <typename T>
void print(T value)
{
    std::cout << value << std::endl;
}

void print(int x)
{
    std::cout << "Non-template func: " << x << std::endl;
}

template <>
void print<char>(char x)
{
    std::cout << "Specialized func: " << x << std::endl;
}

int main(int argc, char **argv)
{
    int result1 = sum(3, 6);        // вызывается первая версия, result1 = 9
    double result2 = sum(3.3, 6.6); // вызывается вторая версия, result2 = 9.9

    MyOtherClass obj;
    int square_int = obj.square(5);                                                         // square_int = 25
    double square_double = obj.square(3.14);                                                // square_double = 9.8596
    auto product = obj.multiply(2.0, 3);                                                    // product = 6.0
    auto product2 = obj.multiply(2, 3.5);                                                   // product = 7.0

    print(1);
    print(2.0);
    print(nullptr);
    print('a');

    return 0;
}