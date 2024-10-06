#include <cstdio>

int main()
{
	for(int u = 1; u < 20; u += 2)
	for(int v = 1; v < u; v += 2)
	{
		printf("(%d %d %d)\n", u*v, (u*u - v*v)/2, (u*u + v*v)/2);
	}

	return 0;
}

