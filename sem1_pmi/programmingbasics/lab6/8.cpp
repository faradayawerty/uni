#include <cstdio>

int divisor_sum(int);
bool are_friendly(int, int);

int main()
{
	int n, m;
	printf("введите два целых числа, разделенных пробелами: ");
	scanf("%d %d", &n, &m);

	for(int i = n; i <= m; i++)
	for(int j = n; j <= i; j++) {
		if(are_friendly(i, j) && i != j)
			printf("\t%d\t%d\n", i, j);
	}

	return 0;
}

bool are_friendly(int a, int b) 
{
	return (divisor_sum(a) == b) && (a == divisor_sum(b));
}

int divisor_sum(int n)
{
	int s = 0;

	for(int i = 1; i < n; i++) {
		if(n%i == 0)
			s += i;
	}

	return s;
}

