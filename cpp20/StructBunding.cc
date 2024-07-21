#include <iostream>
#include <tuple>
#include <string>

//***********************************************
// name      : 结构化绑定
// brief     :
// attention : None
//***********************************************

auto func()
{
    return std::tuple<int,double,std::string>(1,2.0,"hello");
}

int main()
{
    const auto [x1,x2,x3] = func();
    std::cout<<x1<<x2<<x3<<std::endl;
    return 0;
}