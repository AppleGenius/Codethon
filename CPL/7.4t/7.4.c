#include <stdio.h>

void func1(void);
void func2(void);

int main(int argc, const char *argv[])
{
	func1();
	func2();
	return 0;
}


void func1()
{
	printf("This is func 1!\n");

	int index = 0;
	int postindex = 0;

	for (; index < 10; index++)
		for (; postindex < 10; postindex++)
			printf("The result is: %d!\n", (index * 10 + postindex));

	printf("\n");
}


void func2()
{
	printf("This is func 2!\n");

	for (int index = 0; index < 10; index++)
		for (int postindex = 0; postindex < 10; postindex++)
			printf("The result is: %d\n", (index * 10 + postindex));

	printf("\n");
}