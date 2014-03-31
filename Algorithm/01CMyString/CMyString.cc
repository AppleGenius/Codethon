/*
*	要求：如下为CMyString的声明，请为该类型添加赋值运算符函数
*	要点：	1. 是否把返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用（即*this），只有返回一个引用，才可以允许连续赋值。
*			否则如果函数声明返回值是void，应用该赋值运算符将不能做连续赋值。如 str1 = str2 = str3将不能通过编译
*			2. 是否把传入的参数的类型声明为常量引用，如果传入的参数不是引用而是实例，那么从形参到实参会调用一次拷贝构造函数；把参数的声明为
*			引用可以避免这样的无畏的消耗，能提高代码质量，同时我们在赋值运算符函数内不会改变传入的实例的状态，因此要在传入的引用参数上加上const关键字
*			3. 是否释放了自己使用的内存，如果我们忘记在分配新内存之前释放自身的空间，程序将出现内存泄漏。
*			4. 是否判断了传入参数和当前的实例*this是不是同一个实例，如果是同一个，则不进行赋值操作，直接返回，如果事先不判断就进行赋值操作，那么在释放实力自身的
*			内存的时候就会导致严重的错误；当*this和传入的参数是同一个实例时，那么一旦释放了自身的内存，传入的参数的内存也就同时被释放了，因此再也找不到需要的赋值内容了
*/

#include <iostream>

class CMyString{

private: 
	char *m_pData;

public :
	CMyString(char *pData = NULL);
	CMyString(const CMyString &str);
	~CMyString();

	CMyString& operator = (const CMyString &str);

	void Print();
};


CMyString::CMyString(char *pData)
{
	if (pData == NULL){
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else{
		int len = strlen(pData);
		m_pData = new char[len + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	int len = strlen(str.m_pData);
	m_pData = new char[len + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

void CMyString::Print()
{
	printf("%s\n", m_pData);
}

// 初级写法：一般软件工程师
CMyString& CMyString::operator = (const CMyString &str)
{
	if (this == &str)
		return *this;

	delete[]m_pData;
	m_pData = NULL;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

//// 高级写法: 高级软件工程师
//CMyString& CMyString::operator=(const CMyString &str)
//{
//	if (this != &str){
//		CMyString strTmp(str);
//
//		char *pTmp = strTmp.m_pData;
//		strTmp.m_pData = m_pData;
//		m_pData = pTmp;
//	}
//
//	return *this;
//}



//========================Test Code==========================
//正常赋值
void Test1()
{
	printf("Test1 Begins....:\n");

	char *text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is : %s\n", text);
	printf("The actual result is : ");
	str2.Print();
	printf("\n");
}


// 自己给自己赋值
void Test2()
{
	printf("The Test2 Begins......:\n");
	char *text = "Hello World";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is : %s\n", text);
	printf("The actual result is : ");
	str1.Print();
	printf("\n");
}

// 连续赋值
void Test3()
{
	printf("The Test3 Begins......:\n");
	char *text = "Hello World";

	CMyString str1(text);
	CMyString str2, str3;

	str3 = str2 = str1;

	printf("The expected result is : %s\n", text);
	printf("The actual result is : ");
	str2.Print();
	printf("\n");

	str3.Print();
	printf("\n");
}


int main(int argc, const char *argv[])
{
	Test1();
	Test2();
	Test3();
	return 0;
}

