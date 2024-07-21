#include <iostream>
#include <future>
#include <thread>
#include <functional>

int func(int n)
{
	int ret{0};
	for(int i = 0 ;i< n ;++i)
	{
		ret += i;
	}
	return ret;
}

int main()
{
    //std::launch::deferred,延迟调用，使async调用发生在当前线程线，将会延迟到get()或wait()时进行调用
    //std::launch::async,启用线程进行调用运行
    //std::launch::async | std::launch::async ，由系统决定是否创建线程进行调用，一般在系统资源紧张时才不会使用线程调用
    auto ret=std::async(std::launch::async,[](int n)->int{
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum += i;
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(5s);
        std::cout<<std::this_thread::get_id()<<std::endl;
        return sum;
    },10);
    //ret.wait();
    std::future_status stat;
    do{
        stat = ret.wait_for(std::chrono::seconds (1));
        switch (stat)
        {
            case std::future_status::deferred:
                std::cout<<"deferred \n";
                break;
            case std::future_status::timeout:
                std::cout<<"timeout \n";
                break;
            case std::future_status::ready:
                std::cout<<"ready \n";
                break;
            default:
                std::cout<<"default \n";
        }

    }while(stat != std::future_status::ready);

    std::cout<<"wait\n";
    std::cout<<std::this_thread::get_id()<<"  "<<ret.get()<<std::endl;

	{
		int n=10;
		std::function<int (int)> ff=[n](int i)->int{
			return func(n*i);
		};
		std::function<int (int)> fff =std::bind(ff,std::placeholders::_1);

		std::packaged_task<int (int)> t1{[&fff](int n)->int{
            std::cout<<std::this_thread::get_id()<<'\n';
		  return fff(n);
		}};
		std::packaged_task<int (int)> t2{fff};
		auto fu = t1.get_future();
		//std::invoke(t1,1); 直接调用的话，实在当前线程进行调用的
        std::thread task(std::move(t1),1);//在其他线程进行调用
        task.join();
        std::cout<<std::this_thread::get_id()<<'\n';
		std::cout<<"packaged_task:"<<fu.get()<<std::endl;
	}



    return 0;
}