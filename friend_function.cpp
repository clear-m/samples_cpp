#include <iostream>
using namespace std;

class Beta;

class Alpha
{
private:
    int data;

public:
    Alpha() : data(3){};
    friend int friendFunction(Alpha, Beta);
};

class Beta
{
private:
    int data;

public:
    Beta() : data(7){};
    friend int friendFunction(Alpha, Beta);
};

int friendFunction(Alpha alpha, Beta beta)
{
    return alpha.data + beta.data;
}

int main(int argc, char **argv)
{
    Alpha alpha;
    Beta beta;
    cout << friendFunction(alpha, beta) << "\n"; // outputs 10
    return 0;
}
