/*
*	Ҫ������ΪCMyString����������Ϊ��������Ӹ�ֵ���������
*	Ҫ�㣺	1. �Ƿ�ѷ���ֵ����������Ϊ�����͵����ã����ں�������ǰ����ʵ����������ã���*this����ֻ�з���һ�����ã��ſ�������������ֵ��
*			�������������������ֵ��void��Ӧ�øø�ֵ�������������������ֵ���� str1 = str2 = str3������ͨ������
*			2. �Ƿ�Ѵ���Ĳ�������������Ϊ�������ã��������Ĳ����������ö���ʵ������ô���βε�ʵ�λ����һ�ο������캯�����Ѳ���������Ϊ
*			���ÿ��Ա�����������η�����ģ�����ߴ���������ͬʱ�����ڸ�ֵ����������ڲ���ı䴫���ʵ����״̬�����Ҫ�ڴ�������ò����ϼ���const�ؼ���
*			3. �Ƿ��ͷ����Լ�ʹ�õ��ڴ棬������������ڷ������ڴ�֮ǰ�ͷ�����Ŀռ䣬���򽫳����ڴ�й©��
*			4. �Ƿ��ж��˴�������͵�ǰ��ʵ��*this�ǲ���ͬһ��ʵ���������ͬһ�����򲻽��и�ֵ������ֱ�ӷ��أ�������Ȳ��жϾͽ��и�ֵ��������ô���ͷ�ʵ�������
*			�ڴ��ʱ��ͻᵼ�����صĴ��󣻵�*this�ʹ���Ĳ�����ͬһ��ʵ��ʱ����ôһ���ͷ���������ڴ棬����Ĳ������ڴ�Ҳ��ͬʱ���ͷ��ˣ������Ҳ�Ҳ�����Ҫ�ĸ�ֵ������
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

// ����д����һ���������ʦ
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

//// �߼�д��: �߼��������ʦ
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
//������ֵ
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


// �Լ����Լ���ֵ
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

// ������ֵ
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

