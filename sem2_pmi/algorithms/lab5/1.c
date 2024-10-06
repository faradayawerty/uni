#include <stdio.h>
#include <stdbool.h>

#define BLANK 0
#define WALL 1
#define STEP 2
#define START 5
#define FINISH 6
#define END_OF_LINE -1
#define END_OF_MAZE -2

bool maze_solve(int *arr, int w, int h, int start_x, int start_y, int finish_x, int finish_y);
void maze_print(int *arr);
void maze_get_start(int *arr, int *x, int *y);
void maze_get_finish(int *arr, int *x, int *y);
int maze_get_width(int *arr);
int maze_get_height(int *arr);

int main()
{

	//int maze[] = {
		//1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, -1,
		//1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, -1,
		//1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, -1,
		//1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, -1,
		//1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, -1,
		//1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, -1,
		//1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, -1,
		//1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, -1,
		//1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1,
		//1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, -1,
		//1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, -1,
		//1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -2,
	//};

	int maze[] = {
		1, 5, 1, 1, 1, 1, 1, 1, -1,
		1, 0, 1, 0, 0, 0, 0, 0, -1,
		1, 0, 0, 0, 0, 0, 0, 0, -1,
		1, 0, 1, 0, 0, 0, 0, 0, -1,
		1, 0, 1, 0, 1, 0, 0, 0, -1,
		1, 0, 1, 0, 1, 0, 0, 0, -1,
		1, 0, 0, 0, 1, 0, 0, 6, -1,
		1, 1, 1, 1, 1, 1, 1, 1, -2,
	};

	int start_x, start_y, finish_x, finish_y;
	
	maze_get_start(maze, &start_x, &start_y);
	maze_get_finish(maze, &finish_x, &finish_y);

	maze_solve(maze, maze_get_width(maze), maze_get_height(maze),
			start_x, start_y, finish_x, finish_y);
	maze_print(maze);

	return 0;
}

bool maze_solve(int *arr, int w, int h, int start_x, int start_y, int finish_x, int finish_y)
{
	if(start_x == finish_x && start_y == finish_y)
		return true;

	if(arr[start_x + start_y*(w+1)] == WALL || arr[start_x + start_y*(w+1)] == STEP)
		return false;

	arr[start_x + start_y*(w+1)] = STEP;

	if(maze_solve(arr, w, h, start_x + 1, start_y, finish_x, finish_y))
		return true;
	if(maze_solve(arr, w, h, start_x - 1, start_y, finish_x, finish_y))
		return true;
	if(maze_solve(arr, w, h, start_x, start_y + 1, finish_x, finish_y))
		return true;
	if(maze_solve(arr, w, h, start_x, start_y - 1, finish_x, finish_y))
		return true;
	
	arr[start_x + start_y*(w+1)] = BLANK;
	return false;
}

void maze_print(int *arr)
{
	for(int i = 0; arr[i] != END_OF_MAZE; i++)
		if(arr[i] == END_OF_LINE)
			putchar('\n');
		else if(arr[i] == WALL)
			printf("###");
		else if(arr[i] == START)
			printf(" S ");
		else if(arr[i] == FINISH)
			printf(" F ");
		else if(arr[i] == STEP)
			printf(" . ");
		else if(arr[i] == BLANK)
			printf("   ");
	putchar('\n');
}

int maze_get_width(int *arr)
{
	int count;
	for(count = 0; arr[count] != END_OF_LINE; count++);
	return count;
}

int maze_get_height(int *arr)
{
	int count = 1;
	for(int i = 0; arr[i] != END_OF_MAZE; i++) {
		if(arr[i] == END_OF_LINE)
			count++;
	}
	return count;
}

void maze_get_start(int *arr, int *x, int *y)
{
	int w = maze_get_width(arr);
	*x = -10;
	*y = -10;
	for(int i = 0; arr[i] != END_OF_MAZE; i++)
		if(arr[i] == START) {
			*x = i % (w+1);
			*y = i / (w+1);
		}
}

void maze_get_finish(int *arr, int *x, int *y)
{
	int w = maze_get_width(arr);
	*x = -10;
	*y = -10;
	for(int i = 0; arr[i] != END_OF_MAZE; i++)
		if(arr[i] == FINISH) {
			*x = i % (w+1);
			*y = i / (w+1);
		}
}

