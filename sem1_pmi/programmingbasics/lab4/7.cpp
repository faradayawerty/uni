#include <cstdio>
#include <cmath>

#define PHI (1+sqrt(5))/2

// returns nth fibonacci number
int f(int n)
{
	// rounding with floor(decimal + 0.5)
	return (int)floor(pow(PHI, n) / sqrt(5) + 0.5);
}

// returns the first fibonacci number greater than m
// NOTE: faster than `f` in while loop
int fibg(int m)
{
	int a = 0, b = 1, t;
	while(a <= m) {
		t = b;
		b = a + b;
		a = t;
	}

	return a;
}

int main()
{
	// a
	printf("%d\n", f(40));

	// b
	int m;
	printf("m = ");
	scanf("%d", &m);
	printf("%d\n", fibg(m));

	// c
	// using the formula: f(1) + f(2) + f(3) + ... + f(n) = f(n+2) - f(2)
	// and considering that f(15) = 610, f(16) = 987
	// we see that the sum `s` of fibonacci numbers <= 1000 is equal to the following
	int s = f(18) - f(2);
	printf("%d\n", s);
}

