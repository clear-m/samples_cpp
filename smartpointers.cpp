#include <iostream>
#include <memory>

class SmartPtr
{
    int *ptr; // Actual pointer
public:
    explicit SmartPtr(int *p = NULL) { ptr = p; }

    ~SmartPtr()
    {
        delete (ptr);
    }

    // Overloading dereferencing operator
    int &operator*()
    {
        return *ptr;
    }
};

class MyClass
{
public:
    MyClass() { std::cout << "MyClass created" << std::endl; }
    ~MyClass() { std::cout << "MyClass destroyed" << std::endl; }
};

int main(int argc, char **argv)
{
    {
        SmartPtr ptr(new int());
        *ptr = 20;
        std::cout << *ptr;
    }
    {
        std::unique_ptr<MyClass> ptr(new MyClass()); // owns, can't copy, can't move
    }
    {
        std::shared_ptr<MyClass> ptr1(new MyClass()); // owns, shared
        std::shared_ptr<MyClass> ptr2 = ptr1;
    }
    {
        std::shared_ptr<MyClass> ptr1(new MyClass());
        std::weak_ptr<MyClass> weakPtr = ptr1;
    }
    // TODO: std::atomic<std::shared_ptr> and std::observer_ptr
    return 0;
}
