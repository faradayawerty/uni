#include <iostream>

// returns sum for digit squares
int digit_squares_sum(int);

int main()
{
	for(int i = 10; i < 100; i++) {
		if(digit_squares_sum(i) % 13 == 0)
			std::cout << i << std::endl;
	}

	return 0;
}

int digit_squares_sum(int n)
{
	int s = 0;

	for(; n > 0; n /= 10) {
		s += (n % 10) * (n % 10);
	}

	return s;
}
