/*
* ��Ҫ���⣺ A�Ŀ������캯������Ĳ�����A��һ��ʵ���������Ǵ�ֵ���������ǰ��βθ��Ƶ�ʵ�λ���ÿ������캯����
*			�����������ƹ��캯����ֵ���ͻ��ڸ��ƹ��캯���ڵ��ø��ƹ��캯�����ͻ��γ�������ֹ�ĵݹ����
*			�Ӷ�����ջ����������C++�ı�׼�Ӳ����������캯����ֵ��������VS��GCC�£������������Ҫ���
*			������⣬������Ҫ�ѹ��캯���޸�ΪA(const A& other)��Ҳ���ǰѴ�ֵ�����ĳɳ�������
*/
#include <iostream>

class A{
private :
	int value;

public :
	A(int n){ value = n; }
	// Error:�������
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