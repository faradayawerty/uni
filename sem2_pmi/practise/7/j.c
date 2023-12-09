#include <stdio.h>

long long int eights(int n)
{
	long long int p = 0;
	for(int i = 0; i < n; i++)
		p = 10*p + 8;
	return p;
}

int main()
{
	int k;
	scanf("%d", &k);

	if(k > 36) {
		printf("%d\n", -1);
		return 0;
	}

	printf("%lld\n",
		k%2 ? eights(k/2) * 10 + 6 : eights(k/2)
	);

	return 0;
}

