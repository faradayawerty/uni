#include <cstdio>
#include <ctime>
#include <cstdlib>

int *inputArr(int l)
{
	int *a = new int[l];
	for(int i = 0; i < l; i++) {
		printf("new element: ");
		scanf("%d", &a[i]);
	}
	return a;
}

int *randArr(int l, int min, int max)
{
	int *a = new int[l];
	srand(time(0));
	for(int i = 0; i < l; i++)
		a[i] = rand() % (max - min + 1) + min;
	return a;
}

void printArr(int *a, int l)
{
	for(int i = 0; i < l; i++)
		printf("%d", a[i]);
}

int findIndex(int *a, int l, int x)
{
	for(int i = 0; i < l; i++) {
		if(a[i] == x)
			return i;
	}

	return -1;
}

