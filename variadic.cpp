#include <vector>
#include <iostream>
#include <cassert>

template <typename... Args>
double sum(Args... args)
{
    return (args + ...);
}

template <typename T>
class Container
{
public:
    template <typename... Args>
    Container(Args... args)
    {
        values.reserve(sizeof...(args));
        ((values.emplace_back(args)), ...);
    }

private:
    std::vector<T> values;
};

template <typename... Args>
void print(Args... args)
{
    (std::cout << ... << args); // fold expression
    //((std::cout << args << std::endl), ...); // also, print with \n
}

int main(int argc, char **argv)
{
    assert(sum(1, 2, 3, 4, 5) == 15);
    print(1, 2, 3, 4, 5, 6);
    Container<int> c(1, 2, 3, 4, 5, 6, 7, 8, 9, 0);
    return 0;
}
