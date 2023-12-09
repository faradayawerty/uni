#include <cstdio>

// возводит число в куб, используя сумму нечетных чисел
int cube(int);

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);

	printf("\t%d^3 = %d\n", n, cube(n));

	return 0;
}

int cube(int n)
{
	int s = 0;
	int a = 1 - n + n*n; // общий вид чисел 1, 3, 7, 13...

	for(int i = 0; i < n; i++) {
		s += a;
		a += 2;
	}

	return s;
}

