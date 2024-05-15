#include <iostream>

class Department
{
public:
    void show()
    {
        std::cout << "You are in CS dept\n";
    }
    virtual void info()
    {
        std::cout << "Department\n";
    }
    virtual void getData() = 0;
};

class Professor : public Department
{
public:
    void getData()
    {
        Department::show();
        std::cout << "You are in Professor section\n";
    }
    void info()
    {
        Department::info();
        std::cout << "Professor\n";
    }
};

class Student : public Department
{
public:
    void getData()
    {
        Department::show();
        std::cout << "You are in Students section\n";
    }
    void info()
    {
        Department::info();
        std::cout << "Student\n";
    }
};

int main()
{
    Department *dept1 = new Student();
    dept1->getData();
    dept1->info();
    Department *dept2 = new Professor();
    dept2->getData();
    dept2->info();
    return 0;
}
