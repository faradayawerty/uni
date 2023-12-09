#include <cstdio>
#include "util.h"

void insert(int *a, int l, int t);

int main()
{
	int n; printf("n = "); scanf("%d", &n);
	int a[n]; initarr(a, n);
	int t;

	for(int i = 0; i < n; i++) {
		printf("новый элемент: "); scanf("%d", &t);
		insert(a, i, t);
		printarr(a, n);
	}
}

void insert(int *a, int l, int t)
{
	int i = 0;
	while(a[i] < t && i < l) i++;
	for(int j = l; j >= i; j--)
		a[j] = a[j-1];
	a[i] = t;
}

