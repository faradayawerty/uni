#include <cstdio>

int nonzero_binary_even_positions(int);

int main()
{
	int n;
	printf("введите число: ");
	scanf("%d", &n);

	printf("%d\n", nonzero_binary_even_positions(n));

	return 0;
}

int nonzero_binary_even_positions(int n)
{
	bool pass = false;
	int c = 0;

	while(n > 0) {
		if(n & 0x01 == 1 && !pass)
			c++;

		n = n >> 1;
		pass = !pass;
	}

	return c;
}

