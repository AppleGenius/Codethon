#include <iostream>
#include <string>

int main(int argc, const char *argv[])
{
	std::string str1 = "AVCDEFGHIJKLMNOPQRS";
	std::string str2 = "DZ";

	int hash[26] = {0};
	int num = 0;

	for (int j = 0; j < str2.length(); ++j)
	{
		int index = str1[j] - 'A';
		if (hash[index] == 0)				
		{
			hash[index] = 1;
			num ++;
		}
	}

	for (int k = 0; k < str1.length(); ++k)
	{
		int index = str1[k] - 'A';
		if (hash[index] == 1)
		{
			hash[index] = 0;
			num --;
			if (num == 0)
			{
				break;
			}
		}
	}

	if (num == 0)
		std::cout << "Compare True!" << std::endl;
	else
		std::cout << "Compare False!" << std::endl;
	return 0;
}