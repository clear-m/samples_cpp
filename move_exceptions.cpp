#include <utility>
#include <vector>
#include <cassert>

// TODO: extend with real throw inside
class MyClass
{
public:
    MyClass(int data) : data(data) {}

    MyClass(MyClass &&other) noexcept
    try : data(std::exchange(other.data, 0))
    {
    } // was found in move semantic drafts )
    catch (...)
    {
        // Вернуть other в исходное состояние
        other.data = data;
        // throw
    }
    // ...
private:
    int data;
};

struct NonExceptionalTypeA
{
    NonExceptionalTypeA() {}
    NonExceptionalTypeA(const NonExceptionalTypeA &) {}
    NonExceptionalTypeA(NonExceptionalTypeA &&) noexcept : moved_in_{true} {}
    NonExceptionalTypeA &operator=(const NonExceptionalTypeA &) { return *this; }
    NonExceptionalTypeA &operator=(NonExceptionalTypeA &&) noexcept
    {
        moved_in_ = true;
        return *this;
    }
    bool moved_in_{false};
};

struct ExceptionalTypeA
{
    ExceptionalTypeA() noexcept(false) {}
    ExceptionalTypeA(const ExceptionalTypeA &) noexcept(false) {}
    ExceptionalTypeA(ExceptionalTypeA &&) noexcept(false) : moved_in_{true} {}
    ExceptionalTypeA &operator=(const ExceptionalTypeA &) noexcept(false) { return *this; }
    ExceptionalTypeA &operator=(ExceptionalTypeA &&) noexcept(false)
    {
        moved_in_ = true;
        return *this;
    }
    bool moved_in_{false};
};

int main(int argc, char **argv)
{
    NonExceptionalTypeA obj1;
    NonExceptionalTypeA obj2 = std::move_if_noexcept(obj1);
    assert(obj2.moved_in_);

    ExceptionalTypeA obj3;
    ExceptionalTypeA obj4 = std::move_if_noexcept(obj3);
    assert(!obj4.moved_in_);

    return 0;
}
