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

	while (--lim > 0 && (c = getchar())!=EOF && c != '\n' )
}