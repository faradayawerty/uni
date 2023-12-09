#include <cstdio>

int gcd(int, int);

int main()
{
	int m, n, d = 0;
	printf("m = ");
	scanf("%d", &m);

	for(int i = 0; i < m; i++) {
		printf("n%d = ", i+1);
		scanf("%d", &n);

		d = gcd(n, d);
	}

	printf("%d\n", d);

	return 0;
}

int gcd(int a, int b)
{
	while(a != 0 && b != 0) {
		if(a > b)
			a = a % b;
		else
			b = b % a;
	}

	return a + b;
}

