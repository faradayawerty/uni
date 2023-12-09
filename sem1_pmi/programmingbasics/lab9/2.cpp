#include <stdio.h>
#include "util.h"

bool *changearr(int *a, int l);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, -50, 50);
	printarr(a, n);

	bool *b = changearr(a, n);
	printarr(b, n);

	return 0;
}

bool *changearr(int *a, int l)
{
	bool *b = new bool[l];
	for(int i = 0; i < l; i++)
		b[i] = a[i]%3 == 0;
	return b;
}

