#include <cstdio>

int gcd(int a, int b)
{
	while (a != b) {
		if(a > b) {
			a = a - b;
		} else if (a < b) {
			b = b - a;
		}
	}
	return a;
}

int main()
{
	unsigned int m, n;
	printf("enter two positive integers separated by spaces: ");
	scanf("%d %d", &m, &n);

	unsigned int gcdmn = gcd(m, n);
	unsigned int p = m / gcdmn;
	unsigned int q = n / gcdmn;

	printf("%d/%d = %d/%d\n", m, n, p, q);

	return 0;
}

