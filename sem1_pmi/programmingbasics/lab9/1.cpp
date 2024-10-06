#include <stdio.h>
#include "util.h"

int *changearr(int *a, int l);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, -50, 50);
	printarr(a, n);

	int *b = changearr(a, n);
	printarr(b, n);

	return 0;
}

int *changearr(int *a, int l)
{
	int *b = new int[l];
	for(int i = 0; i < l; i++)
		b[i] = a[i]*a[i] + 2*a[i] - 1;
	return b;
}
