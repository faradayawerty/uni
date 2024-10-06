#include <cstdio>

int digit_sum(int);
int number_of_digits(int);
int fact(int);
int ones(int);
float avarage_of_permutations(int);
bool all_digits_different(int);

int main()
{
	for (int i = 100; i < 1000; i++) {
		if(all_digits_different(i) && (int)avarage_of_permutations(i) == i)
			printf("\t%d\n", i);
	}

	return 0;
}

// считает среднее значение всех чисел,
// получаемых перестановками цифр аргумента
float avarage_of_permutations(int n)
{
	// --- пояснение к формуле --- //
	//
	// рассмотрим как пример число 372
	// выпишем числа, получаемые перестановкой цифр этого числа:
	// 372, 327, 273, 237, 723, 732
	// заметим, что их сумма это
	// (300+300+200+200+700+700) + (30+30+20+20+70+70) + (3+3+2+2+7+7)
	// или другими словами (3+7+2)*2 * (1+10+100)
	// самих перестановок ровно 3!, т.к. число трехзначное
	//
	return digit_sum(n)*2 * ones(number_of_digits(n)) / (float)fact(number_of_digits(n));
}

// проверяет, являются ли все цифры числа различными
bool all_digits_different(int n)
{
	for(int i = 0; i < 10; i++) {
		int m = n, c = 0;

		for(;m > 0; m /= 10) {
			if(m%10 == i)
				c++;
		}

		if(c > 1)
			return false;
	}

	return true;
}

// считает сумму цифр числа
int digit_sum(int n)
{
	int s = 0;
	for(;n > 0; n /= 10)
		s += n%10;
	return s;
}

// считает количество цифр в числе
int number_of_digits(int n)
{
	int c = 0;
	for(;n > 0; n /= 10)
		c++;
	return c;
}
// считает факториал числа
int fact(int n)
{
	int result = 1;
	for(int i = n; i > 0; i--)
		result *= i;
	return result;
}

// возвращает число, состоящие из `n` единичек в десятичной с.с.
int ones(int n)
{
	int result = 0, t = 1;
	for(int i = 0; i < n; i++) {
		result += t;
		t *= 10;
	}
	return result;
}

