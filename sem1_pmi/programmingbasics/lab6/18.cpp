#include <cstdio>

int main()
{
	char ans;
	printf("Хотите ли вы сходить первым? (y/n) ");
	scanf("%c", &ans);

	bool computer_turn;
	if(ans == 'y') {
		computer_turn = true;
	} else if (ans == 'n') {
		computer_turn = false;
	} else {
		printf("Ответ должен быть либо y либо n!!\n");
		return 1;
	}

	int n, d, s = 0;
	printf("n = ");
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		computer_turn = !computer_turn;
		printf("$ ");

		if(computer_turn) {
			d = 9 - s%9;
			printf("%d\n", d);
		} else {
			scanf("%d", &d);
		}

		s += d;
	}

	if(s % 9 == 0 && computer_turn)
		printf("Число делится на 9, побеждает компьютер!");
	else if(s % 9 == 0 && !computer_turn)
		printf("Число делится на 9, вы победили!");
	else if(s % 9 != 0 && computer_turn)
		printf("Число не делится на 9, вы победили!");
	else if(s % 9 != 0 && !computer_turn)
		printf("Число не делится на 9, побеждает компьютер!");
	printf("\n");
	
	return 0;
}

