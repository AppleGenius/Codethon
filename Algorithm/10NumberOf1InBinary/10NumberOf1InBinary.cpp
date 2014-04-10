// 10NumberOf1InBinary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int NumberOf1_Solution1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			++count;
		flag = flag << 1;
	}

	return count;
}

int NumberOf1_Solution2(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1) & n;
	}
	return count;
}

//================================================== Test Code ========================================================
void Test(int number, unsigned int expected)
{
	int actual = NumberOf1_Solution1(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);

	actual = NumberOf1_Solution2(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test(0, 0);
	Test(1, 1);
	Test(10, 2);
	Test(0x7FFFFFFF, 31);
	Test(0xFFFFFFFF, 32);
	Test(0x80000000, 1);
	return 0;
}

