#include <iostream>

//***********************************************
// name      : 三路比较
// brief     : 
// attention : None
//***********************************************

class Type
{
public:
    explicit Type(int a,int b)
    :_d(a),
    _v(b)
    {

    }
    friend auto operator<=>(const Type& lhs,const Type& rhs)=default;

    int _d;
    int _v;
};


int main()
{
    //Type aa={1,2};      //拷贝列表初始化不能为explicit构造函数
    Type d1{1,2},d2{2,3};
    auto ret=d1<=>d2;
    //左操作数 > 右操作数，> 0
    //左操作数 < 右操作数，< 0
    //左操作数 = 右操作数，= 0
    if(ret > 0)
    {
        std::cout<<"d1 > d2"<<std::endl;
    }
    else if(ret <0)
    {
        std::cout<<"d1 < d2"<<std::endl;
    }
    else
    {
        std::cout<<"d1 == d2"<<std::endl;
    }
    std::cout<<std::boolalpha<< (d1 < d2)<<std::endl;
    std::cout<<std::boolalpha<< (d1 > d2)<<std::endl;
    std::cout<<std::boolalpha<< (d1 == d2)<<std::endl;
    return 0;
}
