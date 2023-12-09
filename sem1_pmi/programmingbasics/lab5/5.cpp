#include <iostream>

int digit_sum(int);

int main()
{
	for(int i = 10; i < 100; i++) {
		if(digit_sum(i) + digit_sum(i)*digit_sum(i) == i)
			std::cout << i << std::endl;
	}

	return 0;
}

int digit_sum(int n)
{
	if (n % 10 == n) {
		return n;
	}

	return n%10 + digit_sum(n/10);
}

