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
    int x, y;
    printf("enter two numbers separated by space:\n$ ");
    scanf("%d %d", &x, &y);
    
    printf("numbers %d and %d are %srelatively primes\n", x, y, gcd(x, y) == 1 ? "" : "not ");

	return 0;
}

