#include <cstdio>

int digit_sum(int);

int main()
{
	int n, a;
	printf("N = ");
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		printf("$ ");
		scanf("%d", &a);
		if(digit_sum(a) > 5)
			printf("\t%d\n", a);
	}

	return 0;
}

int digit_sum(int n)
{
	int s = 0;
	for(;n > 0; n /= 10)
		s += n%10;
	return s;
}

