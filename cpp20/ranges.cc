#include <iostream>
#include <ranges>
#include <vector>
#include <map>
#include <string>

namespace ranges=std::ranges;
namespace views=std::views;

template<ranges::range T>
auto range_begin(T t)
{
    return t.begin();
}

int main()
{
    std::cout<<"begin end"<<std::endl;
    {//begin end
        std::vector<int> vec{1, 2, 3, 4, 5};
        std::cout << *ranges::begin(vec) << std::endl;
        std::cout << *ranges::cbegin(vec) << std::endl;
        std::cout << *ranges::rbegin(vec) << std::endl;
        std::cout << *ranges::end(vec) << std::endl;
    }
    std::cout<<"range约束"<<std::endl;
    {//range约束
        std::vector<int> vec{1, 2, 3, 4, 5};
        int a=1;
        auto b=range_begin(vec);
        //range_begin(a);
    }
    //适配器
    std::cout<<"适配器"<<std::endl;
    {
        std::vector<int> vec{1, 2, 3, 4, 5,6,7,8,9};
        auto even=vec | views::filter([](auto i){return i%2 ==0;}) |
                                        views::transform([](auto i){return i*i;});
        for(const auto&i : even)
        {
            std::cout<<i<<std::endl;
        }
    }
    std::cout<<"element"<<std::endl;
    {
        std::map<std::string,int> m{{"one",1},{"two",2},{"three",3},{"four",4}};
        auto key_ele = m | views::elements<0>;
        for(auto& i:key_ele)
        {
            std::cout<<i<<' ';
        }
        std::cout<<std::endl;
        auto val_ele = m | views::elements<1>;
        for(auto& i:val_ele)
        {
            std::cout<<i<<' ';
        }
    }


    return 0;
}