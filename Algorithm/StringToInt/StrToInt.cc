/*
*  ��Ŀ�� ��һ���ַ���ת��Ϊ����
*  Ҫ�㣺	1. ���ǵ������ֺ�������
			2. ���ǵ��������������С�ĸ��������������
			3. ��������ַ�������ת��Ϊ����ʱ��Ӧ������δ���
			4. ����³�������⣨��������Ϊ��ָ��ʱ��
*/
#include <stdio.h>

int StrToInt(char * string);

int main(int argc, const char *argv[])
{	
	char string[] = "123456";

	printf("%d\n", StrToInt(string));
	return 0;
}

int StrToInt(char *string)
{
	if (string == NULL){
		printf("Input Error!\n");
		return NULL;
	}
	int number = 0;

	while (*string != '\0'){
		number = number * 10 + (*string - '0');
		string++;
	}

	return number;
		
}