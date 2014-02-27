#include <stdio.h>
#include <limits.h>

int main(int argc, const char * argv[])
{
	/*
	printf("Size of char %d\n", CHAR_BIT);
	printf("Size of Char Max %d\n", CHAR_MAX);
	printf("Size of Char Min %d\n", CHAR_MIN);
	printf("Size of int min %d\n", INT_MIN);
	printf("Size of int max %d\n", INT_MAX);
	printf("Size of long min %ld\n", LONG_MIN);
	printf("Size of long max %ld\n", LONG_MAX);
	printf("Size of short min %d\n", SHRT_MIN);
	printf("Size of short max %d\n", SHRT_MAX);
	printf("Size of unsigned char %u\n", UCHAR_MAX);
	printf("Size of unsigned int %u\n", UINT_MAX);
	printf("Size of unsigned short %u\n", USHRT_MAX);
	printf("Size of unsigned long %lu\n", ULONG_MAX);
	*/
	printf("Size of char:\t %6d\n", sizeof(char));
	printf("Size of short:\t %6d\n", sizeof(short));
	printf("Size of int:\t %6d\n", sizeof(int));	
	printf("Size of long:\t %6d\n", sizeof(long));
	printf("Size of long long:\t %6d\n", sizeof(long long));
	printf("Size of float:\t %6d\n", sizeof(float));
	printf("Size of double:\t %6d\n", sizeof(double));
	printf("Size of long double:\t %6d\n", sizeof(long double));
	printf("Size of int*:\t %6d\n", sizeof(int*));
	printf("Size of double*:\t %6d\n", sizeof(double*));

	return 0;


}