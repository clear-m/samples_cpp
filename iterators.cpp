#include <vector>
#include <iostream>

// Input Iterators (Итераторы ввода): только считывание элементов последовательности.
template <typename T>
class ArrayInputIterator
{
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    ArrayInputIterator(T *ptr) : m_ptr(ptr) {}

    reference operator*() const { return *m_ptr; }
    pointer operator->() const { return m_ptr; }
    ArrayInputIterator &operator++() { ++m_ptr; return *this; }
    ArrayInputIterator operator++(int) { ArrayInputIterator tmp(*this); ++(*this); return tmp; }
    bool operator==(const ArrayInputIterator &other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const ArrayInputIterator &other) const { return m_ptr != other.m_ptr; }

private:
    T *m_ptr;
};

// Output Iterators (Итераторы вывода): только запись элементов в последовательность.
template <typename T>
class VectorOutputIterator
{
public:
    using iterator_category = std::output_iterator_tag;
    using value_type = void;
    using difference_type = std::ptrdiff_t;
    using pointer = void;
    using reference = void;

    VectorOutputIterator(std::vector<T> &vec, size_t pos)
        : vec_(&vec), pos_(pos) {}

    VectorOutputIterator &operator*() { return *this; }
    VectorOutputIterator &operator++() { ++pos_; return *this; }
    VectorOutputIterator operator++(int) { VectorOutputIterator temp = *this; ++pos_; return temp; }
    VectorOutputIterator &operator=(const T &val) { (*vec_)[pos_] = val; return *this; }

private:
    std::vector<T> *vec_;
    size_t pos_;
};

// Forward Iterators (Однонаправленные итераторы): многократное считывание и запись элементов в последовательности.
template <typename T>
class ForwardIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    ForwardIterator(T *ptr) : ptr(ptr) {}

    ForwardIterator &operator++() { ptr++; return *this; }
    ForwardIterator operator++(int) { ForwardIterator temp = *this; ++(*this); return temp; }
    T &operator*() const { return *ptr; }
    bool operator==(const ForwardIterator &other) const { return ptr == other.ptr; }
    bool operator!=(const ForwardIterator &other) const { return !(*this == other); }

private:
    T *ptr;
};

// Bidirectional Iterators (Двунаправленные итераторы): перемещаться в обоих направлениях по последовательности.
template <typename T>
class BidirectionalIterator
{
public:
    using value_type = T;
    using reference = T &;
    using pointer = T *;

    BidirectionalIterator(pointer ptr) : ptr_(ptr) {}

    BidirectionalIterator &operator++() { ++ptr_; return *this; }
    BidirectionalIterator operator++(int) { BidirectionalIterator temp = *this; ++ptr_; return temp; }
    BidirectionalIterator &operator--() { --ptr_; return *this; }
    BidirectionalIterator operator--(int) { BidirectionalIterator temp = *this; --ptr_; return temp; }
    reference operator*() const { return *ptr_; }
    bool operator==(const BidirectionalIterator &other) const { return ptr_ == other.ptr_; }
    bool operator!=(const BidirectionalIterator &other) const { return ptr_ != other.ptr_; }

private:
    pointer ptr_;
};

// Random Access Iterators (Итераторы произвольного доступа): прямой доступ к элементам за константное время.
template <typename T>
class ArrayRandomAccessIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    ArrayRandomAccessIterator(pointer ptr) : m_ptr(ptr) {}

    reference operator*() const { return *m_ptr; }
    pointer operator->() const { return m_ptr; }

    ArrayRandomAccessIterator &operator++() { ++m_ptr; return *this; }
    ArrayRandomAccessIterator operator++(int) { ArrayRandomAccessIterator tmp(*this); ++m_ptr; return tmp; }
    ArrayRandomAccessIterator &operator--() { --m_ptr; return *this; }
    ArrayRandomAccessIterator operator--(int) { ArrayRandomAccessIterator tmp(*this); --m_ptr; return tmp; }

    ArrayRandomAccessIterator &operator+=(difference_type n) { m_ptr += n; return *this; }
    ArrayRandomAccessIterator operator+(difference_type n) const { return ArrayIterator(m_ptr + n); }
    ArrayRandomAccessIterator &operator-=(difference_type n) { m_ptr -= n; return *this; }
    ArrayRandomAccessIterator operator-(difference_type n) const { return ArrayIterator(m_ptr - n); }

    difference_type operator-(const ArrayRandomAccessIterator &other) const { return m_ptr - other.m_ptr; }

    bool operator==(const ArrayRandomAccessIterator &other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const ArrayRandomAccessIterator &other) const { return m_ptr != other.m_ptr; }
    bool operator<(const ArrayRandomAccessIterator &other) const { return m_ptr < other.m_ptr; }
    bool operator>(const ArrayRandomAccessIterator &other) const { return m_ptr > other.m_ptr; }
    bool operator<=(const ArrayRandomAccessIterator &other) const { return m_ptr <= other.m_ptr; }
    bool operator>=(const ArrayRandomAccessIterator &other) const { return m_ptr >= other.m_ptr; }

