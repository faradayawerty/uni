#include <cstdio>
#include <cstdlib>
#include <ctime>

#define DIFFICULTY_RANDOM 0
#define DIFFICULTY_EASY 1
#define DIFFICULTY_MEDIUM 2
#define DIFFICULTY_HARD 3

#define FIRST_TURN_RANDOM 0
#define FIRST_TURN_PLAYER 1
#define FIRST_TURN_COMPUTER 2

int player_choose_difficulty();
int player_choose_first_turn();
int player_choose_n();

 // возвращает количество камней после хода компьютера
int make_computer_turn(int number_of_stones, int difficulty);

 // возвращает количество камней после хода игрока
int make_player_turn(int number_of_stones);

void print_info();
void get_result(int number_if_turns, bool computer_last_turn);

int main()
{
	// инициализация
	int difficulty = player_choose_difficulty();
	bool computer_turn = player_choose_first_turn() == FIRST_TURN_COMPUTER;
	int n = player_choose_n();
	int c = 0;

	print_info();

	// ход игры
	while(n > 0) {
		printf("В куче %d камней\n", n);
		if(computer_turn)
			n = make_computer_turn(n, difficulty);
		else
			n = make_player_turn(n);

		computer_turn = !computer_turn;
		c++;
		printf("\n");
	}

	// подведение итогов
	get_result(c, !computer_turn);

	return 0;
}

void get_result(int c, bool b)
{
	if(b)
		printf("Компьютер выиграл за %d ходов\n", c);
	else
		printf("Вы выиграли за %d ходов\n", c);
}

void print_info()
{
	printf("Список доступных команд:\n");
	printf("\t1 - взять один камень из кучи\n");
	printf("\t2 - половину всех камней из кучи\n");
	printf("\n");
}

int make_player_turn(int n)
{
	int command;

	while(true) {
		printf("Ваш ход: ");
		scanf("%d", &command);
		if(n%2 == 1 && command == 2)
			printf("\tВы не можете убрать половину камней из кучи, т.к. их нечетное количество\n");
		else if(command > 2 || command < 1)
			printf("\tВозможны только команды 1 и 2 !!\n");
		else
			break;
	}

	if(command == 1) {
		printf("\tВы убрали один камень из кучи\n");
		return n - 1;
	} else if(command == 2) {
		printf("\tВы убрали половину камней из кучи\n");
		return n / 2;
	}

	return n;
}

int make_computer_turn(int n, int d)
{
	srand(time(NULL));

	int command;
	if(d == DIFFICULTY_EASY) {
		if(n%2 == 0)
			command = rand() % 2 + 1;
		else
			command = 1;
	} else if(d == DIFFICULTY_MEDIUM) {
		if(n > 10 && n%2 == 0)
			command = rand() % 2 + 1;
		if(n == 4)
			command = 2;
		else
			command = 1;
	} else if(d == DIFFICULTY_HARD) {
		if(n == 4)
			command = 2;
		else if(n%2 == 0 && (n/2) % 2 == 1 && n > 6)
			command = 2;
		else
			command = 1;
	}

	if(command == 1) {
		printf("\tКомпьютер убрал 1 камень из кучи\n");
		return n - 1;
	} else if(command == 2) {
		printf("\tКомпьютер убрал половину камней из кучи\n");
		return n / 2;
	}

	return n;
}

int player_choose_difficulty()
{
	printf("Выберите сложность\n");
	printf("\t%d - случайно\n", DIFFICULTY_RANDOM);
	printf("\t%d - компьютер не знает стратегию\n", DIFFICULTY_EASY);
	printf("\t%d - компьютер знает стратегию при достаточно маленьких N\n", DIFFICULTY_MEDIUM);
	printf("\t%d - компьютер знает стратегию\n", DIFFICULTY_HARD);
	printf("$ ");

	int d;
	scanf("%d", &d);

	if(d == DIFFICULTY_RANDOM) {
		srand(time(NULL));
		d = rand() % DIFFICULTY_HARD + DIFFICULTY_EASY;
	}

	if(d > DIFFICULTY_HARD)
		d = DIFFICULTY_HARD;

	printf("Выбрана сложность %d\n", d);
	return d;
}

int player_choose_first_turn()
{
	printf("Выберите, кто делает первый ход\n");
	printf("\t%d - случайно\n", FIRST_TURN_RANDOM);
	printf("\t%d - игрок\n", FIRST_TURN_PLAYER);
	printf("\t%d - компьютер\n", FIRST_TURN_COMPUTER);
	printf("$ ");

	int ans;
	scanf("%d", &ans);

	if(ans == FIRST_TURN_RANDOM) {
		srand(time(NULL));
		ans = rand() % FIRST_TURN_COMPUTER + FIRST_TURN_PLAYER; // FIRST_TURN_COMPUTER > FIRST_TURN_PLAYER, see the definition
	}

	return ans;
}

int player_choose_n()
{
	printf("Выберите первоначальное количество камней в куче\n");
	printf("\tподсказка: выберите 0, чтобы задать N случайным образом\n");
	printf("\tподсказка: N должно быть равно хотя бы двум\n");

	int n;
	while(true) {
		printf("$ ");
		scanf("%d", &n);
		if(n < 2 && n != 0)
			printf("N должно быть равно хотя бы двум!!!\n");
		else
			break;
	}

	int min_n = 5, max_n = 30;
	if(n == 0) {
		srand(time(NULL));
		n = rand() % (max_n - min_n + 1) + min_n;
	}

	return n;
}

