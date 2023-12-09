#include <cstdio>
#include <cmath>

int roots(float a, float b, float c, float* x1, float* x2);

int main()
{
	float a, b, c, x1, x2;
	printf("введите коэффициенты квадратного уравнения через пробел: ");
	scanf("%f %f %f", &a, &b, &c);

	int n = roots(a, b, c, &x1, &x2);

	printf("количество корней: %d\n", n);

	if(n == 1)
		printf("x = %.2f\n", x1);
	else
		printf("x1 = %.2f, x2 = %.2f\n", x1, x2);

	return 0;
}

int roots(float a, float b, float c, float* x1, float* x2)
{
	float D = b*b - 4*a*c;

	if(D < 0)
		return 0;

	*x1 = (-b + sqrt(D))/(2*a);
	*x2 = (-b - sqrt(D))/(2*a);

	return 1 + (D > 0);
}

