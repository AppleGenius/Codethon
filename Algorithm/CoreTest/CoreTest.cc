/*
* 代码分析：	20行为f设置初始值为0，而f结构的成员是一个指针，结果f.p指向了NULL，而一个空指针结构的成员（f.p->s)会返回一个非0的值，
*			这也是为何22行会为真，而23行试图访问这个空指针指向的结构的成员时，就会core。
*/


#include <stdio.h>

struct str{
	int len;
	char s[0];
};

struct foo{
	struct str *p;
};

int main(int argc, const char *argv[])
{
	struct foo f = { 0 };

	if (f.p->s){
		printf(f.p->s);
	}

	return 0;
}