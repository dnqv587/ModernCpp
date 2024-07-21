#include <iostream>
#include <array>

//使用模板元函数实现斐波纳西数列
template<size_t N>
struct Fibnacci{
    constexpr static size_t value=Fibnacci<N-1>::value + Fibnacci<N-2>::value;
};
template<> struct Fibnacci<0>{constexpr static size_t value = 0;};
template<> struct Fibnacci<1>{constexpr static size_t value = 1;};

template<size_t N>
constexpr size_t fibnacci=fibnacci<N-1> + fibnacci<N-2>;

template<> constexpr size_t fibnacci<0> = 0;
template<> constexpr size_t fibnacci<1> = 1;

constinit char arrp[10]={"12345657"};

template<size_t N>
 std::string FileName(const char (&file)[N] ){
        for(int i = N;i>0;--i){
            if(file[N] == '\\'){
                return file+N;
            }
        }
        return "";
}

int main(){

    std::cout<<Fibnacci<10>::value<<std::endl;
    std::cout<<fibnacci<10><<std::endl;
    std::cout<<arrp<<std::endl;
    std::cout<<FileName(__FILE__)<<std::endl;
    return 0;
}