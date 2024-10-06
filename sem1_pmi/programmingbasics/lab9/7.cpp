#include <cstdio>
#include "util.h"

int lastdivi(int *a, int l, int d);
void plastdivi(int *a, int l, int d);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, -50, 50);
	printarr(a, n);

	plastdivi(a, n, 7);

	return 0;
}

int lastdivi(int *a, int l, int d)
{
	int lasti = -1;
	for(int i = 0; i < l; i++) {
		if(a[i]%d == 0)
			lasti = i;
	}

	return lasti;
}

void plastdivi(int *a, int l, int d)
{
	int i = lastdivi(a, l, d);
	if(i < 0)
		printf("чисел, делящихся на %d, нет\n", d);
	else
		printf("\t%d\n", i);
}

