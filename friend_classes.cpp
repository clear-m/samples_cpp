#include <iostream>

class Alpha {
private:
    int data;
public:
    Alpha(): data(3) { };
    friend class Beta;
};

class Beta { // can access all private of Alpha
public:
    void func1(Alpha alpha) {
        std::cout << alpha.data << "\n";
    }
};

int main(int argc, char **argv)
{
    Alpha alpha;
    Beta beta;
    beta.func1(alpha);
    return 0;
}
