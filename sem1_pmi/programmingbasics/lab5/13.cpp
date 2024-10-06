#include <iostream>

int double_fact(int);

int main()
{
	int n;
	std::cin >> n;
	std::cout << double_fact(n) << std::endl;

	return 0;
}

int double_fact(int n)
{
	int p = 1;
	for(int i = n; i > 0; i -= 2) {
		p *= i;
	}
	return p;
}

