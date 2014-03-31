/*
* 主要问题： A的拷贝构造函数传入的参数是A的一个实例，由于是传值参数，我们把形参复制到实参会调用拷贝构造函数，
*			因此如果允许复制构造函数传值，就会在复制构造函数内调用复制构造函数，就会形成永无休止的递归调用
*			从而导致栈溢出，因此在C++的标准钟不允许拷贝构造函数传值参数，在VS和GCC下，都将编译出错，要解决
*			这个问题，我们需要把构造函数修改为A(const A& other)，也就是把传值参数改成常量引用
*/
#include <iostream>

class A{
private :
	int value;

public :
	A(int n){ value = n; }
	// Error:编译错误
	//A(A other){ value = other.value; }
	A(const A &other){ value = other.value; }

	void print() { std::cout << value << std::endl; }
};

int main(int argc, const char *argv[])
{
	A a = 10;
	A b = a;
	b.print();

	return 0;
}