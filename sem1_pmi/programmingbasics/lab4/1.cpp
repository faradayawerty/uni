#include <cstdio>

// return digit sum of the argument
int ds(int n)
{
	int s = 0;
	while(n != 0) {
		s += n%10;
		n/=10;
	}

	return s;
}

int main()
{
	int x;
	printf("number: ");
	scanf("%d", &x);
	printf("%d\n", ds(x));

	return 0;
}

