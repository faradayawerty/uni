#include <cstdio>

bool isprime(int);

int main()
{
	for(int i = 1; i < 998; i++) {
		if(isprime(i) && isprime(i+2))
			printf("%d %d\n", i, i+2);
	}

	return 0;
}

bool isprime(int n)
{
	if(n == 1)
		return false;

	for(int i = 2; i*i <= n; i++) {
		if(n%i == 0)
			return false;
	}
	return true;
}

