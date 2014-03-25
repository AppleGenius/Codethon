#include <stdio.h>

typedef struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
}Treenode;

typedef struct tnode *Treeptr;

union {
	int ival;
	float fval;
	char* sval;
}u;

struct {
	char *name;
	int flags;
	int utype;
	union{
		int ival;
		float fval;
		char * sval;
	}u;
}symtab[100];

int main(int argc, const char *argv[])
{
	return 0;
}