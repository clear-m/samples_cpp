#include <iostream>
#include <exception>

int call_with_exception()
{
    throw std::runtime_error("some error");
}

int call_with_throw()
{
    throw;
}

int main(int argc, char **argv)
{
    std::set_terminate([]()
                       {
        std::cout << "terminate handler" << std::endl;
        std::exception_ptr eptr = std::current_exception();
        if (eptr) {
            try {
                std::rethrow_exception(eptr);
            } catch (...) {
                std::cout << "terminate catch ..." << std::endl; // never called - since empty throw calls terminate; 
            }
        } });
    try
    {
        try
        {
            call_with_exception();
        }
        catch (std::exception &e)
        {
            std::cout << "normal catch: " << e.what() << std::endl;
            call_with_throw(); // rethrow
        }
    }
    catch (...)
    {
        std::cout << "catch ..." << std::endl; // rethrow catched
    }
    std::cout << "now empty trow without background exception" << std::endl; 
    try
    {
        call_with_throw();
    }
    catch (...)
    {
        std::cout << "catch with empty throw ..." << std::endl; // never called - since terminate
    }
    return 0;
}
