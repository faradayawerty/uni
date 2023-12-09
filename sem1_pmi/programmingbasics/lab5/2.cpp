#include <iostream>

int digit_sum(int number);

int main()
{
	int N;
	std::cin >> N;

	// # of three digit numbers with digit sum `N`
	int count = 0;

	for(int i = 100; i < 1000; i++) {
		if(digit_sum(i) == N)
			count++;
	}

	std::cout << count << std::endl;

	return 0;
}

int digit_sum(int n)
{
	if (n % 10 == n) {
		return n;
	}

	return n%10 + digit_sum(n/10);
}

