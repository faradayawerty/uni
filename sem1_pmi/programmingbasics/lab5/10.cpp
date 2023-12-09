#include <iostream>

int digit_sum(int);

int main()
{
	for(int i = 105; i < 1000; i += 7)
		if(digit_sum(i) % 7 == 0)
			std::cout << i << ' ';
	std::cout << std::endl;

	return 0;
}

int digit_sum(int n)
{
	if (n < 10) {
		return n;
	}

	return n%10 + digit_sum(n/10);
}

