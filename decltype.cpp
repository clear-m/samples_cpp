#include <vector>
#include <iostream>

// INFO: remember
//  typeid works in runtime,
//  decltype - in compile time )
template <typename T> // hint - Debug prints deduced type on construction error
struct Debug
{
    Debug(T) = delete;
};

struct S
{
    int x = 0;
};

template <typename Container>
auto &get_element(Container &cont, size_t index)
{
    return cont[index];
}

template <typename Container>
auto get_element_2(Container &cont, size_t index) -> decltype(cont[index])
{
    return cont[index];
}

template <typename Container>
decltype(auto) get_element_3(Container &cont, size_t index) // get_element_2 === get_element_3
{
    return cont[index];
}

template <typename Container>
decltype(auto) get_element_4(Container &cont, size_t index) // get_element_2 !== get_element_4
{
    return (cont[index]); // reference here
}

template <typename Container>
decltype(auto) get_element_5(Container &cont, size_t index) // get_element_2 !== get_element_5
{
    decltype(auto) element = cont[index];
    return (element); // UB - dangling reference to the element
}

int main(int argc, char **argv)
{
    int x = 0;
    int &y = x;
    decltype(x) yy = x;      // int yy
    const decltype(y) z = y; // const int& z
    decltype(x) &t = x;      // int& t
    decltype(y) &f = y;      // int& f - reference collapsing
    decltype(y) &&ff = y;    // int&& f - reference collapsing
    // decltype(x)&& xx = x; // CE - x not rvalue
    decltype(x) &&xx = std::move(x); // ok

    decltype(&x) const p = &x;

    decltype(++x) u = x;  // int& u - dectype work at compile time it is not calc
    decltype(x++) uu = x; // int u - dectype work at compile time it is not calc
    ++u;

    std::cout << x << u << std::endl;

    decltype(std::move(x)) &uuu = x;  // int& uuu - reference collapsing type
    const decltype(throw 1) *pp = &x; // const void* pp
    decltype((x)) yyy = x;            // POW! int & yyy - remember: decltype works from names and expressions

    decltype((S().x)) zz = std::move(x); // POW! int && zz
    decltype(S().x) zzz = x;
    // Debug<decltype((S().x))>(); // check it )
    // std::vector<decltype(yyy)> v;
    // Debug<decltype(yyy)>(); // CE - prints type in error
    // Debug<decltype(pp)>(); // ok

    std::vector<int> vv(5);
    get_element_5(vv, 0) = 1;

    return 0;
}
