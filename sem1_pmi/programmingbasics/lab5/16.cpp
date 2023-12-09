#include <iostream>

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n*m; i++)
		if(i % m == 0 || i % n == 0)
			std::cout << i << std::endl;
	return 0;
}

