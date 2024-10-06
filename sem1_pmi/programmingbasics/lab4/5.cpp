#include <cstdio>

int main()
{
	int old = 100, newnum;

	printf("number: ");
	scanf("%d", &newnum);
	
	while(old < newnum && newnum != 100 || old == 100) {
		old = newnum;
		printf("number: ");
		scanf("%d", &newnum);
	}

	return 0;
}

