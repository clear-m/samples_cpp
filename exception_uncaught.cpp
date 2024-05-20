
#include <exception>
#include <string>
#include <iostream>

// Apply change on destruction:
// Rollback in case of exception (failure)
// Else Commit (success)
class Transaction
{
public:
    Transaction(const std::string &s) : message(s) {}
    Transaction(const Transaction &) = delete;
    Transaction &operator=(const Transaction &) = delete;
    void Commit() { std::cout << message << ": Commit\n"; }
    void RollBack() noexcept(true) { std::cout << message << ": Rollback\n"; }
    // ...
    ~Transaction()
    {
        if (uncaughtExceptionCount == std::uncaught_exceptions())
        {
            Commit(); // May throw.
        }
        else
        { // current stack unwinding
            RollBack();
        }
    }

private:
    std::string message;
    int uncaughtExceptionCount = std::uncaught_exceptions();
};

class Foo
{
public:
    ~Foo()
    {
        try
        {
            Transaction transaction("In ~Foo"); // Commit,
                                                // even if there is an uncaught exception
            //...
        }
        catch (const std::exception &e)
        {
            std::cerr << "exception/~Foo:" << e.what() << std::endl;
        }
    }
};

int main()
{
    try
    {
        Transaction transaction("In main"); // RollBack
        Foo foo;                            // ~Foo commit its transaction.
        //...
        throw std::runtime_error("Error");
    }
    catch (const std::exception &e)
    {
        std::cerr << "exception/main:" << e.what() << std::endl;
    }
    return 0;
}
