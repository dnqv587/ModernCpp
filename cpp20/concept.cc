#include <iostream>
#include <concepts>
#include <type_traits>

template<typename T>
concept isInteger=requires (T lhs,T rhs){
    requires std::is_integral_v<T>;
    lhs + rhs;
};

template<typename T>
requires std::is_integral_v<T> //直接写出约束
constexpr T Add(T lhs,T rhs)
{
    return lhs+rhs;
}

template<typename T>
requires isInteger<T> //约束表达式使用方式1
constexpr T Add(T lhs,T rhs)
{
    return lhs+rhs;
}

constexpr auto Add(isInteger auto lhs,isInteger auto rhs) //对于auto使用约束表达式,lambda同样可以
{
    return lhs+rhs;
}

template<isInteger T>//约束表达式使用方式2
constexpr T Add(T lhs,T rhs)
{
    return lhs+rhs;
}

template<typename T>
constexpr T Add(T lhs,T rhs)
{
    return lhs+rhs;
}

int main()
{
    auto r=Add(12.00,32.00);
    std::cout<<r<<std::endl;
    return 0 ;
}