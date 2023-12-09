#include <cstdio>

int divisornum(int);

int main()
{
	int maxnum = 0, maxdiv = 0;

	for(int i = 100; i < 1000; i++) {
		int d = divisornum(i);
		if(d > maxdiv) {
			maxdiv = d;
			maxnum = i;
		} else if(d == maxdiv && i > maxnum) {
			maxnum = i;
		}
	}

	printf("\t%d\n", maxnum);

	return 0;
}

int divisornum(int n)
{
	int c = 0;
	for(int i = 1; i <= n; i++)
		if(n%i == 0)
			c++;
	return c;
}

