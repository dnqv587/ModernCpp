#include <string>

template<class D>
class Animal
{
 public:
	std::string bark()
	{
		return static_cast<D&>(*this).barkImpl();
	}
};

class Dog:public Animal<Dog>
{
 private:
	friend Animal;
	std::string barkImpl()
	{
		return "汪汪";
	}
};

class Cat:public Animal<Cat>
{
 private:
	friend Animal;
	std::string barkImpl()
	{
		return "喵喵";
	}
};

template<class T>
std::string doBark(Animal<T>& animal)
{
	return animal.bark();
}


