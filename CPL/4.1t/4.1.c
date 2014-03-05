#include <stdio.h>

#define  MAXLINE 1000

int getline(char s[], int max);
int strindex(char source[], int searchfor[]);

char patten[] = "ould";

int main(int argc, const char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	while (getline(line, MAXLINE) > 0)
		if (strindex(line, patten) >= 0)
		{
			printf("%s", line);
			found++;
		}
	return found;
}


int getline(char s[], int lim)
{
	int i = 0, c = 0;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}

int strindexL(char s[], char t[])
{
	int i = 0, count = -1, k;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (int j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}


double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	return sign * val / power;
}