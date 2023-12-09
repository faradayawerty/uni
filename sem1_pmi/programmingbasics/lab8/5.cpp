#include <cstdio>

int ack(int n, int m);

int main()
{

	printf("%d\n", ack(2, 3));

	return 0;
}

int ack(int m, int n)
{
	printf("%d %d\n", n, m);

	if(m == 0)
		return n+1;
	else if(n == 0)
		return ack(m-1, 1);
	return ack(m-1, ack(m, n-1));
}

