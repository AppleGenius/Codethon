#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);
int mystrlen(char *s);
void strcpy(char *s, char *t);
void strcpy1(char *s, char *t);
void strcpy2(char *s, char *t);
int strcmp1(char *s, char *t);


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


void strcpy1(char *s, char *t)
{
	int i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}


void strcpy2(char *s, char *t)
{
	while ((*s = *t) != '\0')
	{
		s++;
		t++;
	}
}


void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0');
}


int strcmp1(char *s, char *t)
{
	int i;

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;

	return s[i] - t[i];
}

int strcmp2(char *s, char *t)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int strcat(char *s, char *t)
{
	while (*s++);
	strcpy(s, t);
}

int strend(char *s, char *t)
{
	int result = 0;
	int s_length = strlen(s);
	int t_length = strlen(t);

	if (t_length < s_length)
	{
		s += s_length - t_length;
		if (0 == strcmp(s, t))
			result = 1;
	}

	return result;
}


char * strncpy(char *s, const char *t, size_t n)
{
	char *p = s;

	for (; n > 0 && *t != '\0'; --n)
		*p++ = *t++;
	for (; n > 0; --n)
		*p++ = '\0';
	return s;

}


char *strncat(char *s, char *t, size_t n)
{
	char *p = s;

	while (*p++ != '\0');
	for (; n > 0 && *t != '\0'; --n)
		*p++ = *t++;
	*p = '\0';
	return s;
}

int strncmp(char *s, char *t, size_t n)
{
	while (n-- > 0 && *s++ == *t++ && *s != '\0');

	if (n == 0 || *s == *t)
		return 0;
	return *s - *t;
}