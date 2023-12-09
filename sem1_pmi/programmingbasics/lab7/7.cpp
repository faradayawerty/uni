#include <cstdio>

void swap(int&, int&);

int main()
{
	int a = 228, b = 1337;

	swap(a, b);
	printf("%d %d\n", a, b);

	return 0;
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

