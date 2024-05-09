#include <iostream>

struct S
{
    int x = 0;
    S(int x) : x(x)
    {
        std::cout << "Created" << std::endl;
    }
    S(const S &s) : x(s.x)
    {
        std::cout << "Copy" << std::endl;
    }
    S(S &&s) : x(s.x)
    {
        std::cout << "Move" << std::endl;
    }
    ~S()
    {
        std::cout << "Destroyed" << std::endl;
    }
};

S f()
{
    S s(1);
    return s; // NRVO - нет создания временного объекта
}

S ff()
{
    return S(2); // RVO - нет создания временного объекта
}

int main(int argc, char **argv)
{
    S a = f();
    S b = ff();
    return 0;
}
