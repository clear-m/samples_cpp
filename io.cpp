#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    {
        std::ofstream file("text_output.txt");
        file << "Hello, world!" << std::endl;
        file.close();
    }
    {
        std::ofstream file("output.bin", std::ios::binary);
        if (file.is_open())
        {
            char data[] = "Hello, World!";
            file.write(data, sizeof(data));
            file.close();
        }
        else
        {
            std::cout << "Unable to open file";
        }
    }
    {
        std::ifstream file("input.txt");
        if (file.is_open()) {
            char c;
            while (file.get(c)) {
                std::cout << c;
            }
            file.close();
        } else {
            std::cout << "Unable to open file";
        }
    }
    {
        std::ifstream file3("binary_input.bin", std::ios::binary);
        if (file3.is_open())
        {
            char data[10];
            file3.read(data, 10);
            file3.close();
        }
        else
        {
            std::cout << "Unable to open file";
        }
    }

    return 0;
}
