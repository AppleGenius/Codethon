// TestFibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

long long Fibonacci(unsigned int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("%lld\n", Fibonacci(100));
	return 0;
}

