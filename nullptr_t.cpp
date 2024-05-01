#include <cstddef>
#include <type_traits>
#include <cassert>
#include <iostream>

bool foo(int *)
{
    std::cout << "pointer to integer overload\n";
    return false;
}

bool foo(double *)
{
    std::cout << "pointer to double overload\n";
    return false;
}

bool foo(std::nullptr_t)
{
    std::cout << "null pointer overload\n";
    return true;
}

int main(int argc, char **argv)
{
    std::nullptr_t this_is_nullptr = nullptr;
    assert((std::is_same<decltype(nullptr), std::nullptr_t>::value));
    assert(!(std::is_pointer<std::nullptr_t>::value)); // because it is not a built-in pointer type - it is decltype
    assert((std::is_null_pointer<std::nullptr_t>::value));
    assert(foo(nullptr));
    return 0;
}
