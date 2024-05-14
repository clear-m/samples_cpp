#include <vector>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
    // https://alyssaq.github.io/stl-complexities/
    {
        std::vector<int> v{1, 2, 3, 4, 5};
        for (int i{0}; i < 1000; ++i)
        {
            v.push_back(i); // O(1)
        }
        v.erase(v.begin() + 2); // Linear, actually delete elms
        // move all elements not equal 2 to the beggining of v and return new end
        auto new_end = std::remove(v.begin(), v.end(), 2); // not resize, can't delete
        v.erase(new_end, v.end());
        std::cout << v[1]; // O(1)
        std::sort(v.begin(), v.end());
    }
    {
        std::list<int> l{0, 10, 15, 20};
        auto iter = l.begin();
        ++iter;
        l.insert(iter, 5); // O(1)

        iter = l.begin();
        ++iter;
        while (*iter % 2 == 0)
        {
            iter = l.erase(iter); // O(1)
        }

        std::list<int> lst(1000000);
        lst.sort(); // 	O(nlogn)
    }
    {
        std::deque<int> deq{1, 2, 3, 4, 5};
        int first = deq.front();         // O(1)
        int last = deq.back();           // O(1)
        int element = deq[2];            // O(1) amortized
        deq.insert(deq.begin() + 2, 10); // O(1) amortized
        deq.erase(deq.begin() + 2);      // O(1)
    }
    {
        std::map<std::string, int> ages = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 35}};
        ages["One"] = 1;                    // O(logn)
        ages.insert({"Four", 4});           // O(logn)
        ages.erase("Alice");                // O(logn)
        if (ages.find("Bob") != ages.end()) // O(logn)
        {
            std::cout << "Элемент найден: " << ages["Bob"] << std::endl;
        }
        else
        {
            std::cout << "Элемент не найден." << std::endl;
        }
    }
    {
        std::set<int> numbers{5, 2, 8, 3, 5};
        numbers.insert(10);        // O(log n) вставка элемента 10 в Set
        numbers.erase(5);          // O(log n) удаление элемента со значением 5 из Set
        auto it = numbers.find(8); // O(log n) поиск элемента со значением 8 в Set
        if (it != numbers.end())
        {
            std::cout << "Элемент найден";
        }
        else
        {
            std::cout << "Элемент не найден";
        }
    }
    return 0;
}
