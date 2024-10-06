#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define SIZE 200

void selection_sort(long long *arr, long long len, long long *com, long long *sw); // 1
void bubble_sort(long long *arr, long long len, long long *com, long long *sw); // 2
void better_bubble_sort(long long *arr, long long len, long long *com, long long *sw); // 3
void shaker_sort(long long *arr, long long len, long long *com, long long *sw); // 4
void insertion_sort(long long *arr, long long len, long long *com, long long *sw); // 5
void better_insertion_sort(long long *arr, long long len, long long *com, long long *sw); // 6
void merge_sort(long long *arr, long long istart, long long istop, long long *com, long long *sw); // 7
void quick_sort(long long *arr, long long istart, long long istop, long long *com, long long *sw); // 8

void swap(long long *a, long long *b);
void randarr(long long *arr, long long len, long long min, long long max);
void genarr(long long *arr, long long len, long long first_element, long long increment);
void print_arr(long long *arr, long long len);

int main()
{
	long long *arr = (long long*)malloc(sizeof(long long) * SIZE);
	long long table[8][6];
	long long com, sw;

	for(int j = 0; j < 8; j++)
		for(int i = 0; i < 6; i++)
			table[j][i] = 0;

	genarr(arr, SIZE, 0, 1);
	selection_sort(arr, SIZE, &com, &sw);
	table[0][0] = com; table[0][1] = sw;

	genarr(arr, SIZE, SIZE, -1);
	selection_sort(arr, SIZE, &com, &sw);
	table[0][2] = com; table[0][3] = sw;

	randarr(arr, SIZE, 0, 100);
	selection_sort(arr, SIZE, &com, &sw);
	table[0][4] = com; table[0][5] = sw;


	genarr(arr, SIZE, 0, 1);
	bubble_sort(arr, SIZE, &com, &sw);
	table[1][0] = com; table[1][1] = sw;

	genarr(arr, SIZE, SIZE, -1);
	bubble_sort(arr, SIZE, &com, &sw);
	table[1][2] = com; table[1][3] = sw;

	randarr(arr, SIZE, 0, 100);
	bubble_sort(arr, SIZE, &com, &sw);
	table[1][4] = com; table[1][5] = sw;


	genarr(arr, SIZE, 0, 1);
	better_bubble_sort(arr, SIZE, &com, &sw);
	table[2][0] = com; table[2][1] = sw;

	genarr(arr, SIZE, SIZE, -1);
	better_bubble_sort(arr, SIZE, &com, &sw);
	table[2][2] = com; table[2][3] = sw;

	randarr(arr, SIZE, 0, 100);
	better_bubble_sort(arr, SIZE, &com, &sw);
	table[2][4] = com; table[2][5] = sw;


	genarr(arr, SIZE, 0, 1);
	shaker_sort(arr, SIZE, &com, &sw);
	table[3][0] = com; table[3][1] = sw;

	genarr(arr, SIZE, SIZE, -1);
	shaker_sort(arr, SIZE, &com, &sw);
	table[3][2] = com; table[3][3] = sw;

	randarr(arr, SIZE, 0, 100);
	shaker_sort(arr, SIZE, &com, &sw);
	table[3][4] = com; table[3][5] = sw;


	genarr(arr, SIZE, 0, 1);
	insertion_sort(arr, SIZE, &com, &sw);
	table[4][0] = com; table[4][1] = sw;

	genarr(arr, SIZE, SIZE, -1);
	insertion_sort(arr, SIZE, &com, &sw);
	table[4][2] = com; table[4][3] = sw;

	randarr(arr, SIZE, 0, 100);
	insertion_sort(arr, SIZE, &com, &sw);
	table[4][4] = com; table[4][5] = sw;


	genarr(arr, SIZE, 0, 1);
	better_insertion_sort(arr, SIZE, &com, &sw);
	table[5][0] = com; table[5][1] = sw;

	genarr(arr, SIZE, SIZE, -1);
	better_insertion_sort(arr, SIZE, &com, &sw);
	table[5][2] = com; table[5][3] = sw;

	randarr(arr, SIZE, 0, 100);
	better_insertion_sort(arr, SIZE, &com, &sw);
	table[5][4] = com; table[5][5] = sw;


	com = 0; sw = 0;
	genarr(arr, SIZE, 0, 1);
	merge_sort(arr, 0, SIZE-1, &com, &sw);
	table[6][0] = com; table[6][1] = sw;

	com = 0; sw = 0;
	genarr(arr, SIZE, SIZE, -1);
	merge_sort(arr, 0, SIZE-1, &com, &sw);
	table[6][2] = com; table[6][3] = sw;

	com = 0; sw = 0;
	randarr(arr, SIZE, 0, 100);
	merge_sort(arr, 0, SIZE-1, &com, &sw);
	table[6][4] = com; table[6][5] = sw;


	com = 0; sw = 0;
	genarr(arr, SIZE, 0, 1);
	quick_sort(arr, 0, SIZE-1, &com, &sw);
	table[7][0] = com; table[7][1] = sw;

	com = 0; sw = 0;
	genarr(arr, SIZE, SIZE, -1);
	quick_sort(arr, 0, SIZE-1, &com, &sw);
	table[7][2] = com; table[7][3] = sw;

	com = 0; sw = 0;
	randarr(arr, SIZE, 0, 100);
	quick_sort(arr, 0, SIZE-1, &com, &sw);
	table[7][4] = com; table[7][5] = sw;


	for(int j = 0; j < 8; j++) {
		for(int i = 0; i < 6; i++)
			printf("%8ld ", table[j][i]);
		putchar('\n');
	}


	return 0;
}

