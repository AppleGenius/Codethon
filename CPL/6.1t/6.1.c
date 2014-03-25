#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS 100
#define BUFSIZE 1000

struct key{
	char *word;
	int count;
}keytab[NKEYS];

char buf[BUFSIZE];
int bufp = 0;

int getword(char *, int);
int binsearch(char *, struct key *, int);
int getch(void);
void unget(int c);


int main(int argc, const char *argv[])
{
	int n = 0;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	}

	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);

	return 0;

}

int binsearch(char * word, struct key tab[], int n)
{
	int cond = 0;
	int low = 0, high = n-1, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)){
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';

	return word[0];
}


int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters!\n");
	else
		buf[bufp++] = c;
}