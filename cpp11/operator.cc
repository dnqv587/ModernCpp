#include <iostream>

class Foo {
public:
  explicit Foo(int val):_val(val){}

  // 一元运算符

  Foo& operator++() {
    ++_val;
    return *this;
  }

  Foo operator++(int) {
    const Foo temp(_val);
    ++_val;
    return temp;
  }

  Foo& operator--() {
    --_val;
    return *this;
  }

  Foo operator--(int) {
    const Foo temp(_val);
    --_val;
    return temp;
  }

  Foo& operator-() {
    _val = -_val;
    return *this;
  }

  bool operator!() const {
    return !_val;
  }

  //二元运算符
  Foo& operator+(const int val) {
    _val += val;
    return *this;
  }

  Foo& operator-(const int val) {
    _val -= val;
    return *this;
  }

  Foo& operator*(const int val) {
    _val *= val;
    return *this;
  }

  Foo& operator/(const int val) {
    _val /= val;
    return *this;
  }

  //关系运算符
  bool operator>(const Foo& val) const {
    return this->_val > val._val;
  }

  bool operator<(const Foo& val) const {
    return this->_val < val._val;
  }

  bool operator>=(const Foo& val) const {
    return this->_val >= val._val;
  }

  bool operator<=(const Foo& val) const {
    return this->_val <= val._val;
  }

  bool operator==(const Foo& val) const {
    return this->_val == val._val;
  }

  bool operator!=(const Foo& val) const {
    return this->_val != val._val;
  }

  // 输入输出操作符重载
  friend std::ostream& operator<<(std::ostream& os,const Foo& foo){
    os<<foo._val;
    return os;
  }

  friend std::istream& operator<<(std::istream& os,Foo& foo){
    os >> foo._val;
    return os;
  }

  //赋值运算符重载
  Foo& operator=(const Foo& foo) {
    this->_val = foo._val;
    return *this;
  }

  // 函数调用运算符重载
  Foo& operator()(const int a, const int b) {
    _val = a*b;
    return *this;
  }

  //下标运算符重载
  int& operator[](int i) {
    return _val;
  }

  int& operator->(){
    return _val;
  }
private:
  int _val;
};

int main() {
  Foo foo(100);
  std::cout<<++foo<<std::endl;;
  std::cout<<--foo<<std::endl;;
  std::cout<<std::boolalpha<<!foo<<std::endl;;
  std::cout<<-foo<<std::endl;;
  std::cout<<foo*2<<std::endl;;
  std::cout<<foo/2<<std::endl;;
  std::cout<<foo+2<<std::endl;;
  std::cout<<foo-2<<std::endl;;
  std::cout<<std::boolalpha << (foo > Foo(2))<<std::endl;;
  std::cout<<std::boolalpha << (foo < Foo(2))<<std::endl;;
}