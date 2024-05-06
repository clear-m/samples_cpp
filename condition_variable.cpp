#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <cassert>

int main(int argc, char **argv)
{
    std::mutex mtx;
    std::condition_variable cv;
    bool data_produced{false};
    bool data_consumed{false};

    auto producer = [&]()
    {
        // actually produce ...
        data_produced = true;
        cv.notify_one();
    };

    auto consumer = [&]()
    {
        std::unique_lock lock(mtx);
        cv.wait(lock, [&]()
                { return data_produced; });
        // actually consume ...
        data_consumed = true;
    };

    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    assert(data_produced);
    assert(data_consumed);

    return 0;
}
