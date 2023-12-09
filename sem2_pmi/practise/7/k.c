#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}

int min(int a, int b)
{
	if(a < b)
		return a;
	return b;
}

int main()
{
	int t, n, k, count;
	char *str;

	scanf("%d", &t);
	for(; t > 0; t--) {
		scanf("%d %d", &n, &k);
		str = (char*)calloc(sizeof str, n+1);
		scanf("%s", str);

		count = 0;
		for (int i = 0; i < n; i++) {
			
		}

		printf("%d\n", count);
	}

	return 0;
}

