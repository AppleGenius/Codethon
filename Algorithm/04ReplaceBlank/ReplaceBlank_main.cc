#include <stdio.h>
#include <string.h>

void RepalceBlank(char string[], int length)
{
	if (string == NULL && length <= 0)
		return;

	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;

	while (string[i] != '\0')
	{
		originalLength++;
		if (string[i] == ' ')
			++numberOfBlank;
		i++;
	}


	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length)
		return;
	
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;

	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else{
			string[indexOfNew--] = string[indexOfOriginal];
		}

		--indexOfOriginal;
	}
}

//======================================= Test Code ==================================================
void Test(char *testName, char string[], int length, char expected[])
{
	if (testName != NULL)
		printf("%s begins...", testName);

	RepalceBlank(string, length);

	if (expected == NULL && string == NULL)
		printf("Passed!\n");
	else if (expected == NULL && string != NULL)
		printf("Failed!\n");
	else if (strcmp(string, expected) == 0)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

//blank in the middle of the string
void Test1()
{
	const int length = 100;

	char string[length] = "Hello World";
	Test("Test1", string, length, "Hello%20World");
}

// blank at the head of the string
void Test2()
{
	const int length = 100;
	char string[length] = " HelloWorld";
	Test("Test2", string, length, "%20HelloWorld");
}

// blank at the end of the string
void Test3()
{
	const int length = 100;
	char string[length] = "HelloWorld ";
	Test("Test3", string, length, "HelloWorld%20");
}

// two blanks
void Test4()
{
	const int length = 100;
	char string[length] = "Hello  World";
	Test("Test4", string, length, "Hello%20%20World");
}

// NULL
void Test5()
{
	Test("Test5", NULL, 0, NULL);
}

// 传入为空
void Test6()
{
	const int length = 100;
	char string[length] = "";
	Test("Test6", string, length, "");
}

// 传入一个blank
void Test7()
{
	const int length = 100;
	char string[length] = " ";
	Test("Test7", string, length, "%20");
}

// no blank
void Test8()
{
	const int length = 100;
	char string[length] = "HelloWorld";
	Test("Test8", string, length, "HelloWorld");
}

// all blanks
void Test9()
{
	const int length = 100;
	char string[length] = "  ";
	Test("Test9", string, length, "%20%20");
}


int main(int argc, const char *argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	return 0;
}