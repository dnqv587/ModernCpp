#include <iostream>
#include <future>
#include <thread>
#include <algorithm>

int main()
{
	std::promise<int> pms;

    std::thread t1{[](std::promise<int>& pms,int n)->void{
        int ret{0};
        for(int i = 0;i<n;++i)
        {
            ret += i;
        }
        pms.set_value(ret);
        //return ret;
    },std::ref(pms),10};

    auto fur=pms.get_future();
    t1.join();
    std::cout<<fur.get()<<std::endl;

	return 0;
}