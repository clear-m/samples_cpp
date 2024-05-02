#include <iostream>
#include <shared_mutex>
#include <mutex>
#include <thread>
#include <cassert>

class ThreadSafeCounter
{
private:
    mutable std::shared_mutex mutex_;
    unsigned int value_{0};

public:
    ThreadSafeCounter() = default;

    // Несколько поттоков могут одновременно читать значение счетчика (read)
    unsigned int get() const
    {
        std::shared_lock lock(mutex_);
        return value_;
    }

    // Только один поток может инкрементировать значение счетчика (write)
    void increment()
    {
        std::unique_lock lock(mutex_);
        ++value_;
    }

    // Только один поток может сбросить значение счетчика (write)
    void reset()
    {
        std::unique_lock lock(mutex_);
        value_ = 0;
    }
};

int main(int argc, char **argv)
{
    ThreadSafeCounter counter;

    auto increment_and_print = [&]()
    {
        for (int i{}; i < 3; ++i)
        {
            counter.increment();
            std::cout << counter.get() << std::endl;
        }
    };

    std::thread thread1(increment_and_print);
    std::thread thread2(increment_and_print);

    thread1.join();
    thread2.join();

    assert(counter.get() == 6);

    return 0;
}
