#include <stdio.h>

int main(int argc, const char *argv[])
{
	int c;

	while ((c = getchar()) != EOF)
	{
		printf("%c\n", c);
		switch (c)
		{
		case '0': case '1': case '2': case '3': case '4': case '5':case '6': case '7': case '8': case '9':
			printf("Number!\n");
			break;
		case 'a': case 'b':
			printf("Char!\n");
			break;
		default:
			break;
		}
		printf("while\n");
		//break;
	}

	printf("main\n");
	return 0;
}