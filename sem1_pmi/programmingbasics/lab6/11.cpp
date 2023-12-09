#include <cstdio>

int main()
{
	int N, M;
	printf("введите два числа через пробел: ");
	scanf("%d %d", &N, &M);

	int n = N, m = M; // скопировать переменные, чтобы позже использовать их

	int c = 0;
	while(n > 0 && m > 0) {
		if(n > m)
			n = n - m;
		else
			m = m - n;
		c++;
	}

	printf("прямоугольник %dx%d можно разрезать на %d квадратов\n", N, M, c);

	return 0;
}

