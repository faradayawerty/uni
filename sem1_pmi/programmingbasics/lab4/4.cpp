#include <cstdio>

int get_digit(int number, int position);
int set_digit(int number, int position, int digit);
int number_of_digits(int number);
int max_digit_position(int number);
int min_digit_position(int number);

int main()
{
	int x;
	printf("number: ");
	scanf("%d", &x);

	int mind_pos = min_digit_position(x);
	int maxd_pos = max_digit_position(x);

	int maxd = get_digit(x, maxd_pos);
	int mind = get_digit(x, mind_pos);
	
	x = set_digit(x, maxd_pos, mind);
	x = set_digit(x, mind_pos, maxd);

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

int max_digit_position(int n)
{
	int i = 0, max = -1, max_pos = 0;
	while(n != 0) {
		if (n%10 > max) {
			max = n%10;
			max_pos = i;	
		}
		n /= 10;
		i++;
	}
	return max_pos;
}

int min_digit_position(int n)
{
	int i = 0, min = 10, min_pos = 0;
	while(n != 0) {
		if (n%10 < min) {
			min = n%10;
			min_pos = i;	
		}
		n /= 10;
		i++;
	}
	return min_pos;
}