private:
    pointer m_ptr;
};

// ReverseIterator: для обратного прохода по элементам контейнера
template <typename Iterator>
class ReverseIterator {
private:
    Iterator current;

public:
    ReverseIterator(Iterator it) : current(it) {}

    ReverseIterator& operator++() { --current; return *this; }
    ReverseIterator operator++(int) { ReverseIterator tmp = *this; --current; return tmp; }
    ReverseIterator& operator--() { ++current; return *this; }
    ReverseIterator operator--(int) { ReverseIterator tmp = *this; ++current; return tmp; }
    
    typename std::iterator_traits<Iterator>::reference operator*() const { auto copy = current; return *--copy; }
    typename std::iterator_traits<Iterator>::pointer operator->() const { auto copy = current; return &*--copy; }
    bool operator==(const ReverseIterator& other) const { return current == other.current; }
    bool operator!=(const ReverseIterator& other) const { return !(*this == other); }
};


// Sentinel Iterators attempt
// Создаем класс Sentinel Iterator
template <typename T>
class SentinelIterator
{
public:
    SentinelIterator(std::vector<T> &data, const T &sentinel, size_t index = 0)
        : data(data), sentinel(sentinel), index(index) {}

    T &operator*()
    {
        if (index >= data.size() || data[index] == sentinel) {
            return const_cast<T&>(sentinel);
        }
        return data[index];
    }

    SentinelIterator &operator++()
    {
        ++index;
        return *this;
    }

    bool operator!=(const SentinelIterator &other) const
    {
        return index != other.index || &data != &other.data;
    }

private:
    std::vector<T> &data;
    const T &sentinel;
    size_t index;
};

int main(int argc, char **argv)
{
    // Input Iterator
    {
        int arr[] = {1, 2, 3, 4, 5};
        ArrayInputIterator<int> it(arr);
        std::cout << *it << std::endl; // Выведет 1
        ++it;
        std::cout << *it << std::endl; // Выведет 2
    }
    // Output Iterator
    {
        std::vector<int> vec(5);
        std::fill_n(VectorOutputIterator<int>(vec, 0), 5, 42);
    }
    // Forward Iterators
    {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        ForwardIterator it(vec.data());
        ForwardIterator end(vec.data() + vec.size());
        for (; it != end; ++it)
        {
            std::cout << *it << " ";
        }
    }
    // BidirectionalIterator
    {
        int arr[] = {1, 2, 3, 4, 5};
        BidirectionalIterator<int> it(&arr[2]);
        std::cout << *it << std::endl; // Output: 3
        ++it;
        std::cout << *it << std::endl; // Output: 4
        --it;
        std::cout << *it << std::endl; // Output: 3
    }
    // RandomAccessIterator
    {
        int arr[] = {1, 2, 3, 4, 5};
        ArrayRandomAccessIterator<int> it(arr);
        std::cout << *it << std::endl; // Выведет 1
        it += 2;
        std::cout << *it << std::endl; // Выведет 2
    }
    // Reverse Iterator
    {
        std::vector<int> vec = {1, 2, 3, 4, 5};

        ReverseIterator<std::vector<int>::iterator> rit(vec.end());
        for(; rit != vec.begin(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;
    }
    // more info https://en.cppreference.com/w/cpp/iterator/sentinel_for
    {
        std::vector<int> numbers = {1, 2, 3, -1, 4, 5, -1, 6, 7};
        const int sentinel = -1;

        SentinelIterator<int> begin(numbers, sentinel);
        SentinelIterator<int> end(numbers, sentinel, 8);

        for (auto it = begin; it != end; ++it)
        {
            if (*it != sentinel)
            {
                std::cout << *it << " ";
            }
            else
            {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
