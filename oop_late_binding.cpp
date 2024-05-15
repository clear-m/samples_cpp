#include <iostream>

namespace A
{
    class Base
    {
    public:
        void show()
        {
            std::cout << "Base\n";
        }
    };

    class Derv1 : public Base
    {
    public:
        void show()
        {
            std::cout << "Derv1\n";
        }
    };

    class Derv2 : public Base
    {
    public:
        void show()
        {
            std::cout << "Derv2\n";
        }
    };
}

namespace B
{
    class Base
    {
    public:
        virtual void show() // Late Binding, также известный как Dynamic Binding или Runtime Binding
        {
            std::cout << "Base\n";
        }
    };

    class Derv1 : public Base
    {
    public:
        // not necessary to add `virtual` keyword, as the function of the base is
        // virtual
        void show()
        {
            std::cout << "Derv1\n";
        }
    };

    class Derv2 : public Base
    {
    public:
        void show()
        {
            std::cout << "Derv2\n";
        }
    };
}

int main(int argc, char **argv)
{
    //using namespace A;
    using namespace B;
    Derv1 derv1;
    Derv2 derv2;
    Base *ptr;
    ptr = &derv1;
    ptr->show();
    ptr = &derv2;
    ptr->show();

    return 0;
}
