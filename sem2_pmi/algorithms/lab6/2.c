#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// triangle data
int t_h;
int **t_arr;
int **t_sum_arr;
int **t_path_arr;
int t_max = 99;
int t_min = 10;

// triangle functions
void t_create();
void t_randomize();
void t_print();

void t_sum_create();
void t_sum_print();
void t_sum_print_path();
void t_sum_gen();

// util functions
void u_print_blanks(int n);
int u_max(int a, int b);
int u_min(int a, int b);

int main()
{
	t_create(); t_randomize(); t_print();
	t_sum_create(); t_sum_gen(); t_sum_print();
	t_sum_print_path();

	return 0;
}


void t_create()
{
	printf("высота треугольника: "); scanf("%d", &t_h);
	t_arr = (int **)calloc(sizeof(int*), t_h * (t_h+1) / 2);
	for(int i = 0; i < t_h; i++)
		t_arr[i] = (int *)calloc(sizeof(int), i + 1);
}

void t_randomize()
{
	for(int i = 0; i < t_h; i++)
		for(int j = 0; j < i + 1; j++)
			t_arr[i][j] = rand() % (t_max - t_min + 1) + t_min;
}

void t_print()
{
	for(int i = 0; i < t_h; i++) {
		for(int j = 0; j < i + 1; j++)
			printf("\t%d", t_arr[i][j]);
		putchar('\n');
	}
	putchar('\n');
}


void t_sum_print()
{
	for(int i = 0; i < t_h; i++) {
		for(int j = 0; j < i + 1; j++)
			printf("\t%d", t_sum_arr[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void t_sum_create()
{
	t_sum_arr = (int **)calloc(sizeof(int*), t_h * (t_h+1) / 2);
	for(int i = 0; i < t_h; i++)
		t_sum_arr[i] = (int *)calloc(sizeof(int), i + 1);
}

void t_sum_gen()
{
	t_sum_arr[0][0] = t_arr[0][0];
	for(int i = 1; i < t_h; i++)
	for(int j = 0; j < i + 1; j++)
		t_sum_arr[i][j] = u_max(
			t_arr[i][j] + t_sum_arr[i-1][j],
			j > 0 ? t_arr[i][j] + t_sum_arr[i-1][j-1] : 0);
}

void t_sum_print_path()
{
	t_path_arr = (int **)calloc(sizeof(int*), t_h * (t_h+1) / 2);
	for(int i = 0; i < t_h; i++)
		t_path_arr[i] = (int *)calloc(sizeof(int), i + 1);

	int imax = 0;
	for(int i = 0; i < t_h; i++)
		if(t_sum_arr[t_h - 1][i] > t_sum_arr[t_h - 1][imax])
			imax = i;

	int j = imax;
	for(int i = t_h - 1; i >= 0; i--)
		t_path_arr[i][u_max(0, j--)] = 1;

	for(int i = 0; i < t_h; i++) {
		for(int j = 0; j < i + 1; j++)
			if(t_path_arr[i][j])
				printf("\t(%d)", t_arr[i][j]);
			else
				printf("\t%d", t_arr[i][j]);
		putchar('\n');
	}
	putchar('\n');
}


void u_print_blanks(int n)
{
	for(int i = 0; i < n; i++)
		putchar(' ');
}

int u_max(int a, int b)
{
	return a > b ? a : b;
}

int u_min(int a, int b)
{
	return a < b ? a : b;
}

