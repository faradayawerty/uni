#include <stdio.h>
#include <stdlib.h>

long long int binomial(int n, int k);
void print_pascal_triangle(int n);

int main()
{
	printf("%lld\n", binomial(40, 15));
	print_pascal_triangle(6);

	return 0;
}

long long int binomial(int n, int k)
{
	if(k == 0 || k == n)
		return 1;

	long long int val = 1;
	for(int i = 0; i < k; i++) {
		val *= n - i;
		val /= i + 1;
	}

	return val;
}

void print_pascal_triangle(int n)
{
	int *row_d, *row_u = (int *)malloc(sizeof(int) * 1);
	row_u[0] = 1;

	for(int i = 1; i < n + 1; i++) {
		row_d = (int *)malloc(sizeof(int) * (i + 1));

		for(int j = 0; j < i + 1; j++)
			if(j == 0 || j == i)
				row_d[j] = 1;
			else
				row_d[j] = row_u[j] + row_u[j - 1];

		free(row_u);
		row_u = row_d;
	}

	for(int i = 0; i < n + 1; i++)
		printf("\t%d", row_d[i]);
	putchar('\n');

	free(row_d);
}

