#include <iostream>

// Two-step lookup
void print(int x, int y = 0)
{
    std::cout << "Integer, Integer: " << x << ", " << y << std::endl;
}

void print(double x)
{
    std::cout << "Double: " << x << std::endl;
}

template <typename T>
class Container
{
public:
    Container(const T &item)
    {
        // ...
    }
    void add(const T &item)
    {
        // ...
    }
};

// ADL (Argument-Dependent Lookup) - поиск зависящий от аргументов
namespace MyNamespace
{
    class MyClass
    {
    };

    void foo(MyClass)
    {
        // implementation
        std::cout << "foo" << std::endl;
    }
}

namespace
{
    std::ostream &operator<<(std::ostream &os, const MyNamespace::MyClass &obj)
    {
        // реализация вывода объекта в поток
        std::cout << "<<here>>" << std::endl;
        return os;
    }
}

namespace N
{
    struct X
    {
    };
    void f(X)
    {
        // ...
    }
}

namespace M
{
    struct Y
    {
        void g()
        {
            f(N::X{}); // ADL ищет f в N и M
        }
        void f(N::X ) // adl chooses this one if uncommented
        {
            return;
        }
    };
    void f(N::X ) // more than one instance of function "M::f" matches the argument list:C/C++(308) but adl chooses other one
    {
        return;
    }
}

// Niebloids
class Niebloid {}; // this is nebloid ) TODO: add some C++2х ranges examples


int main(int argc, char **argv)
{
    // Two-step lookup
    {
        // 1я фаза - точный поиск соответствия типов аргументов
        // 2я фаза - поиск функций которые могут быть вызваны с помощью стандартных преобразований
        print(3.14);
    }
    {
        // 1я фаза - поиск явных специализаций шаблона класса с указанным именем (42)
        // 2я фаза - попытка выведения из контекста использования - int
        Container c(42);
    }
    // ADL
    {
        MyNamespace::MyClass obj;
        foo(obj);         // ADL найдет foo в неймспейсе MyNamespace
        std::cout << obj; // ADL найдет оператор << в анонимном неймспейсе
    }
    {
        M::Y y;
        y.g();
    }
    return 0;
}
