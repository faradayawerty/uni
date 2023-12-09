#include <stdio.h>

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	int count = 0;

	for(int b = 0; b <= n; b++)
		for(int a = 0; a <= m; a++) {
			if(a*a + b == n && a + b*b == m)
				count++;
		}

	printf("%d\n", count);

	return 0;
}

