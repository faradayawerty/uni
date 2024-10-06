#include <cstdio>

// domain for `number` is all 4-digit positive integers
int number_of_digit(int number, int digit);

bool all_digits_different(int);

int main()
{
	for(int i = 1000; i < 10000; i++) {
		if(all_digits_different(i))
			printf("\t%d\n", i);
	}

	return 0;
}

int number_of_digit(int n, int d)
{
	int c = 0;

	for(int i = 0; i < 4; i++) {
		if(n%10 == d)
			c++;
		n /= 10;
	}

	return c;
}

bool all_digits_different(int n)
{
	bool b = true;

	for(int i = 0; i < 10; i++)
		b = b && (number_of_digit(n, i) <= 1);

	return b;
}

