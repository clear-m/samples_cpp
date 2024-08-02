#include <iostream>
#include <cstdlib>
#include <new>

// INFO: yes - there are individual samples for each case

int main(int argc, char **argv)
{
    {
        // TODO: add more samples related:
        //       emplace_back(), emplace_front();
        //       std::make_unique(), std::make_shared();
        //       std::in_place_t, std::in_place_type_t, std::in_place_index_t (std::optional, std::variant, std::any)
        //  Inplace Constructor
        class MyClass
        {
        public:
            MyClass()
            {
                std::cout << "MyClass constructor called." << std::endl;
            }
            ~MyClass()
            {
                std::cout << "MyClass destructor called." << std::endl;
            }
        };
        void *memory = std::malloc(sizeof(MyClass));
        MyClass *obj = new (memory) MyClass(); // <-- inplance ctor
        obj->~MyClass();
        std::free(memory);
    }
    {
        // Inplace Destructor
        class BigObject
        {
        public:
            BigObject()
            {
                std::cout << "BigObject created" << std::endl;
            }
            ~BigObject()
            {
                std::cout << "BigObject destroyed" << std::endl;
            }
        };
        alignas(BigObject) char buffer[sizeof(BigObject)];
        BigObject *obj = new (buffer) BigObject;
        obj->~BigObject(); // <-- inplace dtor
    }
    {
        // Copy Constructor
        class MyClass
        {
        private:
            int *data;

        public:
            MyClass(int value)
            {
                data = new int(value);
            }
            // INFO: Both methods (copy ctor, operator=) can be automatically generated by the compiler if not defined by the user,
            //  but their behavior is different.
            //  copy ctor
            MyClass(const MyClass &other)
            {
                data = new int(*other.data);
            }
            // dtor
            ~MyClass()
            {
                delete data;
            }
            // assignment operator
            MyClass &operator=(const MyClass &other)
            {
                if (this == &other)
                {
                    return *this; // Проверка на самоприсваивание
                }
                delete data;                 // Освобождаем старую память
                data = new int(*other.data); // Копируем новое значение
                return *this;
            }
        };
        MyClass obj1(42);
        MyClass obj2(100);
        MyClass obj3 = obj1; // copy ctor
        obj3 = obj2;         // assignment op
    }
    {
        // Private dtor
        class Test
        {
        private:
            ~Test()
            { // Приватный деструктор
                std::cout << "Destructor called" << std::endl;
            }

        public:
            static Test *create()
            { // Статический метод для создания экземпляра
                return new Test();
            }
            static void destroy(Test *obj)
            {
                delete obj;
            }
        };
        Test *obj = Test::create();
        // delete obj; // <- CE: dtor is private within this context
        Test::destroy(obj);
    }
    {
        // Deleted dtor
        class NonDeletable
        {
        public:
            NonDeletable() {}
            // deleted dtor
            ~NonDeletable() = delete;
        };
        // stack allocation forbidden
        // NonDeletable obj; // CE: use of deleted function
        NonDeletable *obj = new NonDeletable(); // ok
        // delete obj; // // CE: use of deleted function

        // HINT:A remote destructor can be used when a class
        //  is part of an interface that should not be functional,
        //  or when objects of that class must be managed only
        //  through pointers or references to avoid accidental destruction.
    }
    return 0;
}