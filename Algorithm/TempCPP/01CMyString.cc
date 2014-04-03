#include <iostream>

class CMyString{
private :
	char *m_Data;

public :
	CMyString(char *pData = NULL);
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator = (const CMyString& str);

	void Print();
};

CMyString::CMyString(char *pData)
{
	if (pData == NULL){
		m_Data = new char[1];
		m_Data[0] = '\0';
	}
	else{
		m_Data = new char[strlen(pData) + 1];
		strcpy(m_Data, pData);
	}
}

CMyString::CMyString(const CMyString &str)
{
	m_Data = new char[strlen(str.m_Data) + 1];
	strcpy(m_Data, str.m_Data);
}

CMyString::~CMyString()
{
	delete[] m_Data;
}

void CMyString::Print()
{
	printf("%s", m_Data);
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
		return *this;

	delete[] m_Data;
	m_Data = NULL;

	m_Data = new char[strlen(str.m_Data) + 1];
	strcpy(m_Data, str.m_Data);

	return *this;
}

//CMyString& CMyString::operator=(const CMyString& str)
//{
//	if (this != &str){
//		CMyString tmp(str);
//
//		char *pTmp = tmp.m_Data;
//		tmp.m_Data = m_Data;
//		m_Data = pTmp;
//	}
//
//	return *this;
//}


//=============================== Test Code ==========================================
void Test1()
{
	printf("Test1 begins...\n");

	char *text = "Hello World";
	CMyString str1(text);
	CMyString str2 = str1;

	printf("The expected result is : %s\n", text);
	printf("The actual result is : ");
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
	printf("The actual result is : ");
	str1.Print();
	printf("\n");
}


void Test3()
{
	printf("Test3 begins...\n");

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