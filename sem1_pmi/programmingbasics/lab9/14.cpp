#include <stdio.h>
#include "util.h"

void inv(int *array, int arrayLength);
void reverse(int *array, int arrayLength);
void rsh(int *array, int arrayLength, int k);
void crsh(int *array, int arrayLength, int k);
void lsh(int *array, int arrayLength, int k);
void clsh(int *array, int arrayLength, int k);
void mirrow(int *array, int arrayLength);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, 0, 9);

	puts("Вы можете выполнить следующие команды:");
	puts("\t0 - выход из программы");
	puts("\t1 - inv");
	puts("\t2 - reverse");
	puts("\t3 - rsh");
	puts("\t4 - crsh");
	puts("\t5 - lsh");
	puts("\t6 - clsh");
	puts("\t7 - mirrow");

	int cmd = 1, arg = -1;
	while(0 < cmd && cmd < 8) {
		printf("\nмассив: ");
		printarr(a, n);
		printf(">> ");
		scanf("%d", &cmd);

		if(cmd == 1)
			inv(a, n);
		else if(cmd == 2)
			reverse(a, n);
		else if(cmd == 7)
			mirrow(a, n);
		else if(2 < cmd && cmd < 7) {
			printf("k = ");
			scanf("%d", &arg);
			if(cmd == 3)
				rsh(a, n, arg);
			if(cmd == 4)
				crsh(a, n, arg);
			if(cmd == 5)
				lsh(a, n, arg);
			if(cmd == 6)
				clsh(a, n, arg);
		}

	}
	

	return 0;
}

void inv(int *a, int l)
{
	for(int i = 0; i < l; i++)
		a[i] = 9 - a[i];
}

void reverse(int *a, int l)
{
	for(int i = 1; i <= l / 2; i++)
		swap(a[i-1], a[l-i]);
}

void rsh(int *a, int l, int k)
{
	if(k >= l || k == 0)
		return;
	for(int i = l-1; i >= k; i--)
		a[i] = a[i-k];
	for(int i = 0; i < k; i++)
		a[i] = 0;
}

void lsh(int *a, int l, int k)
{
	if(k >= l || k == 0)
		return;
	for(int i = l; i > k; i--)
		a[i-1] = a[i-1-k];
	for(int i = 0; i < k; i++)
		a[i] = 0;
}

void clsh(int *a, int l, int k)
{
	if(k >= l || k == 0)
		return;
	int b[k];
	for(int i = 0; i < k; i++)
		b[i] = a[l-k+i];
	for(int i = l; i > k; i--)
		a[i-1] = a[i-1-k];
	for(int i = 0; i < k; i++)
		a[i] = b[i];
}

void crsh(int *a, int l, int k)
{
	if(k >= l || k == 0)
		return;
	int b[k];
	for(int i = 0; i < k; i++)
		b[i] = a[l-k+i];
	for(int i = l-1; i >= k; i--)
		a[i] = a[i-k];
	for(int i = 0; i < k; i++)
		a[i] = b[i];
}

void mirrow(int *a, int l)
{
	for(int i = 0; i < l / 2; i++)
		a[l-1-i] = a[i];
}

