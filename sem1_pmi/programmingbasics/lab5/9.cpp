#include <iostream>

int main()
{
	int x;
	for(x = 100; x % 100 * 7 != x; x++);
	std::cout << x << std::endl;

	return 0;
}

