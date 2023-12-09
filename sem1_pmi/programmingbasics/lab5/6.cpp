#include <iostream>

int main()
{
	for(int i = 100; i < 1000; i++) {
		if(i*i % 1000 == i)
			std::cout << i << std::endl;
	}

	return 0;
}

