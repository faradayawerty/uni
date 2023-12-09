#include <stdio.h>
#include "util.h"

void changearr(int *a, int l);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, -50, 50);
	printarr(a, n);

	changearr(a, n);
	printarr(a, n);

	return 0;
}

void changearr(int *a, int l)
{
	for(int i = 0; i < l; i++) {
		if(a[i] < 0 && i%2 == 0)
			a[i] += i;
	}
}

