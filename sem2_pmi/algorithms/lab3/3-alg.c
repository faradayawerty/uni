#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define FILENAME "string.txt"
#define SIZE 20

void selection_sort(long long *arr, long long len); // 1
void bubble_sort(long long *arr, long long len); // 2
void better_bubble_sort(long long *arr, long long len); // 3
void shaker_sort(long long *arr, long long len); // 4
void insertion_sort(long long *arr, long long len); // 5
void better_insertion_sort(long long *arr, long long len); // 6
void merge_sort(long long *arr, long long istart, long long istop); // 7
void quick_sort(long long *arr, long long istart, long long istop); // 8

void swap(long long *a, long long *b);
void randarr(long long *arr, long long len, long long min, long long max);
void genarr(long long *arr, long long len, long long first_element, long long increment);
void print_arr(long long *arr, long long len);
void write_arr_to_file(long long *arr, long long len, FILE *f);

int main()
{
	long long *arr = (long long*)malloc(sizeof(long long) * SIZE);
	//long long table[8][6];

	//FILE *f = fopen(FILENAME, "w");
	//if(f == NULL) {
	//	puts("can't open the file");
	//	return 1;
	//}

	randarr(arr, SIZE, 0, 1000);

	//write_arr_to_file(arr, SIZE, f);
	print_arr(arr, SIZE);


	//selection_sort(arr, SIZE);
	//bubble_sort(arr, SIZE);
	//better_bubble_sort(arr, SIZE);
	//merge_sort(arr, 0, SIZE-1);
	quick_sort(arr, 0, SIZE-1);
	
	//write_arr_to_file(arr, SIZE, f);
	print_arr(arr, SIZE);

 	//fclose(f);
	return 0;
}

void selection_sort(long long *arr, long long len)
{
	for(long long i = 0; i < len; i++) {
		long long imin = i;
		for(long long j = i; j < len; j++)
			imin = arr[j] < arr[imin] ? j : imin;
		swap(&arr[i], &arr[imin]);
	}
}

void bubble_sort(long long *arr, long long len)
{
	for(long long i = 0; i < len; i++)
		for(long long j = 1; j < len; j++)
			if(arr[j-1] > arr[j])
				swap(&arr[j], &arr[j-1]);
}

void better_bubble_sort(long long *arr, long long len)
{
	for(long long i = 0; i < len; i++) {
		bool last = true;
		for(long long j = 1; j < len; j++)
			if(arr[j-1] > arr[j]) {
				swap(&arr[j], &arr[j-1]);
				last = false;
			}
		if(last)
			break;
	}
}

void shaker_sort(long long *arr, long long len)
{
	for(long long i = 0; i <= len/2; i++) {
		for(long long j = i+1; j <= len - i - 1; j++) {
			if(arr[j-1] > arr[j])
				swap(&arr[j-1], &arr[j]);
		}

		for(long long j = len - i - 1; j >= i+1; j--) {
			if(arr[j-1] > arr[j])
				swap(&arr[j-1], &arr[j]);
		}
	}
}

void insertion_sort(long long *arr, long long len)
{
	for(long long i = 1; i < len; i++)
		for(long long j = i; arr[j-1] > arr[j] && j-- > 0; swap(&arr[j], &arr[j+1]));
}

void better_insertion_sort(long long *arr, long long len)
{
	// add barrier element
	long long imin = 0;
	for(long long i = 0; i < len; i++)
		imin = arr[i] < arr[imin] ? i : imin;
	swap(&arr[0], &arr[imin]);

	for(long long i = 1; i < len; i++)
		for(long long j = i; arr[j-1] > arr[j]; swap(&arr[j], &arr[j+1]));
}

void merge_sort(long long *arr, long long istart, long long istop)
{
	if(istop == istart)
		return;

	merge_sort(arr, istart, (istart + istop)/2);
	merge_sort(arr, (istart + istop)/2 + 1, istop);
	
	// merge two sorted arrays
	long long *temp_arr = (long long*)malloc(sizeof(long long) * (istop - istart + 1));

	long long i = istart, j = (istart + istop)/2 + 1, k = 0;
	while(i <= (istart + istop)/2 && j <= istop)
		temp_arr[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];

	for(; i <= (istart + istop)/2; temp_arr[k++] = arr[i++]);
	for(; j <= istop; temp_arr[k++] = arr[j++]);

	for(long long i = 0; i < k; i++)
		arr[istart + i] = temp_arr[i];

	free(temp_arr);
}

void quick_sort(long long *arr, long long istart, long long istop)
{
	long long i = istart;
	long long j = istop;
	long long pivot = arr[(istart + istop)/2];

	while(i <= j) {
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if(i <= j)
			swap(&arr[i++], &arr[j--]);
	}

	if(j > istart)
		quick_sort(arr, istart, j);
	if(i < istop)
		quick_sort(arr, i, istop);
}

void genarr(long long *arr, long long len, long long first_element, long long increment)
{
	for(long long i = 0; i < len; i++)
		arr[i] = first_element + i*increment;
}

void randarr(long long *arr, long long len, long long min, long long max)
{
	srand(time(NULL));
	for(long long i = 0; i < len; i++)
		arr[i] = rand() % (max - min + 1) + min;
}

void print_arr(long long *arr, long long len)
{
	for(long long i = 0; i < len; i++) {
		printf("%8lld ", arr[i]);
		if(i%10 == 9)
			putchar('\n');
	}
	putchar('\n');
}

void write_arr_to_file(long long *arr, long long len, FILE *f)
{
	for(long long i = 0; i < len; i++) {
		fprintf(f, "%8lld ", arr[i]);
		if(i%10 == 9)
			fputc('\n', f);
	}
	fputc('\n', f);
	fputc('\n', f);
}


void swap(long long *a, long long *b)
{
	long long t = *a;
	*a = *b;
	*b = t;
}

