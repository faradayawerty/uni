#include <iostream>

int main()
{
	int A, B;
	std::cin >> A;
	std::cin >> B;

	int s = 0;

	for(int i = A/4; i <= B/4; i++) {
		s += 4*i;
		std::cout << 4*i << " + ";
	}
	std::cout << "\b\b= " << s << std::endl;

	return 0;
}

