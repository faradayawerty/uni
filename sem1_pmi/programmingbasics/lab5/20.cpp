#include <cstdio>

// я решил не использовать pow из cmath,
// потому что эта функция возвращает double,
// который потом будет тяжелее сравнивать
long int power(int number, int exponent);

// число цифр
int number_of_digits(int);

// проверяет, является ли аргумент числом армстронга
bool is_armstrong(int);

int main()
{
	for(int i = 100; i < 10000; i++) {
		if(is_armstrong(i))
			printf("\t%d\n", i);
	}

	return 0;
}

bool is_armstrong(int n)
{
	int k = number_of_digits(n);
	long int s = 0;

	for(int m = n; m > 0; m /= 10)
		s += power(m%10, k);

	return s == n;
}

long int power(int n, int p)
{
	long int result = 1;

	for(int i = 0; i < p; i++)
		result *= n;

	return result;
}

int number_of_digits(int n)
{
	int c = 0;

	for(; n > 0; n /= 10)
		c++;

	return c;
}

// P.S.
//
// очень жду, когда нам разрешат использовать рекурсию,
// потому что с ней можно гораздо проще определять многие функции
//
//int number_of_digits(int n)
//{
//	if(n < 10)
//		return 1;
//	return 1 + number_of_digits(n / 10);
//}

