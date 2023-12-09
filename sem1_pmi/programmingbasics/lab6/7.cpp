#include <cstdio>

int divisors(int);

int main()
{
	int a, b;
	printf("введите два целых числа, разделенных пробелами: ");
	scanf("%d %d", &a, &b);

	for(int i = a; i <= b; i++) {
		if(divisors(i) == 2)
			printf("\t%d\n", i);
	}

	return 0;
}

int divisors(int n)
{
	int d = 0;
	for(int i = 1; i <= n; i++)
		if(n % i == 0)
			d++;
	return d;
}

