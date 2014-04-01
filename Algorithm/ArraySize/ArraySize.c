#include <stdio.h>
#include <stdlib.h>

int GetSize(char data[]);

int main(int argc, const char *argv[])
{
	char data[] = { 1, 2, 3, 4, 5 };
	char *data1 = data;

	int size1 = (int)sizeof(data);
	int size2 = (int)sizeof(data1);
	int size3 = GetSize(data);
	//int size4 = strlen(data);
	//int size5 = strlen(data1);

	printf("sizeof(): %d\t%d\t%d\t\n", size1, size2, size3);
	//printf("strlen: %d\t%d\t\n", size4, size5);
	return 0;
}

int GetSize(int data[])
{
	if (data == NULL)
		return NULL;

	return (int)sizeof(data);
}