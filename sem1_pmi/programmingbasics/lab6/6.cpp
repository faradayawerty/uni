#include <cstdio>

int divisor_sum(int);

int main()
{
	int max = 0, imax;
	for(int i = 1; i < 10000; i++) {
		int ds = divisor_sum(i); // записать в переменную для экономии процессорного времени
		if(ds > max) {
			max = ds;
			imax = i;
		}
	}

	printf("%d\n", imax);

	return 0;
}

int divisor_sum(int n)
{
	int s = 0;

	for(int i = 1; i <= n; i++) {
		if(n%i == 0)
			s += i;
	}

	return s;
}

