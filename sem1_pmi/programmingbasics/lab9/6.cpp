#include <cstdio>
#include "util.h"

bool findnegs(int *a, int l);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, -50, 50);
	printarr(a, n);

	if(!findnegs(a, n))
		printf("отрицательных чисел нет\n");

	return 0;
}

bool findnegs(int *a, int l)
{
	bool found = false;
	for(int i = 0; i < l; i++) {
		if(a[i] < 0) {
			printf("\t%d", i);
			found = true;
		}
	}

	if(found)
		printf("\n");

	return found;
}

