#include <iostream>


int main()
{
	int a = 42;
	int &b = a;
	std::cout << &b <<&a << std::endl;
}