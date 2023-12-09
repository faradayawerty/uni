#include <stdio.h>

#define ITEM_COUNT 7
#define WEIGHT_MAX 50

int weights[ITEM_COUNT] = {
	11,	20,	31,	54,	78,	19,	15,
};

int values[ITEM_COUNT] = {
	15,	30,	91,	81,	66,	44,	41,
};

int max_values[ITEM_COUNT] = {
	0,	0,	0,	0,	0,	0,	0,
};

int get_max_value(int i, int max_weight);
float u_max(float a, float b);
void u_print_arr(int *arr, int len);

int main()
{
	int max_value = get_max_value(ITEM_COUNT - 1 , WEIGHT_MAX);
	u_print_arr(max_values, ITEM_COUNT);
	printf("\t%d\n", max_value);
	return 0;
}

int get_max_value(int i, int max_weight)
{
	if(i == 0 && weights[i] <= max_weight)
		max_values[i] = values[i];
	else if(i == 0)
		max_values[i] = 0;

	else if(weights[i] <= max_weight)
		max_values[i] = u_max(values[i] + get_max_value(i-1, max_weight - weights[i]),
                             get_max_value(i-1, max_weight));
	else
		max_values[i] = get_max_value(i-1, max_weight);

	return max_values[i];
}

float u_max(float a, float b)
{
	return a > b ? a : b;
}

void u_print_arr(int *arr, int len)
{
	for(int i = 0; i < len; i++)
		printf("\t%d", arr[i]);
	putchar('\n');
}

