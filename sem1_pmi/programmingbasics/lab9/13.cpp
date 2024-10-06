#include <stdio.h>
#include "util.h"

int posneigh(int *a, int l);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, -50, 50);
	printarr(a, n);

	int i = posneigh(a, n);
	if(i < 0)
		printf("двух соседних положительных элементов в массиве НЕТ\n");
	else
		printf("%d %d\n", a[i], a[i+1]);

	return 0;
}

int posneigh(int *a, int l)
{
	for(int i = 0; i < l-1; i++) {
		if(a[i] > 0 && a[i+1] > 0)
			return i;
	}

	return -1;
}

