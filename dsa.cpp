#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <limits>

#include <stack>
#include <unordered_map>

// INFO: LLM curated samples
int find_max(const std::vector<int> &nums)
{
    int max_num = nums[0];
    for (int num : nums)
    {
        if (num > max_num)
        {
            max_num = num;
        }
    }
    return max_num;
}

bool is_palindrome(const std::string &str)
{
    int left{0};
    int right{static_cast<int>(str.length()) - 1};
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void bubble_sort(std::vector<int> &nums)
{
    int n = nums.size() - 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (nums[i] > nums[j + 1])
            {
                std::swap(nums[i], nums[j + 1]);
            }
        }
    }
}

int find_second_max(const std::vector<int> &nums)
{
    int max = std::numeric_limits<int>::min();
    int second_max = std::numeric_limits<int>::min();

    for (int num : nums)
    {
        if (num > max)
        {
            second_max = max;
            max = num;
        }
        else if (num > second_max && num < max)
        {
            second_max = num;
        }
    }
    return second_max;
}

int fibo_recursive(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}

int fibo_iter(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a{0};
    int b{1};
    int c{};
    for (int i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

std::string reverse_string(const std::string &str)
{
    std::string reversed{""};
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversed += str[i];
    }
    return reversed;
}

int find_substring(const std::string &str, const std::string &sub)
{
    int n = str.length();
    int m = sub.length();
    for (int i = 0; i <= n - m; ++i)
    {
        if (str.substr(i, m) == sub)
        {
            return i;
        }
    }
    return -1;
}

class Queue
{
private:
    std::stack<int> stack1;
    std::stack<int> stack2;

public:
    void enqueue(int x)
    {
        stack1.push(x);
    }
    int dequeue()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int top = stack2.top();
        stack2.pop();
        return top;
    }
};

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(int x)
    {
        if (top >= 99)
        {
            std::cout << "Error: Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }
    int pop()
    {
        if (top == -1)
        {
            std::cout << "Error: No elemenet to pop\n";
            return -1;
        }
        return arr[top--];
    }
    int peek()
    {
        if (top == -1)
        {
            std::cout << "Error: No element in stack\n";
            return -1;
        }
        return arr[top];
    }
};

struct Node
{
    int data;
    Node *next;
};
void print_list(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void delete_list(Node *head)
{
    Node *current = head;
    Node *prev = nullptr;
    while (current)
    {
        prev = current;
        current = current->next;
        delete prev;
    }
}

namespace linked_list
{
    class LinkedList
    {
    private:
        Node *_head;

    public:
        LinkedList()
        {
            _head = nullptr;
        }
        const Node *head()
        {
            return _head;
        }
        void insert(int data)
        {
            Node *new_node = new Node;
            new_node->data = data;
            new_node->next = _head;
            _head = new_node;
        }
        void delete_node(int data)
        {
            Node *current = _head;
            Node *prev = nullptr;
            while (current != nullptr)
            {
                if (current->data == data)
                {
                    if (prev == nullptr)
                    {
                        _head = current->next;
                    }
                    else
                    {
                        prev->next = current->next;
                    }
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
    };
}

namespace remove_duplicates_sorted_list
{
    void remove_duplicates(Node *head)
    {
        Node *current = head;
        while (current != nullptr && current->next != nullptr)
        {
            if (current->data == current->next->data)
            {
                Node *next_node = current->next;
                current->next = next_node->next;
                delete next_node;
            }
            else
            {
                current = current->next;
            }
        }
    }
}

char find_non_repeating_character(const std::string &str)
{
    std::unordered_map<char, int> char_count;
    for (char c : str)
    {
        char_count[c]++;
    }
    for (char c : str)
    {
        if (char_count[c] == 1)
        {
            return c;
        }
    }
    return '\0';
}

namespace reverse_list
{
    Node *reverse(Node *head)
    {
        Node *prev = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            Node *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        return prev;
    }
}
namespace add_two_numbers_list
{
    Node *add_two_numbers(Node *l1, Node *l2)
    {
        Node *dummyHead = new Node{0, 0};
        Node *p = l1, *q = l2, *current = dummyHead;
        int carry = 0;

        while (p != nullptr || q != nullptr || carry)
        {
            int sum = carry;
            if (p != nullptr)
            {
                sum += p->data;
                p = p->next;
            }
            if (q != nullptr)
            {
                sum += q->data;
                q = q->next;
            }
            carry = sum / 10;
            current->next = new Node{sum % 10, 0};
            current = current->next;
        }
        return dummyHead->next;
    }
}

bool is_balanced(const std::string &str)
{
    std::stack<char> s;
    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == ')') && (top != '(') ||
                (c == '}') && (top != '{') ||
                (c == ']') && (top != '['))
            {
                return false;
            }
        }
    }
    return s.empty();
}

int main(int argc, char **argv)
{
    assert(find_max({1, 2, 3, 4, 5}) == 5);
    assert(is_palindrome("radar"));
    {
        std::vector<int> a{1, 5, 2, 4, 3};
        std::vector<int> b{1, 2, 3, 4, 5};
        bubble_sort(a);
        assert(a == b);
    }
    {
        std::vector<int> nums{3, 1, 4, 4, 5, 5};
        assert(find_second_max(nums) == 4);
    }
    {
        assert(fibo_recursive(5) == 5);
        assert(fibo_iter(5) == 5);
    }
    {
        std::string a{"abc"};
        std::string b{"cba"};
        assert(reverse_string(a) == b);
    }
    {
        std::string text{"Hello, world!"};
        std::string substring{"world"};
        assert(find_substring(text, substring) == 7);
    }
    {
        Queue q{};
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        assert(q.dequeue() == 1);
        q.enqueue(4);
        assert(q.dequeue() == 2);
    }
    {
        Stack s;
        s.push(1);
        s.push(2);
        s.push(3);
        assert(s.pop() == 3);
        assert(s.peek() == 2);
    }
    {
        linked_list::LinkedList list;
        list.insert(3);
        list.insert(2);
        list.insert(1);
        list.delete_node(2);
        assert(list.head()->next->data == 3);
    }
    {
        using namespace remove_duplicates_sorted_list;
        Node *head = new Node{1, new Node{1, new Node{2, new Node{3, new Node{3, nullptr}}}}};
        remove_duplicates(head);
        print_list(head);
        delete_list(head);
    }
    {
        std::string input{"swiss"};
        char result = find_non_repeating_character(input);
        assert(result == 'w');
    }
    {
        using namespace reverse_list;
        Node *head = new Node{1, new Node{2, new Node{3, nullptr}}};
        head = reverse(head);
        print_list(head);
        delete_list(head);
    }
    {
        using namespace add_two_numbers_list;
        Node *l1 = new Node{2, new Node{4, new Node{3, nullptr}}};
        Node *l2 = new Node{5, new Node{6, new Node{4, nullptr}}};
        Node *result = add_two_numbers(l1, l2);
        print_list(result);
        delete_list(l1);
        delete_list(l2);
    }
    {
        std::string input{"{[()]}"};
        assert(is_balanced(input));
    }
    return 0;
}