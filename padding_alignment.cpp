#include <iostream>
#include <cassert>
#include <memory>

// Data Structure Padding - выравнивания членов структуры данных внутри структуры
struct ExampleStructA
{
    char a;   // 1 байт | 4 байта
    int b;    // 4 байта
    double c; // 8 байтов
    char d;   // 1 байт | 4 байта
};

struct ExampleStructB
{
    char a;   // 1 байт | 4 байта
    char d;   // 1 байт |
    int b;    // 4 байта
    double c; // 8 байтов
};

// Data Structure Alignment
// Выравнивание по 8 байтам
struct alignas(8) MyStructAB8
{
    int a;
    float b;
};

struct alignas(16) MyStruct {
    int a;
    int b;
};

struct alignas(64) MyStructAB64
{
    int a;
    float b;
};

// Выравнивание по 32 байтам
struct alignas(32) MyStruct32
{
    int a;
    float b;
    char c;
};

// Выравнивание по 64 байтам
struct alignas(64) MyStruct64
{
    int a;
    float b;
    char c;
    double d;
};

struct Type1 {
    int data;
};

struct Type2 {
    double data;
};

// packed tightly
#pragma pack(push, 1)
struct A 
{ 
    int i; 
    char c; 
}; 
 
struct B: A 
{ 
    char c1, c2; 
}; 
 
struct C: B 
{ 
    char c3; 
}; 
 
#pragma pack(pop)

struct AA 
{ 
    int i; 
    char c; 
}; 
 
struct BB: AA 
{ 
    char c1, c2; 
}; 
 
struct CC: BB 
{ 
    char c3; 
}; 

class AAA 
{ 
    int i; 
    char c; 
}; 
 
class BBB: AAA 
{ 
    char c1, c2; 
}; 
 
class CCC: BBB 
{ 
    char c3; 
}; 


int main(int argc, char **argv)
{
    {
        ExampleStructA a;
        std::cout << sizeof(a) << std::endl;
        ExampleStructB b;
        std::cout << sizeof(b) << std::endl;
    }
    {
        MyStructAB8 a8;
        MyStructAB8 a64;
        assert(sizeof(a8) == sizeof(a64));
    }
    {
        // объект с выравниванием в 16 байт на архитектуре с выравниванием в 8 байт не будет выравнен корректно
        std::cout << sizeof(MyStruct) << std::endl;

        std::aligned_storage<sizeof(MyStruct), alignof(MyStruct)>::type storage;
        MyStruct* ptr = new (&storage) MyStruct();

        // // Создание массива объектов с выравниванием в 16 байт
        std::aligned_storage<sizeof(MyStruct), alignof(MyStruct)>::type storages[5];
        MyStruct* ptrs = new (&storages[0]) MyStruct[5];
    }
    {
        std::aligned_union<0, Type1, Type2>::type myUnion;
        Type1* ptrType1 = new(&myUnion) Type1{42}; // Размещаем объект типа Type1 в объединении
        std::cout << ptrType1->data << std::endl; // Выводим данные
    }
    {
        C c;
        CC cc;
        CCC ccc;
        std::cout << "Size of stricly packed derived: " << sizeof(c) << ", but without packing " << sizeof(cc) << " and without compatible padding " << sizeof(ccc) << std::endl;


    }
    return 0;
}
