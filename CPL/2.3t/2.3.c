#include <stdio.h>
#include <stdlib.h>

int hexalpha_to_int(int c);
unsigned int htoi(const char s[]);
void strcat(char s[], char t[]);


int main(int argc, const char *argv)
{
	char *endp = NULL;
	char *test[] =
	{
		"F00",
		"bar",
		"0100",
		"0x1",
		"0xa",
		"0x0C0BE",
		"0x123465",
		"zong_c"
	};

	unsigned int result, check;

	size_t  numtests = sizeof test / sizeof test[0];
	size_t thistest;

	for (thistest = 0; thistest < numtests; thistest++)
	{
		result = htoi(test[thistest]);
		check = (unsigned int)strtoul(test[thistest], &endp, 16);

		if ((*endp != '\0' && result == 0) || result == check)
		{
			printf("Testing %s Correct %u \n", test[thistest], result);
		}
		else
		{
			printf("Testing %s InCorrect %u \n", test[thistest], result);
		}
	}

	char des[20];
	char s[] = "123456789";
	char t[] = "987654321";

	for (int k = 0; k < 20; ++k)
		des[k] = 'a';

	strcat(des, s);
	strcat(des, t);
	printf("%s", des);

	return 0;
}



int hexalpha_to_int(int c)
{
	char hexalpha[] = "aAbBcCdDeEfF";
	int answer = 0;

	for (int i = 0; answer == 0 && hexalpha[i] != '\0'; ++i)
	{
		if (hexalpha[i] == c)
		{
			answer = 10 + (i / 2);
		}
	}

	return answer;
}

unsigned int htoi(const char s[])
{
	unsigned int answer = 0;
	int i = 0, valid = 1, hexit;

	if (s[i] == '0')
	{
		i++;
		if (s[i] == 'x' || s[i] == 'X')
		{
			i++;
		}
	}

	while (valid && s[i] != '\0')
	{
		answer *= 16;
		if (s[i] >= '0' && s[i] <= '9')
		{
			answer += (s[i] - '0');
		}
		else
		{
			hexit = hexalpha_to_int(s[i]);
			if (hexit == 0)
			{
				valid = 0;
			}
			else
			{
				answer += hexit;
			}
		}
		++i;
	}

	if (!valid)
	{
		answer = 0;
	}

	return answer;
}

void strcat(char s[], char t[])
{
	int i = 0, j = 0;
	
	while (s[i++] != '\0');
	while ((s[i++] == t[j++]) != '\0');

}

