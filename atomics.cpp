#include <atomic>
#include <thread>
#include <cassert>

int main(int argc, char **argv)
{
    // api
    std::atomic<int> ai{0};
    ai.store(5);       // Запись значения атомарно
    int a = ai.load(); // Чтение значения атомарно

    ai.fetch_add(1); // Атомарное увеличение значения на 1
    ai.fetch_sub(2); // Атомарное уменьшение значения на 2

    // TODO: add benchmarks here
    // Release-Acquire Barriers
    {
        std::atomic<int> data{0};
        std::atomic<bool> ready{false};
        // thread 1
        std::jthread t1(
            [&]()
            {
                data.store(42, std::memory_order_release);
                ready.store(true, std::memory_order_release);
            });
        // thread 2
        std::jthread t2(
            [&]()
            {
                while (!ready.load(std::memory_order_acquire));
                int value = data.load(std::memory_order_acquire);
                assert(value == 42);
            });
    }
    // Sequential Consistency Barriers (Default)
    {
        std::atomic<int> data{0};
        std::atomic<bool> ready{false};
        {
            // thread 1
            std::jthread t1(
                [&]()
                {
                    data.store(42 /*, std::memory_order_seq_cst*/);
                    ready.store(true /*, std::memory_order_seq_cst*/);
                });
            // thread 2
            std::jthread t2(
                [&]()
                {
                    while (!ready.load(/*std::memory_order_seq_cst*/));
                    int value = data.load(/*std::memory_order_seq_cst*/);
                    assert(value == 42);
                });
        }
    }
    return 0;
}
