#include <cstdio>

int get_digit(int number, int position);
int set_digit(int number, int position, int digit);
int number_of_digits(int number);

int main()
{
	int x;
	printf("number: ");
	scanf("%d", &x);

	int first = get_digit(x, 0);
	int last = get_digit(x, number_of_digits(x) - 1);
	x = set_digit(x, 0, last);
	x = set_digit(x, number_of_digits(x) - 1, first);

	printf("%d\n", x);

	return 0;
}

int get_digit(int n, int i)
{
	int j = 0;
	while(j < i) {
		n /= 10;
		j++;
	}
	return n%10;
}

int set_digit(int n, int i, int d)
{
	int head = n;
	int tail = 0;

	int j = 0;
	while(j < i) {
		tail = tail*10 + head%10;
		head /= 10;
		j++;
	}
	
	head = head/10 * 10 + d;

	j = 0;
	while(j < i) {
		head = head*10 + tail%10;
		tail /= 10;
		j++;
	}

	return head;
}

int number_of_digits(int n)
{
	int c = 0;
	while(n != 0) {
		c++;
		n /= 10;
	}
	return c;
}

