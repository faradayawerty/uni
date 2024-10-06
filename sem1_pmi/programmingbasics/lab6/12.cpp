#include <cstdio>

int main()
{
	int n;
	printf("введите число: ");
	scanf("%d", &n);

	while(n > 1) {
		int i = 2;
		while(n%i != 0)
			i++;

		printf("%d ", i);
		n /= i;
	}

	printf("\n");

	return 0;
}

