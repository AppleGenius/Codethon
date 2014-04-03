/*
*  题目： 将一个字符串转换为整数
*  要点：	1. 考虑到非数字和正负号
			2. 考虑到最大正整数和最小的负整数溢出的问题
			3. 当输入的字符串不能转换为整数时，应该做如何处理
			4. 程序鲁棒性问题（例如输入为空指针时）
*/
#include <stdio.h>

int StrToInt(char * str);
int StrToInt2(char *str);

int main(int argc, const char *argv[])
{	
	char string[] = "123456";

	printf("%d\n", StrToInt2(string));
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


int StrToInt2(char *str)
{
	if (str == NULL)
		return NULL;
	
	int result = 0;
	while (*str != '\0'){
		result = result * 10 + (*str - '0');
		str++;
	}

	return result;
}


////////////////////////////////////// F2 ////////////////////////////////////////////////