void selection_sort(long long *arr, long long len, long long *com, long long *sw)
{
	*sw = 0; *com = 0;

	for(long long i = 0; i < len; i++) {
		long long im = i;
		for(long long j = i; j < len; j++) {
			im = arr[j] < arr[im] ? j : im;
			(*com)++;
		}
		swap(&arr[i], &arr[im]);
		(*sw)++;
	}
}

void bubble_sort(long long *arr, long long len, long long *com, long long *sw)
{
	*com = 0; *sw = 0;

	for(long long i = 0; i < len; i++)
		for(long long j = 1; j < len; j++) {
			(*com)++;
			if(arr[j-1] > arr[j]) {
				swap(&arr[j], &arr[j-1]);
				(*sw)++;
			}
		}
}

void better_bubble_sort(long long *arr, long long len, long long *com, long long *sw)
{
	*com = 0; *sw = 0;

	for(long long i = 0; i < len; i++) {
		bool last = true;
		for(long long j = 1; j < len; j++) {
			(*com)++;
			if(arr[j-1] > arr[j]) {
				(*sw)++;
				swap(&arr[j], &arr[j-1]);
				last = false;
			}
		}
		if(last)
			break;
	}
}

void shaker_sort(long long *arr, long long len, long long *com, long long *sw)
{
	*com = 0; *sw = 0;

	for(long long i = 0; i <= len/2; i++) {
		for(long long j = i+1; j <= len - i - 1; j++) {
			(*com)++;
			if(arr[j-1] > arr[j]) {
				(*sw)++;
				swap(&arr[j-1], &arr[j]);
			}
		}

		for(long long j = len - i - 1; j >= i+1; j--) {
			(*com)++;
			if(arr[j-1] > arr[j]) {
				(*sw)++;
				swap(&arr[j-1], &arr[j]);
			}
		}
	}
}

void insertion_sort(long long *arr, long long len, long long *com, long long *sw)
{
	*com = 0; *sw = 0;

	for(long long i = 1; i < len; i++) {
		long long j = i;
		while(arr[j-1] > arr[j] && j-- > 0) {
			(*com) += 2;
			swap(&arr[j], &arr[j+1]);
			(*sw)++;
		}
		(*com) += 2;
	}
}

void better_insertion_sort(long long *arr, long long len, long long *com, long long *sw)
{
	*com = 0; *sw = 0;

	// add barrier element
	long long imin = 0;
	for(long long i = 0; i < len; i++) {
		imin = arr[i] < arr[imin] ? i : imin;
		(*com)++;
	}
	swap(&arr[0], &arr[imin]);
	(*sw)++;

	for(long long i = 1; i < len; i++) {
		long long j = i;
		while(arr[j-1] > arr[j]) {
			j--;
			(*com)++;
			swap(&arr[j], &arr[j+1]);
			(*sw)++;
		}
		(*com)++;
	}
}

void merge_sort(long long *arr, long long istart, long long istop, long long *com, long long *sw)
{
	if(istop == istart)
		return;

	merge_sort(arr, istart, (istart + istop)/2, com, sw);
	merge_sort(arr, (istart + istop)/2 + 1, istop, com, sw);
	
	// merge two sorted arrays
	long long *temp_arr = (long long*)malloc(sizeof(long long) * (istop - istart + 1));

	long long i = istart, j = (istart + istop)/2 + 1, k = 0;
	while(i <= (istart + istop)/2 && j <= istop) {
		temp_arr[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
		(*com)++;
		(*sw)++;
	}

	for(; i <= (istart + istop)/2; temp_arr[k++] = arr[i++])
		(*sw)++;

	for(; j <= istop; temp_arr[k++] = arr[j++]);
		(*sw)++;

	for(long long i = 0; i < k; i++) {
		arr[istart + i] = temp_arr[i];
		(*sw)++;
	}

	free(temp_arr);
}

void quick_sort(long long *arr, long long istart, long long istop, long long *com, long long *sw)
{
	long long i = istart;
	long long j = istop;
	long long pivot = arr[(istart + istop)/2];

	while(i <= j) {
		while(arr[i] < pivot) {
			(*com)++;
			i++;
		}
		(*com)++;

		while(arr[j] > pivot) {
			(*com)++;
			j--;
		}
		(*com)++;

		if(i <= j) {
			swap(&arr[i++], &arr[j--]);
			(*sw)++;
		}
	}

	if(j > istart)
		quick_sort(arr, istart, j, com, sw);
	if(i < istop)
		quick_sort(arr, i, istop, com, sw);
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
		printf("%8ld ", arr[i]);
		if(i%10 == 9)
			putchar('\n');
	}
	putchar('\n');
}


void swap(long long *a, long long *b)
{
	long long t = *a;
	*a = *b;
	*b = t;
}

