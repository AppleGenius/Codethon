#include <iostream>
#include <string>

int Partition(std::string &str, int lo, int hi)
{
	int key = str[hi];
	int i = lo - 1;

	for (int j = lo; j < hi; j++)
	{
		if (str[j] <= key)
		{
			i++;
			swap(str[i], str[j]);
		}
	}

	swap(str[i + 1], str[hi]);
	return i + 1;
}

void QuickSort(std::string &str, int lo, int hi)
{
	if (lo < hi)
	{
		int k = Partition(str, lo, hi);
		QuickSort(str, lo, k - 1);
		QuickSort(str, k + 1, hi);
	}
}


void CompareString(std::string str1, std::string str2)
{
	int posOne = 0;
	int posTwo = 0;

	while (posTwo < str2.length() && posOne < str1.length())
	{
		while (str1[posOne] < str2[posTwo] && posOne < str1.length() - 1)
			posOne++;

		if (str1[posOne] != str2[posTwo])
		{
			break;
		}

		posTwo++;
	}


	if (posTwo == str2.length())
	{
		std::cout << "Compare True!" << std::endl;
	}
	else
	{
		std::cout << "Compare False!" << std::endl;
	}
}



int main(int argc, const char * argv[])
{
	std::string str1 = "abcdefghijk";
	std::string str2 = "abc";

	QuickSort(str1, 0, str1.length() - 1);
	QuickSort(str2, 0, str2.length() - 1);
	CompareString(str1, str2);
	return 0;
}