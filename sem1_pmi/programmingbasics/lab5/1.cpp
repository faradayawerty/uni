#include <iostream>

bool has_digit(int number, int digit);

int main()
{
	int N;
	std::cout << "хочу число: " << std::endl;
	std::cin >> N;

	for(int i = 10; i < 100; i++) {
		if(has_digit(i, N) || i % N == 0)
			std::cout << i << std::endl;
	}
	
	return 0;
}

bool has_digit(int n, int d)
{
	for(;n > 0; n /= 10) {
		if(n%10 == d)
			return true;
	}

	return false;
}

