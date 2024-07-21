#include <iostream>

//形参包，方式1：类型... 包名
//形参包中为值
template<size_t... Args>
class Num
{
public:
    constexpr void print() const
    {
        for(auto& i : {Args...}) //6.形参包展开 - 格式：模式...
        {
            std::cout<<i<<' ';
        }
        std::cout<<std::endl;
    }
};

//形参包，方式2：typename|class... 包名
//形参包中为类型
template<typename... Args>
void print(Args... args) //5.函数形参包 - 格式：包名... 形参包名
{
    //(...,(std::cout<<args<<' '));//折叠表达式

    (std::cout<<...<< args)<<" ";
    std::cout<<std::endl;
}

//形参包，方式3：类型约束... 包名
template<std::integral... Args> //约束为整型
void print2(Args... args)
{
    ((std::cout<<args<<' '),...);
    std::cout<<std::endl;
}

//模板模板形参的形参包，方式4：template<形参列表>typename|class... 包名     //c++17后支持typename
template<template<typename T1,typename T2,typename T3>class... Args>
class Foo
{
};

//形参包递归调用出口，形参包为空的情况
void print3(){}
template<typename T,typename... Args>
void print3(T v,Args... args)
{
    std::cout<<v<<' ';
    print3(args...);//形参包展开，进行递归调用
}

template<size_t... Args>
void print4()
{
    //sizeof...   获取形参包的个数
    int arr[sizeof...(Args)]{Args...};
    for(auto& i:arr)
    {
        std::cout<<i<<' ';
    }
    endl(std::cout);
}

int main()
{
    constexpr Num<1,2,3,4,5,6> N;
    N.print();
    print(1,'2',"3",4.0,5,false);
    print2(1,2,3,4,5);
    print3(1,'2',"3",4.0,5,false);
    endl(std::cout);
    print4<1,2,3,4,5,6>();
    return 0;
}