// 08MinNumberInRotateArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <exception>


int MinInOrder(int *numbers, int index1, int index2);

int Min(int *numbers, int length)
{
	if (numbers == NULL && length <= 0)
		throw std::exception("Invalid Inputs!");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);


		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
}

int MinInOrder(int *numbers, int index1, int index2)
{
	int result = numbers[index1];

	for (int i = index1; i <= index2; i++)
	{
		if (result > numbers[i])
			result = numbers[i];
	}

	return result;
}


//=============================================== Test code ===============================================================
void Test(int *numbers, int length, int expeced)
{
	int result = 0;
	try
	{
		result = Min(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expeced)
			printf("\tPassed!\n");
		else
			printf("\tFailed\n");
	}
	catch (...)
	{
		if (numbers == NULL)
			printf("Test passed!\n");
		else
			printf("Test failed!\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	Test(NULL, 0, 0);
	return 0;
}

