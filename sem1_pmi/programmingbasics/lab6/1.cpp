#include <cstdio>

int digit_sum(int);
int digital_root(int);

int main()
{
	int x;
	printf("введите число: ");
	scanf("%d", &x);
	printf("%d\n", digital_root(x));

	return 0;
}

int digital_root(int n)
{
	while(n > 9)
		n = digit_sum(n);
	return n;
}

int digit_sum(int n)
{
	int s = 0;
	for(;n > 0; n /= 10) {
		s += n%10;
	}
	return s;
}

