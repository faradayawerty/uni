#include <cstdio>

int divsum(int n) {
	int s = 0;
	int i = 1.;
	while(i < n) {
		if (n % i == 0)
			s += i;
		i++;
	}
	return s;
}

int main()
{
	int x;
	printf("number: ");
	scanf("%d", &x);
	printf("the number %d is %s\n", x, divsum(x) == x ? "perfect" : "not perfect");

	return 0;
}

