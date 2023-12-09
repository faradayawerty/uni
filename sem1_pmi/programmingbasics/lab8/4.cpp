#include <cstdio>

int a(int);
int b(int);

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);

	printf("\t%d\n", b(n));

	return 0;
}

int a(int n)
{
	if(n == 0)
		return 1;
	return 2*a(n-1)-b(n-1);
}

int b(int n)
{
	if(n == 0)
		return 0;
	return a(n)+2*b(n-1);
}

