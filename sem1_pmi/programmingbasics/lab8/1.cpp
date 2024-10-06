#include <cstdio>

void print_digits_reverse(int);
void print_digits(int);

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);

	print_digits_reverse(n);
	printf("\n");
	print_digits(n);

	return 0;
}

void print_digits_reverse(int n)
{
	printf("%d\n", n%10);
	if(n > 9)
		print_digits(n / 10);
}

void print_digits(int n)
{
	if(n > 9)
		print_digits(n / 10);
	printf("%d\n", n%10);
}

