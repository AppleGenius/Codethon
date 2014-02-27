#include <stdio.h>
#include <ctype.h>

void escape(char *s, char *t)
{
	int i = 0, j = 0;

	while (t[i])
	{
		switch (t[i])
		{
		case '\n':
			s[j++] = '\\';
			s[j] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j] = 'n';
			break;
		default:
			s[j] = t[i];
			break;
		}
		i++;
		j++;
	}

	s[j] = t[i];
}

int atoi(char *s)
{
	int i = 0, n = 0, sign = 0;

	for (i = 0; isspace(s[i]); ++i);

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '-' || s[i] == '+')
	{
		i++;
	}

	for (n = 0; isdigit(s[i]); i++)
	{
		n = 10 * n + (s[i] - '0');
	}

	return sign * n;
}

void reverse(char *s)
{
	for (int i = 0, j = strlen(s) - 1, c = 0; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}		
	
}

void itoa(int n, char *s)
{
	int i = 0, sign = n;

	do 
	{
		s[i++] = abs(n % 10) + '0';
	} while (n /= 10);
	
	if (sign < 0)
	{
		s[i++] = '-';
		s[i] = '\0';
		reverse(s);
	}
}

void itob(int n, char *s, int b)
{
	static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0, sign = n;

	if (b < 2 || b > 36)
		printf("Error\n");

	if ((sign = n) < 0)
		n = -n;
	
	do 
	{
		s[i++] = digits[n % b];
	} while ((n/=b) > 0);
	if (sign < 0)
	{
		s[i++] = '-';
	}

	s[i] = '\0';
	reverse(s);
}

int main(int argc, const char *argv[])
{
	int c, i = 0, nwhite = 0, nother = 0, ndigit[10];

	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;
	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
		case '0': case '1': case '2': case '3': case '4': case '5':case '6': case '7': case '8': case '9':
			ndigit[c - '0']++;
			break;
		case ' ':
		case '\n':
		case '\t':
			nwhite++;
			break;
		default:
			nother++;
			break;
		}
	}
	return 0;
}