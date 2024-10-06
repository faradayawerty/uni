#include <cstdio>
#include "util.h"

bool isprime(int k);
void printprimes(int *a, int l);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, 0, 50);
	printarr(a, n);

	printprimes(a, n);

	return 0;
}

bool isprime(int k)
{
	if(k < 2)
		return false;

	for(int i = 2; i*i <= k; i++) {
		if(k%i == 0)
			return false;
	}

	return true;
}

void printprimes(int *a, int l)
{
	for(int i = 0; i < l; i++) {
		if(isprime(a[i]))
			printf("\t%d", a[i]);
	}
	printf("\n");
}

