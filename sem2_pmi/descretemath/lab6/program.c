#include <stdio.h>
#include <stdlib.h>

int calc_minor(int **matrix, int n, int i, int j);
int calc_det(int **matrix, int n);
void calc_adj(int **matrix_input, int **matrix_output, int n);

void clear_matrix(int **matrix, int n);
void print_matrix(int **matrix, int n);
void randomize_matrix(int **matrix, int n);

void fill_stirling_1(int **matrix, int n);
void fill_stirling_2(int **matrix, int n);

int stirling_2_up(int n, int k);
void print_stirling_up(int n);

int main()
{
	int n = 10;
	int **matrix = (int **)calloc(sizeof(int *), n);
	for(int i = 0; i < n; matrix[i++] = (int *)calloc(sizeof(int), n));

	int **adj_matrix = (int **)calloc(sizeof(int *), n);
	for(int i = 0; i < n; adj_matrix[i++] = (int *)calloc(sizeof(int), n));

	puts("Числа стирлинга 1 рода:");
	fill_stirling_1(matrix, n);
	print_matrix(matrix, n);

	puts("Числа стирлинга 2 рода:");
	fill_stirling_2(matrix, n);
	print_matrix(matrix, n);

	puts("Обратная матрица к матрице из чисел стирлинга 2 рода:");
	fill_stirling_1(matrix, n);
	calc_adj(matrix, adj_matrix, n);
	print_matrix(adj_matrix, n);

	puts("Продолжение чисел стирлинга 2 рода вверх:");
	print_stirling_up(n);

	return 0;
}

int calc_det(int **matrix, int n)
{
	if(n == 2)
		return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

	int **minor = (int **)calloc(sizeof(int *), n - 1);
	for(int i = 0; i < n - 1; i++)
		minor[i] = (int *)calloc(sizeof(int), n - 1);

	int det = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n - 1; i++)
			for(int j = 0; j < n - 1; j++)
				minor[i][j] = matrix[i + 1][j < k ? j : j + 1];
		det += (k%2 ? -1 : 1) * matrix[0][k] * calc_det(minor, n - 1);
	}

	free(minor);
	return det;
}

int calc_minor(int **matrix, int n, int i, int j)
{
	if(n == 2)
		return matrix[1 - i][1 - j];

	int **minor = (int **)calloc(sizeof(int *), n - 1);
	for(int k = 0; k < n - 1; k++)
		minor[k] = (int *)calloc(sizeof(int), n - 1);

	for(int ii = 0; ii < n - 1; ii++)
		for(int jj = 0; jj < n - 1; jj++)
			minor[ii][jj]
				= matrix[ii < i ? ii : ii + 1][jj < j ? jj : jj + 1];

	return calc_det(minor, n - 1);
}

void calc_adj(int **matrix_input, int **matrix_output, int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			matrix_output[j][i] = ((i+j) % 2 ? -1 : 1) *
				calc_minor(matrix_input, n, i, j);
}

void print_matrix(int **matrix, int n)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("\t%d", matrix[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void randomize_matrix(int **matrix, int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			matrix[i][j] = rand() % 10;
}

void fill_stirling_1(int **matrix, int n)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i + 1; j++)
			if(i == 0 || j == i)
				matrix[i][j] = 1;
			else if(j == 0)
				matrix[i][j] = 0;
			else
				matrix[i][j] = (i-1)*matrix[i-1][j] + matrix[i-1][j-1];
	}
}


void fill_stirling_2(int **matrix, int n)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i + 1; j++)
			if(i == 0 || j == i)
				matrix[i][j] = 1;
			else if(j == 0)
				matrix[i][j] = 0;
			else
				matrix[i][j] = j*matrix[i-1][j] + matrix[i-1][j-1];
	}
}

void clear_matrix(int **matrix, int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			matrix[i][j] = 0;
}

void print_stirling_up(int n)
{
	int **arr = (int **)calloc(sizeof(int *), n);
	for(int i = 0; i < n; arr[i++] = (int *)calloc(sizeof(int), n));

	for(int i = 0; i > -n; i--)
		for(int j = 0; j > -n; j--)
			arr[n + i - 1][n + j - 1] = stirling_2_up(i, j);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("\t%d", arr[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

int stirling_2_up(int n, int k)
{
	if(n == k)
		return 1;
	else if(n == 0 || k == 0)
		return 0;
	return - (k+1)*stirling_2_up(n, k + 1) + stirling_2_up(n + 1, k + 1);
}

