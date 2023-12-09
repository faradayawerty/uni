#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_VAL 32

void sort(int* arr, int len);
void genarr(int* arr, int len, int min, int max);
void print_arr(int *arr, int len);

int main()
{
	int len = 24;
	int* arr = (int*)calloc(sizeof(int), len);

	genarr(arr, len, 0, MAX_VAL);
	print_arr(arr, len);

	sort(arr, len);
	print_arr(arr, len);

	return 0;
}

void sort(int* arr, int len)
{
	int* b = (int*)calloc(sizeof(int), MAX_VAL+1);
	for(int i = 0; i < len; i++)
		b[arr[i]]++;
	for(int i = 0, index = 0; i <= MAX_VAL; i++)
		for(int j = 0; j < b[i]; j++)
			arr[index++] = i;
}

void genarr(int* arr, int len, int min, int max)
{
	srand(time(NULL));
	for(int i = 0; i < len; i++)
		arr[i] = rand() % (max - min + 1) + min;
}

void print_arr(int *arr, int len)
{
	for(int i = 0; i < len; i++)
		printf("%3d ", arr[i]);
	putchar('\n');
}

