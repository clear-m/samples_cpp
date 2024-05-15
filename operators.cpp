#include <iostream>
#include <cstdlib>

class MyClass {
public:
    MyClass() { std::cout << "MyClass object created" << std::endl; }
    ~MyClass() { std::cout << "MyClass object destroyed" << std::endl; }

    void* operator new(size_t size) {
        std::cout << "Overloaded new operator called" << std::endl;
        void* ptr = std::malloc(size);
        return ptr;
    }

    void operator delete(void* ptr) {
        std::cout << "Overloaded delete operator called" << std::endl;
        std::free(ptr);
    }
};

class DynamicArray {
private:
    int* data;
    size_t size;
public:
    DynamicArray(size_t sz) : size(sz) {
        data = new int[size];
    }

    ~DynamicArray() {
        delete[] data;
    }

    int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

int main(int argc, char **argv)
{
    MyClass* obj = new MyClass();
    delete obj;
    return 0;
}
