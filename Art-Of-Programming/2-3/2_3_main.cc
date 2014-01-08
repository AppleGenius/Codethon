#include <iostream>
#include <string>

void CounterSort(std::string str, std::string &help_str)
{
	int help[26] = { 0 };

	//help存放了等于index + ‘A'的元素个数
	for (int i = 0; i < str.length(); ++i)
	{
		int index = str[i] - 'a';
		help[index] ++;
	}

	//求出每个元素的最终位置
	for (int j = 1; j < 26; ++j)
	{
		help[j] += help[j - 1];
	}

	//把每个元素放到最终应该的位置上
	for (int k = str.length() - 1; k >= 0; k--)
	{
		int index = str[k] - 'a';
		int pos = help[index] - 1;
		help_str[pos] = str[k];
		help[index]--;
	}
}

void Compare(std::string longString, std::string shortString)
{
	int pos_long = 0;
	int pos_short = 0;

	while (pos_short < shortString.length() && pos_long < longString.length())
	{
		while (longString[pos_long] < shortString[pos_short] && pos_long < longString.length() - 1)
			pos_long++;

		while (shortString[pos_short] == shortString[pos_short + 1])
			pos_short++;

		if (longString[pos_long] != shortString[pos_short])
			break;

		pos_long++;
		pos_short++;
	}

	if (pos_short == shortString.length())
		std::cout << "Compare True!" << std::endl;
	else
		std::cout << "Compare False!" << std::endl;
}


int main(int argc, const char *argv[])
{
	std::string strOne = "abcdak";
	std::string strTwo = "a";
	std::string longString = strOne;
	std::string shortString = strTwo;

	CounterSort(strOne, longString);
	CounterSort(strTwo, shortString);
	Compare(longString, shortString);

	return 0;
}
