#include <cstdio>

int max_digit(int);

int main()
{
	int a, b;
	printf("введите два числа разделенных пробелом: ");
	scanf("%d %d", &a, &b);

	for(int i = a; i <= b; i++) {
		if(i % max_digit(i) == 0)
			printf("%d\n", i);
	}

	return 0;
}

int max_digit(int n)
{
	int maxd = -1;
	for(;n > 0; n /= 10) {
		if(maxd < n%10)
			maxd = n%10;
	}
	return maxd;
}

