/*
* ���������	20��Ϊf���ó�ʼֵΪ0����f�ṹ�ĳ�Ա��һ��ָ�룬���f.pָ����NULL����һ����ָ��ṹ�ĳ�Ա��f.p->s)�᷵��һ����0��ֵ��
*			��Ҳ��Ϊ��22�л�Ϊ�棬��23����ͼ���������ָ��ָ��Ľṹ�ĳ�Աʱ���ͻ�core��
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