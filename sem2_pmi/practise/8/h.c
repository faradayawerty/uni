#include <stdio.h>

void print_table(int n, int m, int a, int b)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			putchar((i/a + j/b)%2 ? 'a' : 'b');
		putchar('\n');
	}
}

int main()
{
	int m, n;
	scanf("%d %d", &n, &m);

	if(n%4 == 0)
		print_table(n, m, 4, 1);
	else if(m%4 == 0)
		print_table(n, m, 1, 4);
	else if (m%2 == 0 && n%2 == 0)
		print_table(n, m, 2, 2);
	else
		printf("FAIL\n");

	return 0;
}

