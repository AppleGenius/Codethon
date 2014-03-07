#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);
int mystrlen(char *s);


int main(int argc, const char *argv[])
{
	char s[] = "0abcde";
	printf("%d\n", mystrlen(s));
	return 0;
}



int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}

	sign = (c == '+') ? 1 : -1;

	if (c == '+' || c == '-')
		c = getch();

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * (*pn) + (c - '0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}


int mystrlen(char *s)
{
	int n = 0;

	for (n = 0; *s != '\0'; n++, s++);

	return n;

}

