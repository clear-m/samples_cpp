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

S ff(S a) // copy
{
    return a; // copy elision - moved
}

S fff(S&&s)
{
    //return std::move(s);
    return s; // move - but copy possible in some old compilers
}


int main(int argc, char **argv)
{
    S a = S(S(S(S(S(1)))));
    S aa = std::move(S(S(S(S(S(1)))))); // temporary materialization: prvalue -> xvalue (move prvalue)
    S b = ff(a);
    S c = fff(S(2));
    // also (since C++17)
    std::string s1 = std::move(std::string("abc")); // xvalue - not copy elision
    std::string s2 = std::string("abc"); // prvalue - copy elision

    return 0;
}
