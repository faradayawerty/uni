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

int lcm(int a, int b)
{
	// gcd is never zero
	return a*b / gcd(a, b);
}

int main()
{
	int x, y;
	printf("enter two numbers separated by space:\n$ ");
	scanf("%d %d", &x, &y);

	printf("%d\n", lcm(x, y));

	return 0;
}

