#include <iostream>

//***********************************************
// name      : CATD--类模板参数推倒，C++17
// brief     : 通过模板函数的实参类型，自动推倒模板类型
// attention : None
//***********************************************

/*
 * 示例：
 *      int m1 = std::max(1,2);//省略显式指明模板参数类型
 *      double m2 = std::max(1,3.14);//由于传入的实参是两个不同的类型，无法自动推到模板类型，需要显式指明
 */



template <typename T1,typename T2>
class CATD
{
public:
    CATD(T1 t1,T2 t2):_t1(t1),_t2(t2){};

    T1 getT1() const
    {
        return _t1;
    }

    T2 getT2() const
    {
        return _t2;
    }

private:
    T1 _t1;
    T2 _t2;
};

//c++17之前，可以定义一个工厂函数，无需显式指明模板参数类型
template <typename T1,typename T2>
static CATD<T1,T2> make_CATD(T1 t1,T2 t2)
{
    return CATD<T1,T2>(t1,t2);
}

int main()
{
    auto ca = make_CATD(1,2.12);//c++17之前也可自动推倒

#if __cplusplus > 201703L
    auto cc = CATD(1,2.12);//C++17之后，不需要显式指明<int ,double>
#else
    auto cc = CATD<int,double>(1,2.12);
#endif
    std::cout<<cc.getT1()<<std::endl;
    std::cout<<cc.getT2()<<std::endl;

    float a= 8.2;
    std::cout<<std::boolalpha<<(8.199999999l > a) <<std::endl;
    return 0;
}