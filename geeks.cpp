#include <iostream>
#include <cmath>
#include <cstring>
#include <limits>
#include <bitset>
#include <unordered_map>
#include <array>
#include <ranges>
#include <functional>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <list>
#include <stack>

int factorial(int n)
{
    int fact = 1;
    while (n > 1)
    {
        fact *= n;
        n--;
    }
    return fact;
}

bool is_leap_year(int year)
{
    // leap year
    if (year % 400 == 0)
    {
        return true;
    }
    // not leap year
    if (year % 100 == 0)
    {
        return false;
    }
    // leap year
    if (year % 4 == 0)
    {
        return true;
    }
    // not leap year
    return false;
}

bool is_prime(int n)
{
    // base condition
    if (n <= 1)
    {
        return false;
    }
    // check from 2 to n-1
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool check_palindrome(int n)
{
    int ans = 0;
    int temp = n;
    while (temp != 0)
    {
        ans = (ans * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (ans == n);
}

int fibo(int n)
{
    int first = 0;
    int second = 1;
    int ans{};
    if (n == 0)
    {
        return first;
    }
    for (int i = 2; i <= n; ++i)
    {
        ans = first + second;
        first = second;
        second = ans;
    }
    return ans;
}

int gcd(int a, int b)
{
    int result = std::min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
}

std::string remove_spaces(std::string str)
{
    std::string result{};
    for (char c : str)
    {
        if (c != ' ')
        {
            result += c;
        }
    }
    return result;
}

int find_sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    return sum;
}

// Lowest Common Multiple (LCM) of Two Numbers
int lcm(int a, int b)
{
    int result = (a / gcd(a, b)) * b;
    return result;
}

// Prints roots of quadratic equation ax*2 + bx + c
void find_roots(int a, int b, int c)
{
    // If a is 0, then equation is not quadratic
    if (a == 0)
    {
        std::cout << "Invalid\n";
        return;
    }
    // Formulae to calculate D
    int d = b * b - 4 * a * c;
    // Formulae to calculate square root of D
    double sqrt_val = std::sqrt(std::abs(d));
    // Conditons for checking root
    if (d > 0)
    {
        std::cout << "Roots are real and diferent \n";
        std::cout
            << (-b + sqrt_val) / (2 * a) << "\n"
            << (-b + sqrt_val) / (2 * a) << "\n";
    }
    else if (d == 0)
    {
        std::cout
            << "Roots are real and same \n"
            << -b / (2 * a) << "\n";
    }
    else
    {
        std::cout << "Roots are complex \n";
        std::cout
            << -b / (a * a) << " + i"
            << sqrt_val / (2 * a) << "\n"
            << -b / (2 * a) << " - i"
            << sqrt_val / (2 * a) << "\n";
    }
}

void find_min_max(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    std::cout << "min: " << min << "\n";
    std::cout << "max: " << max << "\n";
}

void print_2_smallest(int arr[], int n)
{
    int first;
    int second;
    if (n < 2)
    {
        std::cout << "Invalid input \n";
        return;
    }

    first = second = std::numeric_limits<int>::max();
    for (int i = 0; i < n; i++)
    {
        // If current element is smaller than first
        // Then update both first and second
        if (arr[i] < first)
        {
            second = first;
            first = arr[i];
        }
        // If arr[i] is in between first and second
        // Then update second
        else if (arr[i] < second && arr[i] != first)
        {
            second = arr[i];
        }
    }
    if (second == std::numeric_limits<int>::max())
    {
        std::cout << "There is no second smallest element\n";
    }
    else
    {
        std::cout << " Second smallest element is " << second << "\n";
    }
}

int sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool is_palindrome(std::string s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool are_anagram(char *str1, char *str2)
{
#define NO_OF_CHARS 256
    // Create 2 count arrays and initialize all values as 0
    int count1[NO_OF_CHARS] = {0};
    int count2[NO_OF_CHARS] = {0};
    int i{};
    // For each character in input strings, increment count
    // in the corresponding count array
    for (i = 0; str1[i] && str2[i]; i++)
    {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }
    if (str1[i] || str2[i])
    {
        return false;
    }
    // Compare count arrays
    for (i = 0; i < NO_OF_CHARS; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    return true;
}

void print_diamond(int n)
{
    int space = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < space; j++)
            std::cout << " ";

        // Print i+1 stars
        for (int j = 0; j <= i; j++)
            std::cout << "* ";

        std::cout << std::endl;
        space--;
    }

    space = 0;

    // run loop (parent loop)
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < space; j++)
            std::cout << " ";

        // Print i stars
        for (int j = 0; j < i; j++)
            std::cout << "* ";

        std::cout << std::endl;
        space++;
    }
}

