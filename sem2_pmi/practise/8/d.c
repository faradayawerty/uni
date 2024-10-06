#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	double S = fabs((c*c)/(2.0*a*b));

	printf("%.15f\n", S);

	return 0;
}

