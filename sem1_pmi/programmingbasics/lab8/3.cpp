#include <cstdio>

int a(int);

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);

	printf("\t%d\n", a(n));

	return 0;
}


int a(int n)
{
	if(n == 0)
		return 2;
	if(n == 1)
		return -1;
	return -a(n-1) * a(n-2);
}

