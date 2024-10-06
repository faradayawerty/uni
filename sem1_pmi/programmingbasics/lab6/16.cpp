#include <cstdio>

// moves all `digit` to the end of `number`
int move_digit_to_the_end(int number, int digit);

int count_zeros(int);
int put_zeros_after_first_digit(int number, int number_of_zeros);

int main()
{
	int n;
	printf("введите число: ");
	scanf("%d", &n);

	int number_of_zeros = count_zeros(n);
	for(int i = 0; i < 10; i++)
		n = move_digit_to_the_end(n, i);
	n = put_zeros_after_first_digit(n, number_of_zeros);

	printf("%d\n", n);

	return 0;
}

int move_digit_to_the_end(int n, int d)
{
	int m = 0;
	int om = 1; // record the order of `m` (i.e. 1, 10, 100...)

	for(;n > 0; n /= 10) {
		if(n%10 == d)
			m = m*10 + n%10;
		else
			m = n%10 * om + m;
		om *= 10;
	}

	return m;
}

int count_zeros(int n)
{
	int c = 0;
	for(;n > 0; n /= 10)
		if(n%10 == 0)
			c++;
	return c;
}

int put_zeros_after_first_digit(int n, int z)
{
	int m = 0;
	int om = 1; // record the order of `m` (i.e. 1, 10, 100...)

	for(;n >= 10; n /= 10) {
		m = n%10 * om + m;
		om *= 10;
	}

	for(;z > 0; z--)
		om *= 10;
	m = n%10 * om + m;

	return m;
}

