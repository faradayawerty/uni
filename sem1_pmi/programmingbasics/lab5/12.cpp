#include <iostream>

int main()
{
	unsigned int n;
	std::cin >> n;

	std::cout << n << "^2" << " = 1";

	for(int i = 1; i < n; i++)
		std::cout << " + " << 2*i+1;
	std::cout << std::endl;

	return 0;
}

