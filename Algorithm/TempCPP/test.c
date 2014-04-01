#include <stdio.h>

int GetSize(char *pData);

int main(int argc, const char *argv[])
{
	char *text = "Hello";
	char text2[] = "Hello";
	printf("%d\n", GetSize(text));
	printf("%d\n", GetSize(text2));
	return 0;
}

int GetSize(char *pData)
{
	if (pData == NULL)
		return NULL;

	return strlen(pData);
}