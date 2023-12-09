#include <iostream>

#define TEMPLATE_SIZE 5

int main()
{
	int word_template[TEMPLATE_SIZE] = {10, 20, 30, 40, 50};
	int word[TEMPLATE_SIZE] = {0, 0, 0, 0, 0};

	// найдем пять тысяч сто двадцать третье слово (отсчет с нуля)
	int n = 5123;
	
	for(int i = TEMPLATE_SIZE-1; i >= 0; i--) { 
		word[i] = n % word_template[i];
		n /= word_template[i];
	}

	// напечатаем найденное слово
	for(int i = 0; i < TEMPLATE_SIZE; i++)
		std::cout << word[i] << ' ';
	std::cout << std::endl;


	// найдем номер нового слова {0, 0, 2, 22, 23}
	int new_word[TEMPLATE_SIZE] = {0, 0, 2, 22, 23};
	int m = 0;
	int p = 1;
	for(int i = TEMPLATE_SIZE-1; i >= 0; i--) {
		m += p*new_word[i];
		p *= word_template[i];
	}
	std::cout << m << std::endl;

	return 0;
}

