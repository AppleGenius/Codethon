// 12Print1ToMaxOfNDigits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>

void PrintNumber(char *number);
bool Increment(char *number);
void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index);


//=============================== Solution 1 =======================================
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
		PrintNumber(number);

	delete[] number;
}

bool Increment(char *number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;

		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}

//=============================== Solution 2 =======================================
void Print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}

	delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

void PrintNumber(char *number)
{
	bool isBeginning = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning && number[i] != '0')
			isBeginning = false;

		if (!isBeginning)
			printf("%c", number[i]);
	}

	printf("\t");
}

//=============================== Test Code =======================================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	Print1ToMaxOfNDigits_1(n);
	Print1ToMaxOfNDigits_2(n);

	printf("\nTest for %d ends.\n", n);
}



int _tmain(int argc, _TCHAR* argv[])
{
	Test(1);
	Test(2);
	Test(3);
	Test(0);
	Test(-1);
	return 0;
}

