#include <iostream>
#include <string>

//质数数组
int PrimerNumber[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };

int main(int argc, const char *argv[])
{
	std::string strOne = "ABCDEFG";
	std::string strTwo = "ACBAA";

	long product = 1;	//真实代码中需要一个足以容纳所有乘积的大数

	for (int i = 0; i < strOne.length(); ++i)
	{
		int index = strOne[i] - 'A';
		product *= PrimerNumber[index];
	}

	int j;

	for (j = 0; j < strTwo.length(); ++j)
	{
		int index = strTwo[j] - 'A';

		if (product % PrimerNumber[index] != 0)
		{
			break;
		}
	}

	if (strTwo.length() == j)
		std::cout << "Compare True!" << std::endl;
	else
		std::cout << "Compare False!" << std::endl;

	return 0;
}