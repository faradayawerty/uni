#include <cstdio>

void max_digit(int number, int* digit, int* position);
void max_odd_digit(int number, int* digit, int* position);

int main()
{
	int n;
	printf("$ ");
	scanf("%d", &n);

	int md, mdp;
	max_digit(n, &md, &mdp);

	int mod, modp;
	max_odd_digit(n, &mod, &modp);

	printf("a) максимальная цифра числа %d равна %d и находится в разряде %d\n", n, md, mdp);
	printf("b) максимальная нечетная цифра числа %d равна %d и находится в разряде %d\n", n, mod, modp);

	return 0;
}

void max_digit(int n, int* d, int* p)
{
	int maxd = 0, maxdp = 0;

	for(int i = 0; n > 0; i++) {
		if(n%10 > maxd) {
			maxd = n%10;
			maxdp = i;
		}
		n /= 10;
	}

	*d = maxd;
	*p = maxdp;
}

void max_odd_digit(int n, int* d, int* p)
{
	int maxd = 0, maxdp = 0;

	for(int i = 0; n > 0; i++) {
		if(n%10 > maxd && n%10 % 2 == 1) {
			maxd = n%10;
			maxdp = i;
		}
		n /= 10;
	}

	*d = maxd;
	*p = maxdp;
}

