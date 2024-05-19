#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

void handle_exception(std::exception_ptr eptr)
{
    try
    {
        if (eptr)
        {
            std::rethrow_exception(eptr);
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: '" << e.what() << "'\n";
    }
}

int main(int argc, char **argv)
{
    std::exception_ptr eptr;
    try
    {
        std::string().at(1); // std::out_of_range
    }
    catch (...)
    {
        eptr = std::current_exception(); // захват исключения
    }
    handle_exception(eptr);
    return 0;
}
