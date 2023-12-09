#include <iostream>

// возвращает a^3 + (a+1)^3 + ... + b^3
long int get_cubes_sum(int a, int b);

int main()
{
	long int s = 0;

	// неэффективный алгоритм (закомментировано, поэтому не выполняется)
	//
	//for(int i = 25; i <= 125; i++) {
	//	s += i*i*i;
	//}

	s = get_cubes_sum(25, 125);
	
	std::cout << s << std::endl;

	return 0;
}

// использует специальную формулу для нахождения суммы кубов от a до b (a < b)
long int get_cubes_sum(int a, int b)
{
	return b*b*(b+1)*(b+1) / 4 - a*a*(a-1)*(a-1) / 4;
}

