#include <stdio.h>

int main(int argc, const char *argv[])
{
	char data1[] = "Hello";
	char data2[] = "Hello";

	printf("data1's address is : 0x%x\n", data1);
	printf("data1's address is : 0x%x\n", data2);
	char *pdata1 = "Hello";
	char *pdata2 = "Hello";
	printf("data1's address is : 0x%x\n", pdata1);
	printf("data1's address is : 0x%x\n", pdata2);

	printf("%d\n", strlen(data1));
	printf("%d\n", strlen(data2));
	printf("%d\n", strlen(pdata1));
	printf("%d\n", strlen(pdata2));

	if (data1 == data2)
		printf("The Array are same!\n");
	else
		printf("The Array are different!\n");

	if (pdata1 == pdata2)
		printf("The pointer are same!\n");
	else
		printf("The pointer are different!\n");

	return 0;
}