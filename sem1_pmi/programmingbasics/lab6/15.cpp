#include <cstdio>

int gcd(int, int);

int main()
{
	for(int i = 1; i <= 7; i++)
	for(int j = 1; j <= i; j++)
	{
			if(gcd(i, j) == 1 && i != j)
				printf("%d/%d\n", j, i);
	}

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

