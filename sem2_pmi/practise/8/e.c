#include <stdio.h>

int main()
{
	int N, k;
	scanf("%d %d", &N, &k);

	if(N*N < k || N*N % k != 0) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}

	return 0;
}

