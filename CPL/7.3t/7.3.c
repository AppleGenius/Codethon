#include <stdio.h>

void filecopy(FILE*, FILE*);

int main(int argc, const char *argv[])
{
	FILE *fp;
	char * prog = argv[0];

	if (argc == 1)
		filecopy(stdin, stdout);
	else{
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL){
				fprintf(stderr, "cat: can't open %s\n", prog, *argv);
				exit(1);
			}
			else{
				filecopy(fp, stdout);
				fclose(fp);
			}	
	}

	if (ferror(stdout)){
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}

	exit(0);
}

void filecopy(FILE* ifp, FILE* ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}

char *fgets(char *s, int n, FILE* iop)
{
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}


int puts(char *s, FILE *iop)
{
	int c;

	while (c = *s++)
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}

int getline(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}