#include <iostream>
#include <climits>

int main()
{
	int n, a;
	std::cin >> n;

	int count_even_odd = 0;

	int sum = 0;
	bool has_sum = false;
	
	int	count_negative = 0,
		count_positive = 0;

	bool ieven = true;
	int	min_ieven = INT_MAX, 
		max_iodd = INT_MIN;

	for(int i = 0; i < n; i++) {
		std::cin >> a;

		if(a%2 == 1 && i%2 == 0)
			count_even_odd++;

		if(abs(a) < i*i) {
			sum += a;
			has_sum = true;
		}

		if(a > 0)
			count_positive++;
		else if(a < 0)
			count_negative++;

		if(ieven) {
			if(min_ieven > a)
				min_ieven = a;
		} else {
			if(max_iodd < a)
				max_iodd = a;
		}

		ieven = !ieven;
	}

	std::cout << "a) " << count_even_odd << std::endl;

	if(has_sum)
		std::cout << "b) " << sum << std::endl;
	else
		std::cout << "b) " << "no sum" << std::endl;
	
	if(count_negative > count_positive)
		std::cout << "c) " << "yes" << std::endl;
	else
		std::cout << "c) " << "no" << std::endl;

	std::cout << "d) " << "min = " << min_ieven << ", max = " << max_iodd << std::endl;

	return 0;
}

