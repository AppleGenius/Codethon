#include <iostream>

int main(int argc, const char *argv[])
{
	float p3x = 80838.0f;
	float p2y = -2499.0f;
	double v321 = p3x * p2y;

	std::cout.precision(15);
	std::cout << v321 << std::endl;

	return 0;
}