#include <iostream>
#include <memory_resource>
#include <vector>

template <typename T>
class PmrAllocator
{
public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    template <typename U>
    struct rebind
    {
        using other = PmrAllocator<U>;
    };
    PmrAllocator() : pmr_(std::pmr::get_default_resource()) {}

    pointer allocate(std::size_t size)
    {
        std::cout << "pmr allocate: " << size << std::endl;
        return static_cast<pointer>(pmr_->allocate(size));
    }

    void deallocate(pointer ptr, std::size_t size)
    {
        std::cout << "pmr deallocate: " << size << std::endl;
        pmr_->deallocate(ptr, size);
    }

private:
    std::pmr::memory_resource *pmr_;
};

template <typename T>
class Allocator
{
public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    template <typename U>
    struct rebind
    {
        using other = Allocator<U>;
    };

    Allocator() noexcept = default;

    template <typename U>
    Allocator(const Allocator<U> &) noexcept {}

    [[nodiscard]] pointer allocate(size_type n)
    {
        std::cout << "allocate: " << n << std::endl;
        return static_cast<pointer>(std::malloc(n * sizeof(T)));
    }

    void deallocate(pointer p, size_type n) noexcept
    {
        std::cout << "deallocate: " << n << std::endl;
        std::free(p);
    }

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args)
    {
        std::cout << "construct " << std::endl;
        ::new (static_cast<void *>(p)) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) noexcept
    {
        std::cout << "destroy " << std::endl;
        p->~T();
    }
};

template <typename T, typename U>
bool operator==(const Allocator<T> &, const Allocator<U> &) noexcept
{
    return true;
}

template <typename T, typename U>
bool operator!=(const Allocator<T> &, const Allocator<U> &) noexcept
{
    return false;
}

int main(int argc, char **argv)
{
    std::vector<int, Allocator<int>> vec(10, 0);
    std::vector<int, PmrAllocator<int>> vec2(10, 0);
    return 0;
}
