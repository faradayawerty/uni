#include <cstdio>
#include <cstdlib>
#include <ctime>

void printarr(bool *a, int l)
{
	for(int i = 0; i < l; i++)
		printf(a[i] ? "\ttrue " : "\tfalse");
	printf("\n");
}

void printarr(int *a, int l)
{
	for(int i = 0; i < l; i++)
		printf("\t%d", a[i]);
	printf("\n");
}

void initarr(int *a, int l)
{
	for(int i = 0; i < l; i++)
		a[i] = 0;
}
void rndarr(int *a, int l, int min, int max)
{
	srand(time(0));
	for(int i = 0; i < l; i++)
		a[i] = rand() % (max-min+1) + min;
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

