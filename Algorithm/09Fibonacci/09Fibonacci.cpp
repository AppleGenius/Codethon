// 09Fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


long long Fibonacci_Solution1(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}

long long Fibonacci_Solution2(unsigned int n)
{
	int result[] = { 0, 1 };
	if (n < 2)
		return result[n];

	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;

	for (unsigned int i = 2; i <= n; ++i)
	{
		fibN = fibNMinusOne + fibNMinusTwo;

		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}

	return fibN;
}

//=============================================== Test Code ===========================================================
void Test(int n, int expected)
{
	if (Fibonacci_Solution1(n) == expected)
		printf("Test of %d in solution1 passed!\n", n);
	else
		printf("Test of %d in solution1 fialed!\n", n);

	if (Fibonacci_Solution2(n) == expected)
		printf("Test of %d in solution2 passed!\n", n);
	else
		printf("Test of %d in solution2 fialed!\n", n);

}


int _tmain(int argc, _TCHAR* argv[])
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);
	return 0;
}

