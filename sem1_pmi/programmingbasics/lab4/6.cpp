#include <cstdio>

int main()
{
	int p;
	printf("number: ");
	scanf("%d", &p);

	int oddnum = 3, c = 1;
	while(p > 1) {
		if(p % oddnum > 0) {
			printf("can't factor !!");
			return 1;
		}

		p /= oddnum;
		oddnum += 2;
		c++;
	}

	printf("%d\n", c);

	return 0;
}

