#include <cstdio>

int digital_root(int);
int digit_sum(int);

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);

	printf("\t%d\n", digital_root(n));

	return 0;
}

int digital_root(int n)
{
	if(n < 10)
		return n;
	return digital_root(digit_sum(n));
}

int digit_sum(int n)
{
	if(n < 10)
		return n;
	return digit_sum(n/10) + n%10;
}

