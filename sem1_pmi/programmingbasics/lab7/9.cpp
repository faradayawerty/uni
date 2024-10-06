#include <cstdio>
#include <cmath>

void f(float x, float* answer, int* error);

int main()
{
	float a, b, h, val;
	int err;

	printf("A = ");
	scanf("%f", &a);
	printf("B = ");
	scanf("%f", &b);
	printf("h = ");
	scanf("%f", &h);

	for(float p = a; p <= b; p += h) {
		f(p, &val, &err);

		if(err != 0) {
			continue;
		}

		printf("f(%.2f) = %.2f\n", p, val);
	}

	return 0;
}

// считает значение sqrt(log(x+5)/(exp(x)-1)) и записывает его в `ans`
//
// `err` равно 0, если `x` попадает в область определения
//
// `err` больше 0, если `x` не попадает в область определения
// `ans` равно 0, если `x` не попадает в область определения
void f(float x, float* ans, int* err)
{
	*ans = 0;
	*err = 0;

	if(x+5 <= 0) // выражение в логарифме должно быть больше нуля
		*err = 1;
	else if (exp(x) - 1 == 0) // на ноль делить нельзя
		*err = 2;
	else if (log(x+5)/(exp(x)-1) < 0) //
		*err = 3;

	if(*err != 0) {
		return;
	}

	*ans = sqrt(log(x+5)/(exp(x)-1));
}

