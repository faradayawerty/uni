#include <cstdio>

#define INTERVAL_BEGIN 1
#define INTERVAL_END 10

int main()
{
	for(int i = INTERVAL_BEGIN; i <= INTERVAL_END; i++)
	for(int j = INTERVAL_BEGIN; j <= i; j++)
	for(int k = INTERVAL_BEGIN; k <= INTERVAL_END; k++)
		if(i*i + j*j == k*k)
			printf("%d^2 + %d^2 = %d^2\n", i, j, k);

	return 0;
}
