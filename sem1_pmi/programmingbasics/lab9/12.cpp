#include <stdio.h>
#include "util.h"

int sum(int *a, int i, int j);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, -50, 50);
	printarr(a, n);

	int k1; printf("k1 = "); scanf("%d", &k1); 
	int k2; printf("k2 = "); scanf("%d", &k2); 

	if(k1 >= k2) {
		printf("k1 должно быть больше чем k2");
		return 1;
	}

	if(k1 >= n || k2>= n) {
		printf("k1 и k2 должны попадать в рамки массива");
		return 1;
	}

	printf("сумма элементов с %d-ый по %d-ый равна %d\n", k1, k2, sum(a, k1, k2));

	return 0;
}

int sum(int *a, int i, int j)
{
	int s = 0;
	for(; i <= j; i++)
		s += a[i];
	return s;
}

