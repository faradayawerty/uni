#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Queen {
	int x;
	int y;
};

void solve(struct Queen *qs, int n, int i, int q, int *min);
void print_queen(struct Queen q);
void print_queens(struct Queen *qs, int n);
void print_desk(struct Queen *qs, int n);
int count_attacked_cells(struct Queen *qs, int n);

int main()
{
	int n; printf("n = "); scanf("%d", &n);
	struct Queen *qs = (struct Queen*)calloc(sizeof(struct Queen), n);

	int min = INT_MAX;
	solve(qs, n, 0, 0, &min);
	printf("%d\n", min);

	return 0;
}

void solve(struct Queen *qs, int n, int i, int q, int *min)
{
	if(q == n) {
		int c = count_attacked_cells(qs, n);
		if(c < *min) {
			*min = c;
			print_desk(qs, n);
		}

		return;
	}

	for(int j = i; j < n*n; j++) {
		qs[q].x = j % n;
		qs[q].y = j / n;
		solve(qs, n, j+1, q+1, min);
	}
}

void print_queens(struct Queen *qs, int n)
{
	for(int i = 0; i < n; i++)
		print_queen(qs[i]);
	putchar('\n');
}

void print_queen(struct Queen q)
{
	printf("(%d %d) ", q.x, q.y);
}

int count_attacked_cells(struct Queen *qs, int n)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	for(int k = 0; k < n; k++) 
		if(qs[k].x == i || qs[k].y == j ||
				abs(qs[k].x - j) == abs(qs[k].y - i)) {
			count++;
			break;
		}
	return count;
}

void print_desk(struct Queen *qs, int n)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			bool queen_on_cell = false;
			for(int k = 0; k < n; k++)
				if(qs[k].x == j && qs[k].y == i)
					queen_on_cell = true;
			if(queen_on_cell)
				putchar('1');
			else
				putchar('0');
			putchar(' ');
		}
		putchar('\n');
	}
	putchar('\n');
}

bool attack(struct Queen q1, struct Queen q2)
{
	if(q1.x == q2.x || q1.y == q2.y || abs(q1.x - q2.x) == abs(q1.y - q2.y))
		return true;
	return false;
}
