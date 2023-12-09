#include <stdlib.h>
#include <stdio.h>

#define BLANK 0
#define QUEEN 1

#define QUEEN_PLACEMENT_FAIL -1
#define QUEEN_PLACEMENT_SUCCESS 0

#define QUEEN_ATTACKED_TRUE 1
#define QUEEN_ATTACKED_FALSE 0

void solution(int *desk, int n, int q, int *solution_count);
int place_queen(int *desk, int n, int i, int j);
int num_of_queens_attacked(int *desk, int n, int i, int j);
void clear_all(int *desk, int n);
void clear_row(int *desk, int n, int i);
void clear_column(int *desk, int n, int i);
void print_desk(int *desk, int n);

int main()
{
	int n; printf("n = "); scanf("%d", &n);
	int *desk = calloc(sizeof(int), n*n);

	int solution_count = 0;
	solution(desk, n, 0, &solution_count);
	printf("%d\n", solution_count);

	return 0;
}

// O(...) - долго
void solution(int *desk, int n, int q, int *solution_count)
{
	if(q == n) {
		print_desk(desk, n);
		(*solution_count)++;
		putchar('\n');
	}

	for(int i = 0; i < n; i++)
		if(place_queen(desk, n, q, i) == QUEEN_PLACEMENT_SUCCESS) {
			solution(desk, n, q+1, solution_count);
			clear_row(desk, n, i);
		}
}

// O(n²)
int num_of_queens_attacked(int *desk, int n, int i, int j)
{
	int count = 0;
	for(int k = 0; k < n*n; k++)
		if(desk[k] == QUEEN && (i == k%n || j == k/n || abs(i - k%n) == abs(j - k/n)))
			count++;
	return count;
}

// O(n²)
int place_queen(int *desk, int n, int i, int j)
{
	if(i < 0 || i >= n || j < 0 || j >= n)
		return QUEEN_PLACEMENT_FAIL;

	if(num_of_queens_attacked(desk, n, i, j) > 0)
		return QUEEN_PLACEMENT_FAIL;
	
	desk[i + n*j] = QUEEN;
	return QUEEN_PLACEMENT_SUCCESS;
}

// O(n²)
void print_desk(int *desk, int n)
{
	for(int i = 0; i < n*n; i++) {
		printf("%d ", desk[i]);
		if((i+1)%n == 0)
			putchar('\n');
	}
}

void clear_row(int *desk, int n, int i)
{
	if(i < 0 || i >= n)
		return;
	for(int j = 0; j < n; j++)
		desk[j + i*n] = BLANK;
}

void clear_column(int *desk, int n, int i)
{
	if(i < 0 || i >= n)
		return;
	for(int j = 0; j < n; j++)
		desk[i + j*n] = BLANK;
}

void clear_all(int *desk, int n)
{
	for(int i = 0; i < n*n; i++)
		desk[i] = BLANK;
}

