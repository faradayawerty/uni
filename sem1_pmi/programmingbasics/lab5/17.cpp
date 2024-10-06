#include <cstdio>

// domain for `number` is all 4-digit positive integers
int number_of_digit(int number, int digit);

bool has_three_identical_digits(int);

int main()
{
	unsigned int n, k;
	printf("Enter two 4-digit numbers separated by spaces: ");
	scanf("%d %d", &n, &k);

	for(int i = n; i <= k; i++) {
		if(has_three_identical_digits(i))
			printf("\t%04d\n", i);
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

bool has_three_identical_digits(int n)
{
	bool b = false;

	for(int i = 0; i < 10; i++)
		b = b || (number_of_digit(n, i) == 3);

	return b;
}

