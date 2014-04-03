#include <stdio.h>

#define  false	0
#define  true	1

int Find(int *matrix, int rows, int columnes, int number)
{

	int found = false;

	if (matrix != NULL && rows > 0 && columnes > 0){
		int row = 0;
		int columne = columnes - 1;
		while (row < rows && columne >= 0){
			if (matrix[row * columnes + columne] == number){
				found = true;
				break;
			}
			else if (matrix[row * columnes + columne] > number)
				--columne;
			else
				++row;
		}
	}

	return found;

}

int FindResult(int *matrix, int rows, int columns, int number)
{
	int found = false;
	
	if (matrix != NULL && rows > 0 && columns > 0){
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0){
			if (matrix[row * columns + column] == number){
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number)
				column--;
			else
				row++;
		}
	}

	return found;
}



//=================================== Test Code =================================================
void Test(char *testName, int *matrix, int rows, int columns, int number, int expected)
{
	if (testName != NULL)
		printf("%s begins", testName);

	int result = Find(matrix, rows, columns, number);

	if (result == expected)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

void TestResult(char *testName, int *matrix, int rows, int columns, int number, int expected)
{
	if (testName != NULL)
		printf("%s begins : ", testName);
	int result = FindResult(matrix, rows, columns, number);

	if (result == expected)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15

// Ҫ���ҵ�����������
void Test1()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test1", (int *)matrix, 4, 4, 7, true);
}

void Test1Result()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TestResult("Test1", (int *)matrix, 4, 4, 7, true);
}

// Ҫ���ҵ�������������
void Test2()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test2", (int *)matrix, 4, 4, 5, false);
}

// Ҫ���ҵ�������������С������
void Test3()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test3", (int*)matrix, 4, 4, 1, true);
}

// Ҫ���ҵ�������������������
void Test4()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test4", (int*)matrix, 4, 4, 15, true);
}

// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test5", (int*)matrix, 4, 4, 0, false);
}

// Ҫ���ҵ������������������ֻ���
void Test6()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
void Test7()
{
	Test("Test7", NULL, 0, 0, 16, false);
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
	return 0;
}