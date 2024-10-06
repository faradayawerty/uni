#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sort(int* arr, int len);
void genarr(int* arr, int len, int min, int max);
void print_arr(int *arr, int len);

int main()
{
	int len = 24;
	int* arr = (int*)calloc(sizeof(int), len);

	genarr(arr, len, 0, 32);
	print_arr(arr, len);

	sort(arr, len);
	print_arr(arr, len);

	return 0;
}

void sort(int* arr, int len)
{
	int* evens = (int*)calloc(sizeof(int), len);
	int* odds = (int*)calloc(sizeof(int), len);
	int num_even = 0, num_odd = 0;

	for(int i = 0; i < len; i++)
		if(arr[i] % 2 == 0)
			evens[num_even++] = arr[i];
		else
			odds[num_odd++] = arr[i];
	for(int i = 0; i < num_even; i++)
		arr[i] = evens[i];
	for(int i = 0; i < num_odd; i++)
		arr[num_even + i] = odds[i];
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