void print_pyramid(int n)
{
    int k = 2 * n - 2;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < k; j++)
            std::cout << " ";

        k = k - 1;
        for (int j = 0; j <= i; j++)
        {
            // Printing stars
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

void print_pyramid_simple(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            std::cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void print_pyramid_inverted(int rows)
{
    for (int i = rows; i >= 1; i--)
    {
        for (int j = rows; j > i; j--)
        {
            std::cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void print_triangle(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void print_floyd_triangle(int rows, int n)
{
    // outer loop to print all rows
    for (int i = 0; i < rows; i++)
    {

        // innter loop to print abphabet in each row
        for (int j = 0; j <= i; j++)
        {
            std::cout << n++;
        }
        std::cout << "\n";
    }
}

void print_pascal_triangle(int n)
{
    int arr[n][n];

    for (int line = 0; line < n; line++)
    {
        // Every line has number of integers
        // equal to line number
        for (int i = 0; i <= line; i++)
        {
            // First and last values in every row are 1
            if (line == i || i == 0)
            {
                arr[line][i] = 1;
            }
            else
            {
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            }
            std::cout << arr[line][i] << " ";
        }
        std::cout << "\n";
    }
}

void print_hourglass(int rows)
{

    // first outer loop to iterate each row
    for (int i = 0; i < 2 * rows - 1; i++)
    {

        // assigning comparator
        int comp;
        if (i < rows)
        {
            comp = 2 * i + 1;
        }
        else
        {
            comp = 2 * (2 * rows - i) - 3;
        }

        // first inner loop to print leading spaces
        for (int j = 0; j < comp; j++)
        {
            std::cout << ' ';
        }

        // second inner loop to print star *
        for (int k = 0; k < 2 * rows - comp; k++)
        {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

void print_hourglass_rotated(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }

        int spaces = 2 * (n - i);
        for (int j = 0; j < spaces; j++)
        {
            std::cout << "  ";
        }

        for (int j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }

        std::cout << std::endl;
    }

    // Printing bottom part.
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }

        int spaces = 2 * (n - i);
        for (int j = 0; j < spaces; j++)
        {
            std::cout << "  ";
        }

        for (int j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }

        std::cout << std::endl;
    }
}

// Reverse string using recursion
void reverse_str(std::string &s, int n, int i)
{
    if (n <= i)
    {
        return;
    }
    std::swap(s[i], s[n]);
    reverse_str(s, n - 1, i + 1);
}

bool is_palindrome2_rec(char str[], int s, int n)
{
    // If there is only one character
    if (s == n)
    {
        return true;
    }
    // If first and last characters do not match
    if (str[s] != str[n])
    {
        return false;
    }
    if (s < n + 1)
    {
        return is_palindrome2_rec(str, s + 1, n - 1);
    }
    return true;
}

bool is_palindrome2(char str[])
{
    int n = std::strlen(str);
    if (n == 0)
    {
        return true;
    }
    return is_palindrome2_rec(str, 0, n - 1);
}

// Calculate the Length of the String Using Recursion
int strlen2(char *str)
{
    if (*str == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + strlen2(str + 1);
    }
}

// Factorial of given number using recursion
unsigned long long factorial3(unsigned long long n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial3(n - 1);
}

// Count the sume of numbers in a string
int sum_of_numbers(std::string str)
{
    int sum = 0;
    for (char ch : str)
    {
        if (std::isdigit(ch))
        {
            sum += ch - '0';
        }
    }
    return sum;
}

void swap(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

unsigned int max2()
{
    unsigned int max{};
    return ~max;
}

int max3(int a, int b)
{
    return ((a + b) + std::abs(a - b)) / 2;
}

int min3(int a, int b)
{
    return ((a + b) - std::abs(a - b)) / 2;
}

bool equals(int a, int b)
{
    return !(a ^ b);
}

int octal_to_decimal(int oct)
{
    int dec = 0;
    int place = 0;
    int temp = oct;
    while (temp)
    {
        int last_digit = temp % 10;
        temp /= 10;
        dec += last_digit * std::pow(8, place);
        ++place;
    }
    return dec;
}

int decimal_to_octal(int decimal)
{
    int octal = 0;
    int place = 1;
    int temp = decimal;
    while (temp)
    {
        int last_digit = temp % 8;
        temp /= 8;
        octal += last_digit * place;
        place *= 10;
    }
    return octal;
}

int hex_to_decimal(char hex_digit)
{
    if (hex_digit >= '0' && hex_digit <= '9')
    {
        return static_cast<int>(hex_digit - '0');
    }
    else if (hex_digit >= 'A' && hex_digit <= 'F')
    {
        return static_cast<int>(hex_digit - 'A' + 10);
    }
    else if (hex_digit >= 'a' && hex_digit <= 'f')
    {
        return static_cast<int>(hex_digit - 'a' + 10);
    }
    return -1;
}

std::string decimal_to_hex(int decimal)
{
    std::string hexa_decimal{};
    char hexa_decimals[16]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (decimal > 0)
    {
        int remainder = decimal % 16;
        hexa_decimal = hexa_decimals[remainder] + hexa_decimal;
        decimal /= 16;
    }
    return hexa_decimal;
}

std::string octal_to_bin(std::string octnum)
{
    int i = 0;
    std::string binary{""};
    while (octnum[i])
    {
        switch (octnum[i])
        {
        case '0':
        {
            binary += "000";
            break;
        }
        case '1':
        {
            binary += "001";
            break;
        }
        case '2':
        {
            binary += "010";
            break;
        }
        case '3':
        {
            binary += "011";
            break;
        }
        case '4':
        {
            binary += "100";
            break;
        }
        case '5':
        {
            binary += "101";
            break;
        }
        case '6':
        {
            binary += "110";
            break;
        }
        case '7':
        {
            binary += "111";
            break;
        }
        default:
        {
            std::cout << "invalid octal digit " << octnum[i];
            break;
        }
        }
        i++;
    }
    return binary;
}

std::string binary_to_octal(std::string bin)
{
    int l = bin.size();
    int t = bin.find_first_of('.');

    // length of string before '.'
    int len_left = t != -1 ? t : l;

    // add min 0's in the beginning to make
    // left substring length divisible by 3
    for (int i = 1; i <= (3 - len_left % 3) % 3; i++)
        bin = '0' + bin;

    // if decimal point exists
    if (t != -1)
    {
        // length of string after '.'
        int len_right = l - len_left - 1;

        // add min 0's in the end to make right
        // substring length divisible by 3
        for (int i = 1; i <= (3 - len_right % 3) % 3; i++)
            bin = bin + '0';
    }

    // create map between binary and its
    // equivalent octal code
    std::unordered_map<std::string, char> bin_oct_map{
        {"000", '0'},
        {"001", '1'},
        {"010", '2'},
        {"011", '3'},
        {"100", '4'},
        {"101", '5'},
        {"110", '6'},
        {"111", '7'}};
    int i = 0;
    std::string octal{""};

    while (true)
    {
        // one by one extract from left, substring
        // of size 3 and add its octal code
        octal += bin_oct_map[bin.substr(i, 3)];
        i += 3;
        if (i == bin.size())
            break;

        // if '.' is encountered add it to result
        if (bin.at(i) == '.')
        {
            octal += '.';
            i++;
        }
    }

    // required octal number
    return octal;
}

class Encapsulation
{
private:
    int x;

public:
    void setter(int a) { x = a; }
    int getter() { return x; }
};

class SimpleCompileTimePolymorphism
{
public:
    void func(int x)
    {
        std::cout << "value of x is " << x << std::endl;
    }
    void func(double x)
    {
        std::cout << "value of x is " << x << std::endl;
    }
    void func(int x, int y)
    {
        std::cout << "value of x and y is " << x << ", " << y << std::endl;
    }
};

class base
{
public:
    virtual void print()
    {
        std::cout << "print base class" << std::endl;
    }
    void show()
    {
        std::cout << "show base class" << std::endl;
    }
};

class derived : public base
{
public:
    void print()
    {
        std::cout << "print derived class" << std::endl;
    }
    void show()
    {
        std::cout << "show derived class" << std::endl;
    }
};

class Person
{
    int id;
    char name[100];

public:
    void set_p(int id, char *name)
    {
        std::strcpy(this->name, name);
        this->id = id;
    }
    void display_p()
    {
        std::cout << "id: " << id << "\t, name: " << name << "\n";
    }
};

class Student : private Person
{
    char course[50];
    int fee;

public:
    void set_s(int id, char *name, char *course, int fee)
    {
        set_p(id, name);
        std::strcpy(this->course, course);
        this->fee = fee;
    }
    void display_s()
    {
        display_p();
        std::cout << "course: " << course << "\t, fee: " << fee << std::endl;
    }
};

int main(int argc, char **argv)
{
    {
        int num = 5;
        std::cout << "factorial " << num << " " << factorial(num) << "\n";
    }
    {
        int year = 2000;
        std::cout << "is leap year? " << year;
        if (is_leap_year(year))
        {
            std::cout << " - leap year\n";
        }
        else
        {
            std::cout << " - not a leap year\n";
        }
    }
    {
        std::cout << "is prime ";
        is_prime(21) ? std::cout << " true\n" : std::cout << " false\n";
        is_prime(17) ? std::cout << " true\n" : std::cout << " false\n";
    }
    {
        int n = 12321;
        std::cout << "is palindrome? " << n;
        if (check_palindrome(n))
        {
            std::cout << " Yes\n";
        }
        else
        {
            std::cout << " No\n";
        }
    }
    {
        int n = 13;
        std::cout << "fibo " << n << " " << fibo(n) << "\n";
    }
    {
        int a = 54;
        int b = 33;
        std::cout << "GCD: a " << a << ", b " << b << " " << gcd(a, b) << "\n";
    }
    {
        std::string str{"Gfg to the moon"};
        std::cout << "Without spaces: " << remove_spaces(str) << "\n";
    }
    {
        int a = 24;
        int b = 13;
        std::cout << "LCM: " << lcm(a, b) << "\n";
    }
    {
        int a = 1;
        int b = 4;
        int c = 4;
        find_roots(a, b, c);
    }
    {
        int arr[] = {1, 2, 3, 4, 5};
        int n = sizeof(arr) / sizeof(arr[0]);
        find_min_max(arr, n);
    }
    {
        int arr[] = {21, 3, 15, 41, 34, 10};
        int n = sizeof(arr) / sizeof(arr[0]);
        print_2_smallest(arr, n);
    }
    {
        int arr[] = {1, 23, 54, 12, 9};
        int n = sizeof(arr) / sizeof(arr[0]);
        std::cout << "sum: " << sum(arr, n) << "\n";
    }
    {
        std::string s{"GeekeeG"};
        std::cout << is_palindrome(s) << "\n";
    }
    {
        char str1[] = "Geek";
        char str2[] = "for";
        if (are_anagram(str1, str2))
        {
            std::cout << "The two strings are anagram of each other\n";
        }
        else
        {
            std::cout << "The two strings are not anagram of each other\n";
        }
    }
    {
        print_diamond(5);
    }
    {
        print_pyramid(5);
    }
    {
        print_hourglass(5);
    }
    {
        print_hourglass_rotated(5);
    }
    {
        print_pyramid_simple(5);
    }
    {
        print_pyramid_inverted(5);
    }
    {
        print_triangle(5);
    }
    {
        print_floyd_triangle(5, 1);
    }
    {
        print_pascal_triangle(6);
    }
    {
        std::string str{"GeeksforGeeks"};
        reverse_str(str, str.length() - 1, 0);
        std::cout << str << std::endl;
    }
    {
        char str[] = "GeeKeeG";
        std::cout << is_palindrome2(str) << "\n";
    }
    {
        char str[] = "GeeksforGeeks";
        std::cout << strlen2(str);
    }
    {
        int num = 15;
        std::cout << "Factorial of " << num << " is " << factorial3(num) << "\n";
    }
    {
        std::string str{"1234"};
        std::cout << "sum of numbers: " << sum_of_numbers(str) << "\n";
    }
    {
        int x = 3;
        int y = 4;
        std::cout << "X : " << x << std::endl;
        std::cout << "Y : " << y << std::endl;
        swap(x, y);
        std::cout << std::endl;
        std::cout << "after: " << std::endl;
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std::endl;
    }
    {
        std::cout << "max value possible: " << max2() << std::endl;
    }
    {
        int a = 10;
        int b = 10;
        std::cout << "a = " << a << ", b = " << b << ", equals? " << equals(a, b) << std::endl;
    }
    {
        int a = 10;
        int b = 5;
        std::cout << "max: " << max3(a, b) << ", min: " << min3(a, b) << std::endl;
    }
    {
        int oct = 67;
        octal_to_decimal(oct);
        std::cout << "decimal equivalent is: " << octal_to_decimal(oct) << std::endl;
    }
    {
        std::string hex{"67"};
        int decimal = 0;
        int place = 0;
        int n = hex.length();
        for (int i = n - 1; i >= 0; i--)
        {
            int digit = hex_to_decimal(hex[i]);
            decimal += digit * std::pow(16, place);
            place++;
        }
        std::cout << "decimal equivalent: " << decimal << std::endl;
    }
    {
        int decimal = 7;
        std::bitset<32> binary(decimal);
        std::cout << "binary equivalent: " << binary << std::endl;
    }
    {
        std::cout << "octal equivalent: " << decimal_to_octal(55) << "\n";
    }
    {
        std::cout << "hexadecimal equivalent: " << decimal_to_hex(103) << "\n";
    }
    {
        std::string bin{"1111001010010100001.010110110011011"};
        std::cout << "octal number = " << binary_to_octal(bin) << "\n";
    }
    {
        std::string octnum{"345"};
        std::cout << "equivalent binary value = " << octal_to_bin(octnum) << "\n";
    }
    {
        Encapsulation obj;
        obj.setter(13);
        std::cout << obj.getter() << "\n";
    }
    {
        SimpleCompileTimePolymorphism obj;
        obj.func(10);
        obj.func(5.321);
        obj.func(94, 32);
    }
    {
        class Complex
        {
        private:
            int real;
            int imag;

        public:
            Complex(int r = 0, int i = 0)
            {
                real = r;
                imag = i;
            }
            Complex operator+(Complex const &obj)
            {
                Complex res;
                res.real = real + obj.real;
                res.imag = imag + obj.imag;
                return res;
            }
            void print()
            {
                std::cout << real << " + " << imag << "i\n";
            }
        };

        Complex c1(15, 5);
        Complex c2(3, 5);
        Complex c3 = c1 + c2;
        c3.print();
    }
    {
        base *bptr;
        derived d;
        bptr = static_cast<base *>(&d);
        bptr->print();
        // non virtual function binded at compile time
        bptr->show();
    }
    {
        Student s;
        char name[] = "XYZ";
        char course[] = "ABC";
        s.set_s(132451, name, course, 100000);
        s.display_s();
    }
    {
        struct c
        {
            double real;
            double img;
        };
        class Complex
        {
        private:
            struct c num;

        public:
            Complex() : num{}
            {
            }
            Complex(double real, double img)
            {
                num.img = img;
                num.real = real;
            }
            Complex(const Complex &var)
            {
                num.img = var.num.img;
                num.real = var.num.real;
            }
            // utility functions
            void print()
            {
                std::cout << "real: " << num.real << " + i" << num.img << std::endl;
            }
            double imag() { return num.img; }
            double real() { return num.real; }
            // overloaded operators
            Complex operator+(Complex &other)
            {
                Complex var;
                var.num.real = num.real + other.num.real;
                var.num.img = num.img + other.num.img;
                return var;
            }
            Complex operator-(Complex &other)
            {
                Complex var;
                var.num.real = num.real - other.num.real;
                var.num.img = num.img - other.num.img;
                return var;
            }
            Complex operator*(Complex &other)
            {
                Complex var;
                var.num.real = num.real * other.num.real - num.img * other.num.img;
                var.num.img = num.real * other.num.img + num.img * other.num.real;
                return var;
            }
        };
        Complex a(11, 12);
        Complex b(5, 8);
        Complex res = a + b;
        a.print();
        b.print();
        res.print();
    }
    {
        // inch-feet length system datatype
        struct c
        {
            double feet;
            double inch;
        };
        // inch-feet class
        class inch_feet
        {
        private:
            struct c length;

        public:
            inch_feet() {}
            inch_feet(double feet, double inch)
            {
                length.inch = inch;
                length.feet = feet;
            }
            inch_feet(inch_feet &var)
            {
                length.inch = var.length.inch;
                length.feet = var.length.feet;
            }
            inch_feet(const inch_feet &&var)
            {
                length.inch = var.length.inch;
                length.feet = var.length.feet;
            }
            // utility functions
            void print()
            {
                std::cout << length.feet << " feet and " << length.inch << " inches" << std::endl;
            }
            double inches() { return length.inch; }
            double feet() { return length.feet; }
            // overloaded operators
            inch_feet operator+(inch_feet &obj)
            {
                inch_feet var;
                var.length.feet = length.feet + obj.length.feet;
                var.length.inch = length.inch + obj.length.inch;
                if (var.length.inch >= 12.0)
                {
                    var.length.feet++;
                    var.length.inch - 12.0;
                }
                return var;
            }
            inch_feet operator-(inch_feet &obj)
            {
                inch_feet var;
                struct c temp = length;
                if (temp.feet > obj.length.feet)
                {
                    if (temp.inch < obj.length.inch)
                    {
                        temp.feet--;
                        temp.inch += 12;
                    }
                    var.length.feet = temp.feet - obj.length.feet;
                    var.length.inch = temp.inch - obj.length.inch;
                }
                else
                {
                    std::cout << "Negative Length is not Possible\n";
                }
                return var;
            }
        };
        inch_feet a(11, 4);
        inch_feet b(5, 8);
        inch_feet c = a - b;
        a.print();
        b.print();
        c.print();
    }
    {
        // function to sort
        auto bubble_sort = [](auto &&arr)
            requires std::ranges::range<decltype(arr)>
        {
            auto n = arr.size();
            for (int i = 0; i < n - 1; i++)
            {
                // last i elements are already in place
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        std::swap(arr[j], arr[j + 1]);
                    }
                }
            }
        };
        // print an array
        auto print_array = [](auto &&arr)
            requires std::ranges::range<decltype(arr)>
        {
            for (auto e : arr)
            {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        };
        std::array arr{3, 1, 4, 2, 5};
        bubble_sort(arr);
        std::cout << "Sorted array: ";
        print_array(arr);
    }
    {
        auto insertion_sort = [](auto &&arr)
            requires std::ranges::range<decltype(arr)>
        {
            int i, key, j;
            auto n = arr.size();
            for (i = 1; i < n; i++)
            {
                key = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
        };
        auto print_array = [](auto &&arr)
            requires std::ranges::range<decltype(arr)>
        {
            std::cout << "Sorted array: ";
            for (auto e : arr)
            {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        };
        std::array arr{1, 4, 3, 2, 5};
        insertion_sort(arr);
        print_array(arr);
    }
    {
        auto selection_sort = [](auto &&arr)
            requires std::ranges::range<decltype(arr)>
        {
            int min_index;
            auto n = arr.size();
            for (int i = 0; i < n - 1; i++)
            {
                min_index = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] < arr[min_index])
                    {
                        min_index = j;
                    }
                }
                if (min_index != i)
                {
                    std::swap(arr[min_index], arr[i]);
                }
            }
        };
        auto print_array = [](auto &&arr)
            requires std::ranges::range<decltype(arr)>
        {
            std::cout << "Sorted array: ";
            for (auto e : arr)
            {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        };
        std::array arr{5, 4, 3, 2, 1};
        selection_sort(arr);
        print_array(arr);
    }
    {
        auto merge = [](auto &&array, int left, int mid, int right)
            requires std::ranges::range<decltype(array)>
        {
            auto const subArrayOne = mid - left + 1;
            auto const subArrayTwo = right - mid;
            // Create temp arrays
            auto *leftArray = new int[subArrayOne],
                 *rightArray = new int[subArrayTwo];
            // Copy data to temp arrays leftArray[] and rightArray[]
            for (auto i = 0; i < subArrayOne; i++)
                leftArray[i] = array[left + i];
            for (auto j = 0; j < subArrayTwo; j++)
                rightArray[j] = array[mid + 1 + j];
            auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
            int indexOfMergedArray = left;
            // Merge the temp arrays back into array[left..right]
            while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
            {
                if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
                {
                    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                    indexOfSubArrayOne++;
                }
                else
                {
                    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                    indexOfSubArrayTwo++;
                }
                indexOfMergedArray++;
            }
            // Copying remaing elements
            while (indexOfSubArrayOne < subArrayOne)
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
                indexOfMergedArray++;
            }
            while (indexOfSubArrayTwo < subArrayTwo)
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
                indexOfMergedArray++;
            }
            delete[] leftArray;
            delete[] rightArray;
        };
        // TODO: deduce this here
        auto merge_sort = [&](auto &op, auto &&array, int begin, int end)
        {
            // base condition
            if (begin >= end)
            {
                return;
            }
            auto mid = begin + (end - begin) / 2;
            op(op, array, begin, mid);
            op(op, array, mid + 1, end);
            merge(array, begin, mid, end);
        };
        auto print_array = [](auto &&arr)
            requires std::ranges::range<decltype(arr)>
        {
            std::cout << "Sorted array: ";
            for (auto e : arr)
            {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        };
        std::array arr{5, 6, 3, 10, 1, 4, 9};
        std::cout << "Array: ";
        print_array(arr);
        merge_sort(merge_sort, arr, 0, arr.size() - 1);
        print_array(arr);
    }
    {
        auto partition = [](auto &&arr, int low, int high)
            requires std::ranges::range<decltype(arr)>
        {
            int pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j <= high - 1; j++)
            {
                // if current element is smaller than the pivot
                if (arr[j] < pivot)
                {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
            std::swap(arr[i + 1], arr[high]);
            return i + 1;
        };
        // quick sort function
        auto quick_sort = [&](auto &op, auto &&arr, int low, int high) -> void
        {
            if (low < high)
            {
                // pi is partitioning index, arr[p] is now at right place
                int pi = partition(arr, low, high);
                // separately sort elements before partition and after partition
                op(op, arr, low, pi - 1);
                op(op, arr, pi + 1, high);
            }
        };
        auto print_array = [](auto &&arr)
            requires std::ranges::range<decltype(arr)>
        {
            for (auto e : arr)
            {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        };
        std::array arr{2, 5, 6, 9, 1, 3, 4};
        std::cout << "Array: ";
        print_array(arr);
        quick_sort(quick_sort, arr, 0, arr.size() - 1);
        std::cout << "Sorted array: ";
        print_array(arr);
    }
    {
        auto search = [](auto &&arr, int n, int x)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == x)
                {
                    return i;
                }
            }
            return -1;
        };
        std::array arr{5, 4, 1, 6, 10, 9, 23, 2};
        int x = 9;
        int result = search(arr, arr.size(), x);
        if (result == -1)
        {
            std::cout << "Elements is not present in array";
        }
        else
        {
            std::cout << "Elements is present at index " << result << std::endl;
        }
    }
    {
        auto binary_search = [](auto &op, auto &&arr, int l, int r, int x)
        {
            if (r >= l)
            {
                // middle element
                int mid = l + (r - l) / 2;
                if (arr[mid] == x)
                {
                    return mid;
                }
                if (arr[mid] > x)
                {
                    op(op, arr, l, mid - 1, x);
                }
                return op(op, arr, mid + 1, r, x);
            }
            // we reach here when element is not present
            return -1;
        };
        std::array arr{1, 2, 3, 4, 5, 6};
        int x = 5;
        int result = binary_search(binary_search, arr, 0, arr.size() - 1, x);
        if (result == -1)
        {
            std::cout << "Element is not present in array" << std::endl;
        }
        else
        {
            std::cout << "Element is present at index " << result << std::endl;
        }
    }
    {
        auto print_index = [](std::vector<int> &v, int element)
        {
            auto it = find(v.begin(), v.end(), element);
            // condition if element found
            if (it != v.end())
            {
                // calc the index of element
                int index = it - v.begin();
                std::cout << index << std::endl;
            }
            else
            {
                // no such element in vector
                std::cout << "-1" << std::endl;
            }
        };
        std::vector<int> v{1, 2, 3, 4, 5, 6};
        int element = 5;
        print_index(v, element);
    }
    {
        auto remove_duplicates = [](auto &&arr)
        {
            std::set<int> s;
            // insert the array elements into the set
            for (int i = 0; i < arr.size(); i++)
            {
                s.insert(arr[i]);
            }
            // print the array with the duplicates removed
            std::cout << "after removing duplicates: \n";
            for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        };
        std::array arr{1, 2, 2, 4, 3, 3, 2, 1};
        // print array
        std::cout << "before removing duplicates:\n";
        for (int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i] << " ";
        }
        remove_duplicates(arr);
    }
    {
        std::array arr{1, 2, 3, 4, 5, 6};
        // print the array
        std::cout << "array: ";
        for (int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        // sort the array indescending order
        std::sort(arr.begin(), arr.end(), std::greater<int>());
        // print the array
        std::cout << "descending sorted array: ";
        for (int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    {
        auto print_frequency = [](std::string str)
        {
            std::map<std::string, int> m;
            std::string word{};
            for (int i = 0; i < str.size(); i++)
            {
                // if element is empty
                if (str[i] == ' ')
                {
                    // if the current
                    // is not found then insert
                    // current word with frequency
                    if (m.find(word) == m.end())
                    {
                        m.insert(std::make_pair(word, 1));
                        word = "";
                    }
                    else
                    {
                        m[word]++;
                        word = "";
                    }
                }
                else
                {
                    word += str[i];
                }
            }
            // storing the last word of the string
            if (m.find(word) == m.end())
            {
                m.insert(std::make_pair(word, 1));
            }
            // update the frequency
            else
            {
                m[word]++;
            }
            // traverse the map
            for (auto &it : m)
            {
                std::cout << it.first << " - " << it.second << std::endl;
            }
        };
        std::string str{"Geeks For Geeks is for Geeks"};
        print_frequency(str);
    }
    {
        auto print_max = [](auto &&arr, int k)
        {
            int result[arr.size()];
            int c[arr.size()];
            // Coping the array a
            // into c and initialising
            for (int i = 0; i < arr.size(); i++)
            {
                c[i] = arr[i];
                result[i] = 0;
            }

            for (int i = 0; i < k; i++)
            {

                int maxi = std::numeric_limits<int>::min();
                int index;
                for (int j = 0; j < arr.size(); j++)
                {
                    if (arr[j] > maxi)
                    {
                        maxi = arr[j];
                        index = j;
                    }
                }
                // Assigning 1 in order
                // to mark the position
                // of all k maximum numbers
                result[index] = 1;
                arr[index] = std::numeric_limits<int>::min();
            }
            // print elements
            for (int i = 0; i < arr.size(); i++)
            {
                if (result[i] == 1)
                {
                    std::cout << c[i] << " ";
                }
            }
            std::cout << std::endl;
        };
        std::array arr{50, 8, 45, 12, 25, 40, 84};
        int k = 3;
        print_max(arr, k);
    }
    {
        auto solve = [](auto &op, std::vector<int> &arr, int n, std::set<std::vector<int>> &ans, std::vector<int> v, int i)
        {
            // base condition
            if (i >= n)
            {
                ans.insert(v);
                return;
            }
            op(op, arr, n, ans, v, i + 1);
            v.push_back(arr[i]);
            op(op, arr, n, ans, v, i + 1);
        };
        auto all_subsets = [&](std::vector<int> arr, int n)
        {
            // set of vectors to store required unique subsets
            std::set<std::vector<int>> ans;
            std::sort(arr.begin(), arr.end());
            std::vector<int> v;
            solve(solve, arr, n, ans, v, 0);
            // vector of vectors to store final result
            std::vector<std::vector<int>> res;
            while (!ans.empty())
            {
                res.push_back(*ans.begin());
                ans.erase(ans.begin());
            }
            return res;
        };
        // print function
        auto print = [&](int n, std::vector<int> &a)
        {
            std::vector<std::vector<int>> result = all_subsets(a, n);
            // printing the output
            for (int i = 0; i < result.size(); i++)
            {
                std::cout << '(';
                for (int j = 0; j < result[i].size(); j++)
                {
                    std::cout << result[i][j];
                    if (j < result[i].size() - 1)
                        std::cout << " ";
                }
                std::cout << "), ";
            }
            std::cout << "\n";
        };
        int n = 3;
        std::vector<int> a{1, 2, 3};
        print(n, a);
    }
    {
        std::queue<int> q;
        // inserting elements in queue
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        // copy queue
        std::queue<int> copy_queue = q;
        std::cout << "queue elements: \n";
        while (!copy_queue.empty())
        {
            std::cout << copy_queue.front() << " ";
            copy_queue.pop();
        }
        std::cout << std::endl;
    }
    {
        const int max_elements = 100;
        class Stack
        {
        private:
            int top;
            int arr[max_elements];

        public:
            Stack() { top = -1; };
            // function to push an element to the stack
            void push(int x)
            {
                if (top == max_elements - 1)
                {
                    std::cout << "stack overflow" << std::endl;
                    return;
                }
                arr[++top] = x;
            }
            // function to pop en element from the stack
            int pop()
            {
                if (top == -1)
                {
                    std::cout << "stack underflow" << std::endl;
                    return -1;
                }
                return arr[top--];
            }
            // function to check if stack is empty
            bool is_empty()
            {
                return (top == -1);
            }
            // functionto return the top element of the stack
            int peek()
            {
                if (top == -1)
                {
                    std::cout << "stack is empty" << std::endl;
                    return -1;
                }
                return arr[top];
            }
        };

        Stack s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);

        std::cout << "popped element: " << s.pop() << std::endl;
        std::cout << "top element: " << s.peek() << std::endl;
    }
    {
        const int max_elements = 100;
        class Queue
        {
        private:
            int front;
            int rear;
            int arr[max_elements];

        public:
            Queue()
            {
                front = -1;
                rear = -1;
            }
            // function to add an element to the queue
            void enqueue(int x)
            {
                if (rear == max_elements - 1)
                {
                    std::cout << "Error: queue overflow" << std::endl;
                    return;
                }
                arr[++rear] = x;
                if (front == -1)
                {
                    front = 0;
                }
            }
            // function to remove an element from the queue
            int dequeue()
            {
                if (front == -1)
                {
                    std::cout << "queue underflow" << std::endl;
                    return -1;
                }
                int x = arr[front];
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front++;
                }
                return x;
            }
            // function to check if ueue is empty
            bool is_empty()
            {
                return front == -1;
            }
            // function to return the front element of the queue
            int peek()
            {
                if (front == -1)
                {
                    std::cout << "queue is empty" << std::endl;
                    return -1;
                }
                return arr[front];
            }
        };

        Queue q;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);

        std::cout << "Dequeued element: " << q.dequeue() << std::endl;
        std::cout << "Front element: " << q.peek() << std::endl;
    }
    {
        class Stack
        {
            std::queue<int> q1;
            std::queue<int> q2;

        public:
            void push(int x)
            {
                // push x first in empty q2
                q2.push(x);
                // push all the remaining elements in q1 to q2
                while (!q1.empty())
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                // swap the names of two queues
                std::queue<int> q = q1;
                q1 = q2;
                q2 = q;
            }
            void pop()
            {
                // if no elements are there in q1
                if (q1.empty())
                {
                    return;
                }
                q1.pop();
            }
            int top()
            {
                if (q1.empty())
                {
                    return -1;
                }
                return q1.front();
            }
            int size()
            {
                return q1.size();
            }
        };
        Stack s;
        // inserting elements in stack
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);

        std::cout << "Size: " << s.size() << std::endl;
        std::cout << s.top() << std::endl;
        s.pop();
        std::cout << s.top() << std::endl;
        s.pop();
        std::cout << s.top() << std::endl;

        std::cout << "Size: " << s.size() << std::endl;
    }
    {
        class Stack
        {
            std::list<int> l;
            int cs = 0;

        public:
            void push(int d)
            {
                cs++;
                l.push_front(d);
            }
            // popping an element from the stack
            void pop()
            {
                if (cs <= 0)
                {
                    std::cout << "stack empty" << std::endl;
                }
                else
                {
                    cs--;
                    l.pop_front();
                }
            }
            // if current size is 0 then stack is empty
            bool empty()
            {
                return cs == 0;
            }
            // getting the element present at the top of the stack
            int top()
            {
                return l.front();
            }
            int size()
            {
                return cs;
            }
            // printing the elements of the stack
            void print()
            {
                for (auto x : l)
                {
                    std::cout << x << std::endl;
                }
            }
        };
        Stack s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);

        std::cout << "Size: " << s.size() << std::endl;
        std::cout << "Top element:" << s.top() << std::endl;
        s.pop();
        std::cout << "Top element:" << s.top() << std::endl;
        s.pop();
        std::cout << "Top element:" << s.top() << std::endl;
        std::cout << "Size:" << s.size() << std::endl;
    }
    {
        auto is_subset = [](auto &&arr1, auto &&arr2)
        {
            int i = 0;
            int j = 0;
            for (i = 0; i < arr2.size(); i++)
            {
                for (j = 0; j < arr1.size(); j++)
                {
                    if (arr2[i] == arr1[j])
                        break;
                }
                if (j == arr1.size())
                {
                    return 0;
                }
            }
            return 1;
        };
        std::array arr1{1, 11, 31, 21, 30, 17};
        std::array arr2{11, 30, 17, 1};
        if (is_subset(arr1, arr2))
        {
            std::cout << "arr2 is subset of arr1\n";
        }
        else
        {
            std::cout << "arr2 is not a subset of arr1\n";
        }
    }
    {
        auto rotate = [](auto &&arr, int k)
        {
            // temp array
            int temp[arr.size()];
            // Keepig track of the current index
            // of temp[]
            int t = 0;

            // Storing the n - d elements of
            // array arr[] to the front of temp[]
            for (int i = k; i < arr.size(); i++)
            {
                temp[t] = arr[i];
                t++;
            }

            // Storing the first d elements of array arr[]
            // into temp
            for (int i = 0; i < k; i++)
            {
                temp[t] = arr[i];
                t++;
            }

            // Copying the elements of temp[] in arr[]
            for (int i = 0; i < arr.size(); i++)
            {
                arr[i] = temp[i];
            }
        };
        auto print_array = [](auto &&arr)
        {
            for (auto a : arr)
            {
                std::cout << a << " ";
            }
            std::cout << std::endl;
        };
        std::array arr{1, 2, 3, 4, 5};
        int k = 2;
        rotate(arr, k);
        print_array(arr);
    }
    {
        auto asc_dec_func = [](auto &&a)
        {
            int temp;
            for (int i = 0; i < a.size() - 1; i++)
            {
                for (int j = 0; j < a.size() / 2; j++)
                {
                    if (a[j] > a[j + 1])
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }

                for (int j = a.size() / 2; j < a.size() - 1; j++)
                {
                    if (a[j] < a[j + 1])
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }

            for (int i = 0; i < a.size(); i++)
            {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;
        };
        std::array arr{1, 2, 3, 4, 5, 6, 7, 8};
        asc_dec_func(arr);
    }
    {
        auto reverse = [](auto &&str)
        {
            for (int i = str.length() - 1; i >= 0; i--)
            {
                std::cout << str[i] << " ";
            }
        };
        std::string str{"GeeksforGeeks"};
        reverse(str);
    }
    {
        auto permute = [](auto &op, std::string s, std::string answer)
        {
            if (s.length() == 0)
            {
                std::cout << answer << std::endl;
                return;
            }
            for (int i = 0; i < s.length(); i++)
            {
                char ch = s[i];
                std::string left = s.substr(0, i);
                std::string right = s.substr(i + 1);
                std::string result = left + right;
                op(op, result, answer + ch);
            }
        };
        std::string s = "ABC";
        std::string answer = "";
        permute(permute, s, answer);
    }
    {
        auto compare = [](const void *a, const void *b) -> int
        {
            return (*(char *)a - *(char *)b);
        };
        auto find_ceil = [](auto &&str, char first, int l, int h)
        {
            int ceil_index = l;
            for (int i = l + 1; i <= h; i++)
                if (str[i] > first && str[i] < str[ceil_index])
                    ceil_index = i;
            return ceil_index;
        };
        auto permutations = [&](auto &&str)
        {
            int size = std::strlen(str);
            std::qsort(str, size, sizeof(str[0]), compare);
            bool is_finished = false;
            while (!is_finished)
            {
                std::cout << str << std::endl;
                int i;
                for (i = size - 2; i >= 0; --i)
                {
                    if (str[i] < str[i + 1])
                    {
                        break;
                    }
                }
                if (i == -1)
                {
                    is_finished = true;
                }
                else
                {
                    int ceilIndex = find_ceil(str, str[i], i + 1, size - 1);
                    std::swap(str[i], str[ceilIndex]);
                    std::qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
                }
            }
        };
        char str[]{"XYZ"};
        permutations(str);
    }
    {
        auto remove_brackets = [](std::string str) -> std::string
        {
            std::string result = "";
            for (char c : str)
            {
                if (c != '(' && c != ')')
                {
                    result += c;
                }
            }
            return result;
        };
        std::string str{"Geeks)(for)(geeks"};
        std::cout << "Without brackets: " << remove_brackets(str) << std::endl;
    }
    {
        struct Node
        {
            int data;
            Node *next;
        };
        Node *head = nullptr;
        // function to insert node in LL
        auto insert = [&](int data)
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        };
        // function to delete node of LL
        auto delete_node = [&](int data)
        {
            Node *temp = head;
            Node *prev = nullptr;
            if (temp != nullptr && temp->data == data)
            {
                head = temp->next;
                delete temp;
                return;
            }
            while (temp != nullptr && temp->data != data)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == nullptr)
            {
                return;
            }
            prev->next = temp->next;
            delete temp;
        };
        auto print_list = [&]()
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        };
        insert(1);
        insert(2);
        insert(3);
        insert(4);
        insert(5);
        std::cout << "Linked list is \n";
        print_list();
        delete_node(3);
        std::cout << "Linked list after deletion of 3: \n";
        print_list();
    }
    {
        struct Node
        {
            int data;
            Node *next;
            Node *prev;
        };
        class DoublyLinkedList
        {
        private:
            Node *head;

        public:
            DoublyLinkedList() : head(NULL) {}
            void insert_at_start(int data)
            {
                Node *new_node = new Node;
                new_node->data = data;
                new_node->next = head;
                new_node->prev = NULL;
                if (head != NULL)
                {
                    head->prev = new_node;
                }
                head = new_node;
            }
            void delete_node(int data)
            {
                Node *temp = head;
                while (temp != NULL && temp->data != data)
                {
                    temp = temp->next;
                }
                if (temp == NULL)
                {
                    return;
                }
                if (temp->prev != NULL)
                {
                    temp->prev->next = temp->next;
                }
                else
                {
                    head = temp->next;
                }
                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                delete temp;
            };
            void print_list()
            {
                Node *temp = head;
                while (temp != NULL)
                {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
                std::cout << std::endl;
            }
        };
        DoublyLinkedList dll;
        dll.insert_at_start(1);
        dll.insert_at_start(2);
        dll.insert_at_start(3);
        dll.insert_at_start(4);
        dll.insert_at_start(5);
        std::cout << "Original Doubly Linked List: ";
        dll.print_list();
        dll.delete_node(2);
        std::cout << "Doubly Linked List after deletion: ";
        dll.print_list();
    }
    {
        struct Node
        {
            int data;
            Node *next;
        };
        class CircularLinkedList
        {
        private:
            Node *head;

        public:
            CircularLinkedList() : head(NULL){};
            void insert_at_start(int data)
            {
                Node *new_node = new Node;
                new_node->data = data;
                new_node->next = head;
                if (head == NULL)
                {
                    head = new_node;
                    new_node->next = head;
                }
                else
                {
                    Node *temp = head;
                    while (temp->next != head)
                    {
                        temp = temp->next;
                    }
                    temp->next = new_node;
                    head = new_node;
                }
            }
            void delete_node(int data)
            {
                Node *temp = head;
                if (temp == NULL)
                    return;

                if (temp->next == head)
                {
                    head = NULL;
                    delete temp;
                    return;
                }

                Node *prev = NULL;
                while (temp->next != head && temp->data != data)
                {
                    prev = temp;
                    temp = temp->next;
                }

                if (temp->data != data)
                    return;

                prev->next = temp->next;
                if (temp == head)
                    head = temp->next;
                delete temp;
            }
            void print_list()
            {
                Node *temp = head;
                while (temp->next != head)
                {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
                std::cout << temp->data << std::endl;
            }
        };
        CircularLinkedList cll;
        cll.insert_at_start(1);
        cll.insert_at_start(2);
        cll.insert_at_start(3);
        cll.insert_at_start(4);
        cll.insert_at_start(5);
        std::cout << "Original Circular Linked list ";
        cll.print_list();
        cll.delete_node(2);
        std::cout << "Circular Linked List after deletion ";
        cll.print_list();
    }
    {
        struct Node
        {
            int data;
            struct Node *left;
            struct Node *right;
        };
        auto new_node = [](int data) -> Node *
        {
            Node *temp = new Node;
            temp->data = data;
            temp->right = NULL;
            temp->left = NULL;
            return temp;
        };
        auto print_in_order = [](auto &op, Node *node)
        {
            if (node == NULL)
            {
                return;
            }
            // first recur on left child
            op(op, node->left);
            // then print the data of node
            std::cout << node->data << " ";
            // now recur on right child
            op(op, node->right);
        };
        Node *root = new_node(1);
        root->left = new_node(2);
        root->right = new_node(3);
        root->left->left = new_node(4);
        root->left->right = new_node(5);
        std::cout << "Inorder traversal of binary tree is \n";
        print_in_order(print_in_order, root);
    }
    {
        auto find_subset = [](auto &op,
                              std::vector<int> &a,
                              std::vector<std::vector<int>> &ans,
                              std::vector<int> &subset,
                              int index) -> void
        {
            ans.push_back(subset);
            for (int i = index; i < a.size(); i++)
            {
                subset.push_back(a[i]);
                op(op, a, ans, subset, i + 1);
                subset.pop_back();
            }
        };

        auto subsets = [&](std::vector<int> &a) -> std::vector<std::vector<int>>
        {
            std::vector<int> subset;
            std::vector<std::vector<int>> ans;
            int index = 0;
            find_subset(find_subset, a, ans, subset, index);
            return ans;
        };
        std::vector<int> array{1, 2, 3, 4, 5};
        std::vector<std::vector<int>> ans{subsets(array)};
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                std::cout << ans[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    {
        struct Node
        {
            int data;
            Node *left;
            Node *right;
        };
        // Utility function to create a new tree node
        auto new_node = [](int data)
        {
            Node *temp = new Node;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        };
        // Given a binary tree, print its nodes in preorder
        auto print_preorder = [](auto &op, Node *node)
        {
            if (node == NULL)
            {
                return;
            }
            // first print data of node
            std::cout << node->data << " ";
            // then recur on left subtree
            op(op, node->left);
            // now recur on right subtree
            op(op, node->right);
        };
        Node *root = new_node(1);
        root->left = new_node(2);
        root->right = new_node(3);
        root->left->left = new_node(4);
        root->left->right = new_node(5);

        std::cout << "Preorder traversal of binary tree is \n";
        print_preorder(print_preorder, root);
    }
    {
        struct Node
        {
            int data;
            Node *left;
            Node *right;
        };
        // Utility function to create a new tree node
        auto new_node = [](int data)
        {
            Node *temp = new Node;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        };
        // Given a binary tree, print its nodes according to the "bottom-up" postorder traversal.
        auto print_postorder = [](auto &op, Node *node)
        {
            if (node == NULL)
            {
                return;
            }
            // first recur on left subtree
            op(op, node->left);
            // then recur on right subtree
            op(op, node->right);
            // now deal with node
            std::cout << node->data << " ";
        };
        Node *root = new_node(1);
        root->left = new_node(2);
        root->right = new_node(3);
        root->left->left = new_node(4);
        root->left->right = new_node(5);
        std::cout << "Postorder traversal of binary tree is \n";
        print_postorder(print_postorder, root);
    }
    {
        struct Node
        {
            int data;
            Node *left;
            Node *right;
        };
        auto new_node = [](int data)
        {
            Node *temp = new Node;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        };
        auto print_level_order = [](Node *node)
        {
            if (node == NULL)
            {
                return;
            }
            std::queue<Node *> q;
            while (node)
            {
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                std::cout << node->data << " ";
                node = q.front();
                q.pop();
            }
        };
        Node *root = new_node(1);
        root->left = new_node(2);
        root->right = new_node(3);
        root->left->left = new_node(4);
        root->left->right = new_node(5);
        std::cout << "Levelorder traversal of binary tree is \n";
        print_level_order(root);
    }
    {
        struct Node
        {
            Node *left;
            Node *right;
            int hd;
            int data;
        };
        auto new_node = [](int key)
        {
            Node *node = new Node();
            node->left = NULL;
            node->right = NULL;
            node->data = key;
            node->hd = 0;
            return node;
        };
        // function to print top view of a binary tree
        auto top_view = [](Node *root)
        {
            if (root == NULL)
            {
                return;
            }
            std::queue<Node *> q;
            std::map<int, int> m;
            int hd = 0;
            root->hd = hd;

            q.push(root);

            while (q.size())
            {
                hd = root->hd;

                if (m.count(hd) == 0)
                    m[hd] = root->data;
                if (root->left)
                {
                    root->left->hd = hd - 1;
                    q.push(root->left);
                }
                if (root->right)
                {
                    root->right->hd = hd + 1;
                    q.push(root->right);
                }
                q.pop();
                root = q.front();
            }
            // printing top view
            for (auto &rec : m)
            {
                std::cout << rec.second << " ";
            }
        };
        Node *root = new_node(1);
        root->left = new_node(2);
        root->right = new_node(3);
        root->left->left = new_node(4);
        root->left->right = new_node(5);
        top_view(root);
    }
    {
        struct Node
        {
            Node *left;
            Node *right;
            int data;
        };
        auto new_node = [](int key)
        {
            Node *node = new Node;
            node->data = key;
            node->left = NULL;
            node->right = NULL;
            return node;
        };
        auto left_view = [](Node *root)
        {
            if (!root)
            {
                return;
            }
            std::queue<Node *> q;
            q.push(root);
            while (!q.empty())
            {
                int n = q.size();
                for (int i = 1; i <= n; i++)
                {
                    Node *temp = q.front();
                    q.pop();
                    if (i == 1)
                    {
                        std::cout << temp->data << " ";
                    }
                    if (temp->left != NULL)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right != NULL)
                    {
                        q.push(temp->right);
                    }
                }
            }
        };
        Node *root = new_node(1);
        root->left = new_node(2);
        root->right = new_node(3);
        root->left->left = new_node(4);
        root->right->right = new_node(5);
        std::cout << "left view\n";
        left_view(root);
        std::cout << std::endl;
    }
    {
        struct Node
        {
            Node *left;
            Node *right;
            int data;
        };
        auto new_node = [](int key)
        {
            Node *node = new Node;
            node->data = key;
            node->left = NULL;
            node->right = NULL;
            return node;
        };
        auto right_view = [](Node *root)
        {
            if (root == NULL)
            {
                return;
            }
            std::queue<Node *> q;
            q.push(root);
            while (!q.empty())
            {
                int n = q.size();
                while (n--)
                {
                    Node *x = q.front();
                    q.pop();
                    if (n == 0)
                    {
                        std::cout << x->data << " ";
                    }
                    if (x->left)
                    {
                        q.push(x->left);
                    }
                    if (x->right)
                    {
                        q.push(x->right);
                    }
                }
            }
        };
        Node *root = new_node(1);
        root->left = new_node(2);
        root->right = new_node(3);
        root->left->left = new_node(4);
        root->left->right = new_node(5);
        std::cout << "right view\n";
        right_view(root);
        std::cout << std::endl;
    }
    {
        auto infix_to_postfix = [](std::string &expression)
        {
            // string to store postfix expression
            std::string postfix;
            // operator stack
            std::stack<char> ope_stack;
            // operator precedence map
            std::unordered_map<char, int> pre = {{'+', 1},
                                            {'-', 1},
                                            {'*', 2},
                                            {'/', 2},
                                            {'(', 0}};

            int length = expression.length();
            for (int i = 0; i < length; i++)
            {
                char c = expression[i];
                // checking operands
                if ((c >= 92 && c <= 122) || (c >= 48 && c <= 57))
                {
                    postfix.push_back(c);
                }
                // checking braces
                else if (c == '(')
                {
                    ope_stack.push(c);
                }
                else if (c == ')')
                {
                    while (ope_stack.top() != '(')
                    {
                        postfix.push_back(ope_stack.top());
                        ope_stack.pop();
                    }
                    ope_stack.pop();
                }
                // checking operators
                else
                {
                    while (!ope_stack.empty() && pre.at(c) < pre.at(ope_stack.top()))
                    {
                        postfix.push_back(ope_stack.top());
                        ope_stack.pop();
                    }
                    ope_stack.push(c);
                }
            }
            // popping whole stack at the end
            while (!ope_stack.empty())
            {
                postfix.push_back(ope_stack.top());
                ope_stack.pop();
            }
            return postfix;
        };
        std::string s{"a*b+(c-d)"};
        std::cout << "normal: " << s << std::endl;
        std::cout << infix_to_postfix(s) << std::endl;
    }
    return 0;
}
