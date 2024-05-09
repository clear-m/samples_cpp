#include <string>
#include <iostream>

// TODO: What can you do at compiletime?
//  C++11:
//  Declare variables (but not modify them)
//  Call other constexpr functions
//  Call constexpr constructors (and default ones)
//  Use carrays and std::array
//  Use static_asserts and stuff
//  typedef and using declarations

// C++14 additions:
// You can also use lambdas now
// You can modify variables inside a constexpr function
// you can have constexpr member functions that change member variables
// you can pass references (the non-const kind) to constexpr functions

// C++20 additions:
// You can allocate memory now
// You can call virtual functions now
// You can have try-catch blocks

// constant creation
constexpr double kPi = 3.14;
constexpr int kMonthInYear = 12;

// constepr functions
constexpr int sum(const int a, const int b)
{
    return a + b;
}

// constexpr ctors
class ConstClass
{
public:
    constexpr ConstClass(int x) : value(x){};

private:
    int value;
};

// constexpr if
constexpr bool isEven(int x) { return x % 2 == 0; }

template <typename T>
T add(T a, T b)
{
    if constexpr (std::is_arithmetic_v<T>)
    {
        return a + b;
    }
    else
    {
        return a.append(b);
    }
}

// constepr lambdas
auto ret = []() constexpr { return 0; };

int main(int argc, char **argv)
{
    constexpr int val = sum(1, 2); // вызов во время компиляции
    constexpr ConstClass c(1);

    if constexpr (isEven(2))
    {
        std::cout << "even" << std::endl;
    }
    else
    {
        std::cout << "odd" << std::endl;
    }

    auto a = add(1, 2);
    auto b = add(std::string("a"), std::string("b"));
    constexpr int v = ret();
    return 0;
}
