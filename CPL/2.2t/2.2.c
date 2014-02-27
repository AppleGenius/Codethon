#include <stdio.h>

int strlen(char s[]);
int atoi(char s[])
{
	int n = 0;

	for (int i = 0; s[i] != '\0' && s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

int main(int argc, const char *argv[])
{
	char s[10] = "123456789";
	printf("%ld\n", atoi(s));
	return 0;
}

int strlen(char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	return i;
}