#include <iostream>

int flip(int number, int digit_number);
long int power(int number, int exponent);

int main()
{
	int x;
	std::cin >> x;

	if(x == flip(x, 4))
		std::cout << x << " is a palindrome" << std::endl;
	else
		std::cout << x << " is NOT a palindrome" << std::endl;

	return 0;
}

int flip(int n, int dn)
{
	int m = 0;
	for(int i = 0; i < dn; i++) {
		m = m*10 + n%10;
		n = n / 10;
	}
	return m;
}

long int power(int n, int p)
{
	long int result = 1;

	for(int i = 0; i < p; i++) {
		result *= n;
	}

	return result;
}

