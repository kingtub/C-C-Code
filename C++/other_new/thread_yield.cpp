#include <iostream>  
#include <chrono>  
#include <thread> 
#include <atomic>
#include <mutex>

std::mutex g_mutex;
std::atomic<bool> ready(false);

void count1m(int id) 
{
    while (!ready)// wait until main() sets ready... 
    {             
        //若线程还有没创建的，将当前线程分配的cpu时间片，让调度器安排给其他线程，
        //由于使用了yield函数，在 not Ready 情况下，避免了空循环，在一定程度上，可以提高cpu的利用率
        std::this_thread::yield();
    }

    for ( int i = 0; i < 1000000; ++i) {}

    std::lock_guard<std::mutex> lock(g_mutex);
    std::cout << "thread : "<< id << std::endl;
}

int main()
{
    std::thread threads[10];

    std::cout << "race of 10 threads that count to 1 million:\n";

    for (int i = 0; i < 10; ++i)
    {
        threads[i] = std::thread(count1m, i);
    }

    ready = true;               // go!

    for (auto& th : threads)
    {
        th.join();
    }

    std::cout << '\n';

    return 0;
}

