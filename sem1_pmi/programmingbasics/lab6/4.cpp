#include <cstdio>

bool is_perfect(int);
int divisor_sum(int);

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);
	
	for(int i = 1; i < n; i++) {
		if(is_perfect(i))
			printf("\t%d\n", i);
	}

	return 0;
}

bool is_perfect(int n)
{
	return 2*n == divisor_sum(n);
}

int divisor_sum(int n)
{
	int s = 0;

	for(int i = 1; i <= n; i++) {
		if(n%i == 0)
			s += i;
	}

	return s;
}

