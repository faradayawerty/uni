#include <cstdio>

int get_digit(int number, int position);
int number_of_digits(int);

int main()
{
	// a
	int k, x = 0, n = 0;
	printf("k = ");
	scanf("%d", &k);

	while(k > x) {
		n++;
		x += number_of_digits(n);
	}
	printf("%d\n", get_digit(n, x - k));


	// b
	n = 0;
	x = 0;
	while(k > x) {
		n++;
		x += number_of_digits(n*n);
	}
	printf("%d\n", get_digit(n*n, x - k));


	// c
	int a = 0, b = 1, c;
	x = 0;
	while(k > x) {
		c = a;
		a = a + b;
		b = c;
		
		x += number_of_digits(a);
	}
	printf("%d\n", get_digit(a, x - k));


	return 0;
}

int number_of_digits(int x)
{
	int n = 1;

	while(x / 10 > 0) {
		x /= 10;
		n++;
	}

	return n;
}

int get_digit(int n, int i)
{
	int j = 0;
	while(j < i) {
		n /= 10;
		j++;
	}
	return n%10;
}

