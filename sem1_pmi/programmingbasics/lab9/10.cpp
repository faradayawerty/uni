#include <stdio.h>
#include "util.h"

bool getp(int *arr, int l, int a, int b, int &p);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, -50, 50);
	printarr(a, n);

	int A; printf("A = "); scanf("%d", &A); 
	int B; printf("B = "); scanf("%d", &B); 

	int p;
	if(getp(a, n, A, B, p))
		printf("p = %d\n", p);
	else
		printf("чисел между %d и %d нет\n", A, B);

	return 0;
}

bool getp(int *arr, int l, int A, int B, int &p)
{
	bool b = false;
	p = 1;
	for(int i = 0; i < l; i++) {
		if(A <= arr[i] && arr[i] <= B) {
			p *= arr[i];
			b = true;
		}
	}

	return b;
}

