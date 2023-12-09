#include <stdio.h>

int **l_count_arr;

int l_count_func(int n, int k);

int l_count_func(int n, int k)
{
	if(n == k)
		return 1;

	int s = 0;
	for(int i = 1; i < k; i++)
		s += l_count_func(n - k, i);
	return s;
}

int main()
{
	int n = 9, s = 0, N;
	for(int i = 1; i < n; i++) {
		N = l_count_func(n, i);
		s += N;
		printf("%d %d %d\n", n, i, N);
	}
	printf("%d\n", s);

	return 0;
}

