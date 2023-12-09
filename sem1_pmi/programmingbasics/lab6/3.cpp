#include <cstdio>

void print_chars(int number_of_characters, char character);
int divisors(int);

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) {
		printf("\t%d", i);
		print_chars(divisors(i), '+');
		printf("\n");
	}

	return 0;
}

int divisors(int n)
{
	int divs = 0;
	for(int i = 1; i <= n; i++)
		if(n%i == 0)
			divs++;
	return divs;
}

void print_chars(int n, char c)
{
	for(;n > 0; n--)
		printf("%c", c);
}

