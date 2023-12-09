#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MIN(x, y) ((x) <= (y) ? (x) : (y))

int get_turn(int max_stones, int current_number_of_stones, bool knows_strategy);

int main()
{
	// для генерации рандомных чисел
	srand(time(NULL));

	int c = 0;

	//
	// выбор параметра сложности
	//
	int ans;
	int difficulty;
	printf("Выберите уровень сложности\n\t0 - компьютер не знает стратегию\n\t1 - компьютер знает стратегию при достаточно маленьких N\n\t2 - компьютер знает стратегию\n$ ");
	scanf("%d", &ans);
	difficulty = ans;

	//
	// выбор очередности ходов
	//
	bool computer_turn;
	printf("Выберите, кто ходит первым (0 - случайно, 1 - вы, 2 - компьютер): ");
	scanf("%d", &ans);
	if(ans == 0)
		computer_turn = rand() % 2;
	else
		computer_turn = ans - 1;

	//
	// выбор N
	//
	int n;
	printf("Выберите N\n\tПодсказка: напишите 0, чтобы выбрать N случайным образом\n$ ");
	scanf("%d", &n);
	if(n == 0) {
		n = rand() % 1000 + 5;
		printf("N = %d\n", n);
	}

	// защита от дурака
	if(n <= 1) {
		printf("N должно быть хотя бы 2!!\n");
		return 1;
	}

	//
	// выбор M
	//
	int m;
	printf("Выберите M\n\tПодсказка: напишите 0, чтобы выбрать M случайным образом\n$ ");
	scanf("%d", &m);
	if(m == 0 && n < 5)
		m = rand() % (n-1) + 1;
	else if (m == 0)
		m = rand() % (n/2) + 3;

	// защита от дурака
	if(m < 0) {
		printf("M не может быть отрицательным!!\n");
		return 1;
	}

	// защита от дурака
	if(m >= n) {
		printf("M должно быть меньше чем N!!\n");
		return 1;
	}

	printf("В куче %d камней. За один ход можно взять не более чем %d камней.\n\n", n, m);

	//
	// ход игры
	//
	int t;
	bool computer_knows_strategy;
	while(n > 0)
	{
		printf("В куче %d камней\n", n);
		if(computer_turn) {
			printf("\tХод компьютера: ");
			if(difficulty == 0)
				computer_knows_strategy = false;
			else if(difficulty >= 2)
				computer_knows_strategy = true;
			else if(difficulty == 1 && !computer_knows_strategy && n <= 3*m+7)
				computer_knows_strategy = true;
			else if(difficulty == 1 && computer_knows_strategy)
				computer_knows_strategy = true;
			else
				computer_knows_strategy = false;
			t = get_turn(m, n, computer_knows_strategy);
			printf("%d\n", t);
		} else {
			while(true) {
				printf("\tВаш ход: ");
				scanf("%d", &t);
				if(t <= m && t <= n && t > 0)
					break;
				else if (t <= 0)
					printf("Вы должны взять хотя бы один камень!!\n");
				else
					printf("Вы можете взять не более чем %d камней!!\n", MIN(m, n));
			} 
		}

		c++;
		n -= t;
		computer_turn = !computer_turn;
	}

	//
	// Итоги игры
	//
	printf("\nИТОГ: \n");
	printf("\tпобедитель: ");
	if(n == 0 && computer_turn) {
		printf("вы\n");
	} else if(n == 0 && !computer_turn) {
		printf("компьютер\n");
	}
	printf("\tколичество ходов: %d\n", c);

	return 0;
}

int get_turn(int m, int n, bool knows_strategy)
{
	if(knows_strategy)
	{
		if(n % (m+1) == 0)
			return rand() % MIN(n, m) + 1;
		else
			return n % (m+1);
	}
		
	return rand() % MIN(n, m) + 1;
}

