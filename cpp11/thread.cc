#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <chrono>


int main()
{
    std::thread t{
        []()->void{
            std::cout<<"thread"<<std::endl;
        }
    };

    std::cout<<std::this_thread::get_id()<<std::endl;
    t.join();

    std::mutex mutex;

    {
        std::lock_guard<std::mutex> lock(mutex);
        //std::lock_guard<std::mutex> lock(mutex,std::adopt_lock);   //构造时不进行上锁
    }

    {
        //与lock_guard的区别，支持再次进行lock和unlock等操作
        std::unique_lock<std::mutex> lock(mutex,std::defer_lock);
        lock.lock();
    }

    std::mutex mutex1,mutex2;
    {
        //与lock_guard的区别，支持多个锁
        std::scoped_lock lock(mutex1,mutex2);

        //std::lock(mutex1,mutex2);//同时上锁多个锁
    }

    std::once_flag f;
    std::call_once(f,[](){
        std::cout<<"call once"<<std::endl;
    });

    //读写所
    std::shared_mutex s_mutex;
    {
        //写锁
        {
            s_mutex.lock();
            s_mutex.unlock();
        }
        //读锁
        {
            s_mutex.lock_shared();
            s_mutex.unlock_shared();
        }
    }

    //条件变量
    {
        std::mutex cond_mutex;
        std::condition_variable cond;

        std::thread t1([&cond,&cond_mutex]()->void{
            {
                using namespace std::chrono_literals;
                std::this_thread::sleep_for(5s);
                std::unique_lock ulock(cond_mutex);
                ulock.unlock();
                cond.notify_one();
            }
            std::cout<<"this cond thread \n";
        });

        t1.detach();
        {
            std::unique_lock ulock(cond_mutex);
            std::cout<<"main thread \n";
            cond.wait(ulock);
            std::cout<<"main thread cond\n";
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(20s);
    }



    return 0;
}