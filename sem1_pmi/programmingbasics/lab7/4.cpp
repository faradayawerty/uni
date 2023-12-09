#include <cstdio>

int smallest_prime_factor(int);

int main()
{
	int n, p;
	printf("введите число: ");
	scanf("%d", &n);

	while(n > 1) {
		p = smallest_prime_factor(n);
		n /= p;
		printf("%d ", p);
	}
	printf("\n");

	return 0;
}

// n > 1
int smallest_prime_factor(int n)
{
	int i = 2;
	while(n%i != 0)
		i++;
	return i;
}

