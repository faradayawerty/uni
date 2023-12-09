#include <cstdio>

int main()
{
	int x;
	printf("number: ");
	scanf("%d", &x);

	while (x > 9)
		x /= 10;
	printf("%d\n", x);

	return 0;
}

