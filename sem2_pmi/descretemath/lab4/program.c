#include <stdio.h>
#include <stdlib.h>

int main()
{
	puts("(1+x)^(3/2) = ");
	double p = 1;
	for(int k = 0; k < 20; k++) {

		p *= 5 - 2*(k+1);
		p /= 2*(k+1);

		printf(k == 0 ? " %.40f\n" : p > 0 ? "+%.40f x^%d\n" : "%.40f x^%d\n", p, k);
	}
	puts("+ ...\n");

	puts("sqrt(1-4x)");
	p = 1;
	for(int k = 0; k < 20; k++) {

		p *= 4*(k+1) - 6;
		p /= (k+1);

		printf(k == 0 ? "%.40f\n" : p > 0 ? "+%.40f x^%d\n" : "%.40f x^%d\n", p, k);
	}
	puts("+ ...\n");

	return 0;
}

