#include <cstdio>
#include <cmath>

#define INTERVAL_BEGIN -1
#define INTERVAL_END 1
#define DELTA 0.1

int CompareTo(int a, int b);
int CompareTo(double a, double b);
double f(double x);

int main()
{
	bool increasing = true;
	for(double p = INTERVAL_BEGIN; p < INTERVAL_END; p += DELTA) {
		if(f(p) > f(p+DELTA)) {
			increasing = false;
			break;
		}
	}

	if(increasing)
		printf("f(x) is increasing\n");
	else
		printf("f(x) is NOT icreasing\n");

	return 0;
}

double f(double x)
{
	return x*x*x + sin(x);
}

int CompareTo(int a, int b)
{
	return a < b ? -1 : a > b;
}

int CompareTo(double a, double b)
{
	return a - b < DELTA/2? -1 : a - b > DELTA/2;
}

