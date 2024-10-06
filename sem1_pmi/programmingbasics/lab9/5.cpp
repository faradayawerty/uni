#include <stdio.h>
#include "util.h"

void inittable(int *a, int w, int h);
void printastable(int *a, int w, int h);

int main()
{
	int w = 10, h = 10; int a[w*h];
	inittable(a, w, h);
	printastable(a, w, h);

	return 0;
}

void inittable(int *a, int w, int h)
{
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++)
			a[j + w*i] = (i+1)*(j+1);
	}
}

void printastable(int *a, int w, int h)
{
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++)
			printf("\t%d", a[j + w*i]);
		printf("\n");
	}
}

