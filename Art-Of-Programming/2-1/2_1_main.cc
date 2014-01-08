#include <iostream>
#include <string>

int CompareString(std::string longString, std::string shortString)
{
	int i, j;
	for (i = 0; i < shortString.length(); ++i)
	{
		for (j = 0; j < longString.length(); ++j)
		{
			if (longString[j] == shortString[i])
			{
				break;
			}
		}

		if (j == longString.length())
		{
			std::cout << "Compare False!" << std::endl;
			return 0;
		}
	}

	std::cout << "Compare True!" << std::endl;
	return 1;
}

int main(int argc, const char * argv[])
{
	std::string longString = "abcdefg";
	std::string shortString = "abc";
	CompareString(longString, shortString);
	return 0;
}