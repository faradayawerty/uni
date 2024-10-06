#include <stdio.h>
#include <stdbool.h>

#define	DIR_DOWN	0
#define	DIR_RIGHT	1
#define	SIZE_WIDTH	5
#define	SIZE_HEIGHT	4
#define	SIZE_FIELD	2 * SIZE_WIDTH * SIZE_HEIGHT
#define SIZE_WEIGHTS	SIZE_WIDTH * SIZE_HEIGHT
#define SIZE_PATH	SIZE_WIDTH * SIZE_HEIGHT

int arr_field[SIZE_FIELD] = {
	1,1,	3,2,	4,5,	8,6,	1,0,
	2,6,	7,1,	0,1,	9,0,	2,0,
	4,8,	1,2,	7,8,	1,1,	2,0,
	0,1,	0,2,	0,4,	0,8,	0,0,
};

int arr_weights[SIZE_WEIGHTS] = {
	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,
};

int arr_path[SIZE_PATH] = {
	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,
};

void print_field();
void print_weights();
void print_path();
void calc_weights(int i, int j);
void calc_path();
void set_weight(int i, int j, int val);
int get_weight(int i, int j);
int get_cost(int i, int j, int dir);
int min(int a, int b);

int main()
{
	print_field();
	calc_path();
	print_path();
}

int min(int a, int b)
{
	return a > b ? b : a;
}

int get_cost(int i, int j, int dir)
{
	return arr_field[2*i + dir + j*2*SIZE_WIDTH];
}

void set_weight(int i, int j, int val)
{
	arr_weights[i + j*SIZE_WIDTH] = val;
}

int get_weight(int i, int j)
{
	calc_weights(i, j);
	return arr_weights[i + j*SIZE_WIDTH];
}

void calc_weights(int i, int j)
{
	if(arr_weights[i + j*SIZE_WIDTH] != 0)
		return;

	int cost_down = get_cost(i, j, DIR_DOWN),
		cost_right = get_cost(i, j, DIR_RIGHT);

	if(cost_down == 0 && cost_right == 0)
		return;
	else if(cost_down == 0)
		set_weight(i, j,
                           cost_right + get_weight(i+1, j));
	else if(cost_right == 0)
		set_weight(i, j,
                           cost_down + get_weight(i, j+1));
	else
		set_weight(i, j, min(
			cost_right + get_weight(i+1, j),
			cost_down + get_weight(i, j+1)));
}

void calc_path()
{
	for(int k = 0, i = 0, j = 0; k < SIZE_WIDTH + SIZE_HEIGHT - 1; k++) {
		arr_path[i + j*SIZE_WIDTH] = 1;
		int cost_down = get_cost(i, j, DIR_DOWN),
			cost_right = get_cost(i, j, DIR_RIGHT);
		if(cost_down == 0 && cost_right == 0)
			return;
		else if(cost_down == 0)
			i++;
		else if(cost_right == 0)
			j++;
		else if(get_weight(i+1, j) <= get_weight(i, j+1))
			i++;
		else
			j++;
	}

}

void print_path()
{
	for(int j = 0; j < SIZE_HEIGHT; j++) {
		for(int i = 0; i < SIZE_WIDTH; i++)
			printf("[%c]\t",
                               arr_path[i + SIZE_WIDTH*j] ? 'x' : ' ');
		putchar('\n');
	}
	putchar('\n');
}

void print_field()
{
	for(int j = 0; j < SIZE_HEIGHT; j++) {
		for(int i = 0; i < SIZE_WIDTH; i++) {
			printf("%d↓%d→\t", get_cost(i, j, DIR_DOWN),
                               get_cost(i, j, DIR_RIGHT));
		}
		putchar('\n');
	}
	putchar('\n');
}

void print_weights()
{
	for(int j = 0; j < SIZE_HEIGHT; j++) {
		for(int i = 0; i < SIZE_WIDTH; i++)
			printf("%d\t", get_weight(i, j));
		putchar('\n');
	}
	putchar('\n');
}

