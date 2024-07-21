#include <iostream>
#include <chrono>
#include <ratio>
#include <thread>

int main()
{
    //有理数
    std::ratio<1,60> ra;
    //duration
    std::chrono::duration<int,std::ratio<1>> sec(60);//60秒
    std::chrono::seconds se(1);
    std::chrono::duration<int,std::ratio<60>> min(60);//60分钟
    std::cout<<sec.count()<<std::endl;
    std::cout<<min.count()<<std::endl;
	//时间字面量
    using namespace std::chrono_literals;
	//根据时间类型，转换为相应的时间
    std::chrono::seconds ss(10s+1min+1h);
	//自动转换为时间单位最小的类型
	auto sss(10s+1min+1h);
    std::cout<<"ss="<<ss.count()<<std::endl;
    //系统时钟system_clock
	//当前时间
    auto now = std::chrono::system_clock::now();
    //转换成C风格时间
	auto now_t = std::chrono::system_clock::to_time_t(now);
	std::cout<<std::ctime(&now_t)<<std::endl;
    //高精度时钟
    auto highNow=std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    auto highNow2=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::ratio<1,1000>> elapsed = highNow2 -highNow;
    std::cout<<elapsed.count()<<std::endl;
    //单调时钟
    auto steadyNow=std::chrono::steady_clock::now();


}