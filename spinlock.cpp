#include <atomic>
#include <thread>
#include <iostream>
#include <cassert>

class SpinLock
{
public:
    void lock()
    {
        while (flag.test_and_set(std::memory_order_acquire))
        {
            // Активно ожидаем, пока флаг не станет доступен
        }
    }
    void unlock()
    {
        flag.clear(std::memory_order_release);
    }

private:
    std::atomic_flag flag{ATOMIC_FLAG_INIT};
};

int main(int argc, char **argv)
{
    SpinLock spinner;
    int sharedResource = 0;
    auto turbo_increment = [&]()
    {
        for (int i{0}; i < 1000000; ++i)
        {
            spinner.lock();
            ++sharedResource;
            spinner.unlock();
        }
    };

    std::thread t1(turbo_increment);
    std::thread t2(turbo_increment);

    t1.join();
    t2.join();

    assert(sharedResource == 2000000);

    return 0;
}
