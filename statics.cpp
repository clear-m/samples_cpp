#include <iostream>

class Gamma
{
private:
    static int total;
    int id;

public:
    Gamma()
    {
        ++total;
        id = total;
    }
    ~Gamma()
    {
        --total;
        std::cout << "Destroying id number " << id << "\n";
    }
    static void showTotal()
    { // have access to static members only
        std::cout << "Total is " << total << "\n";
    }
    void showid()
    {
        std::cout << "ID is " << id << "\n";
        std::cout << "Total is " << total << "\n";
    }
};

int Gamma::total = 0;

int main()
{
    Gamma g1, g2;
    Gamma::showTotal(); // without static won't work; i.e., static void showTotal() will work
                        // but void showTotal() won't
    Gamma g3;
    Gamma::showTotal();
    g1.showid();
    g2.showid();
    g3.showid();
    std::cout << "End of Program\n";
    return 0;
}
