#include <stdio.h>

#define  MAXLINE 100

int GetLine(char line[], int maxline);
void CopyLine(char des[], char sou[]);

int main(int argc, const char *argv[])
{
	int currentLen = 0, currMaxLen = 0;
	char currLine[MAXLINE];
	char currMaxLine[MAXLINE];

	while (currentLen = GetLine(currLine, MAXLINE) > 0)
	{
		printf("%d: %s", currentLen, currLine);
		if (currentLen > currMaxLen)
		{
			currMaxLen = currentLen;
			CopyLine(currMaxLine, currLine);
		}
	}

	if (currMaxLen > 0)
	{
		printf("%s\n", currMaxLine);
	}
	return 0;
}


int GetLine(char line[], int maxline)
{
	int c, i;
	for (i = 0; i < maxline - 1 && (c = getchar())!=EOF && c != '\n'; ++i)
	{
		line[i] = c;
	}

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

void CopyLine(char des[], char sou[])
{
	int i = 0;
	while ((des[i] = sou[i]) != '\0')
		i++;
}




















