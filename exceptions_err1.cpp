#include <exception>
#include <iostream>

//INFO: what's wrong with this code
struct general_exception : public std::exception
{
    virtual const char *what() const noexcept
    {
        auto msg = "general_exception";
        std::cout << msg << std::endl;
        return msg;
    }
};

struct specific_exception : public general_exception
{
    virtual const char *whar() const noexcept
    {
        auto msg = "specific_exception";
        std::cout << msg << std::endl;
        return msg;
    }
};

void foo()
{
    throw specific_exception();
}

int main(int argc, char **argv)
{
    try
    {
        foo();
    }
    catch (general_exception e) // slice
    {
        std::cout << "general_exception" << std::endl;
        e.what();
    }
    catch (specific_exception e) // warning: exception of type ‘specific_exception’ will be caught by earlier handler
    {
        std::cout << "specific_exception" << std::endl;
        e.what();
    }
    return 0;
}
