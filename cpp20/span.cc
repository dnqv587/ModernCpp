#include <span>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <iostream>

//std::span -- 范围视图类，描述连续内存范围

template<typename T>
void span_print(std::span<T> span)
{
    for(auto i:span)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    std::array<int,6> arr{1,2,3,4,5,6};
    std::vector<int> vec{1,2,3,4,5,6};
    std::list<int> list{1,2,3,4,5,6};
    std::map<int,std::string> map{{1,"一"},{2,"二"},{3,"三"}};
    std::deque<int> que{1,2,3,4,5,6};

    span_print<int>(arr);
    span_print<int>(vec);
    //span_print<int>(que);   错误，非连续存储
    //span_print<int>(list);  错误，span只能描述连续内存范围的数据结构
    //span_print<int>(map);   错误

    return 0;
}
