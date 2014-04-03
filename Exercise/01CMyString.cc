#include <iostream>

class CMyString{

private:
	char *m_data;

public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString& str);
	~CMyString();

	CMyString& operator = (const CMyString &str);

	void Print();
};


CMyString::CMyString(char *pData)
{
	if (pData == NULL){
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else{
		int len = strlen(pData);
		m_data = new char[len + 1];
		strcpy(m_data, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	int len = strlen(str.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, str.m_data);
}

CMyString:: ~CMyString()
{
	delete[] m_data;
}


void CMyString::Print()
{
	printf("%s\n", m_data);
}

CMyString& CMyString:: operator = (const CMyString& str)
{
	if (this == & str)
		return *this;

	delete[] m_data;
	m_data = NULL;

	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);

	return *this;
}


CMyString& CMyString::operator = (const CMyString& str)
{
	if (this != &str){
		CMyString tmp(str);

		char *pTmp = tmp.m_data;
		tmp.m_data = m_data;
		m_data = ptmp;
	}

	return *this;
}

//==============================Test Code==========================================
void  Test1()
{
	printf("Test1 begins...\n");

	char *text = "Hello World";

	CMyString str1(text);
	CMyString str2 = str1;

	printf("The expected result is : %s\n", text);
	printf("The actual result is : %s");
	str2.Print();
	printf("\n");
}


void Test2()
{
	printf("Test2 begins...\n");

	char *text = "Hello World";

	CMyString str1(text);

	str1 = str1;

	printf("The expected result is : %s\n", text);
	printf("The actual result is : %s");
	str1.Print();
	printf("\n");
}


void Test3()
{
	printf("Test3 begins...\n");

	char *text = "Hello World";

	CMyString str1(text);
	CMyString str2, str3;

	str2 = str3 = str1;

	printf("The expected result is : %s\n", text);
	printf("The actual result is : %s");
	str1.Print();
	printf("\n");
	str2.Print();
	printf("\n");

}


int main(int argc, const char *argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}