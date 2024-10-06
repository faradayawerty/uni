#include <stdio.h>
#include <stdlib.h>
#include "util.h"

#define SUCCESS 0
#define ERROR_NO_NUMBER 1
#define ERROR_NO_NUMBERS_AFTER 2

int getp(int *a, int l, int &p);

int main()
{
	int n; printf("n = "); scanf("%d", &n); int a[n];
	rndarr(a, n, -50, 50);
	printarr(a, n);

	int p;
	int err = getp(a, n, p);
	if(err == SUCCESS)
		printf("p = %d\n", p);
	else if(err == ERROR_NO_NUMBER)
		printf("в массиве нет отрицательных элементов заканчивающихся на 3\n");
	else if(err == ERROR_NO_NUMBERS_AFTER)
		printf("после отрицательного элемента заканчивающегося на 3 нет других чисел\n");

	return 0;
}

int getp(int *a, int l, int &p)
{
	int i = l-1;
	while(i >= 0 && (a[i] >= 0 || abs(a[i]) % 10 != 3)) i--;

	if(i < 0)
		return ERROR_NO_NUMBER;
	if(i >= l-1)
		return ERROR_NO_NUMBERS_AFTER;

	p = 1;
	for(i++; i < l; i++)
		p *= a[i];

	return SUCCESS;
}

