#include <cstdio>

#define BULL_COST 10
#define COW_COST 5
#define CALF_COST 0.5

#define MONEY 100
#define NUMBER_OF_ANIMALS 100

int main()
{
	// a, b, c - стоимость быка, коровы, теленка в рублях
	// i, j, k - количество быков, коров, телят
	//
	// ai + bj + ck = 100 рублей
	// i + j + k = 100 голов

	for(int i = 0; i <= NUMBER_OF_ANIMALS; i++)
	for(int j = 0; j <= NUMBER_OF_ANIMALS; j++)
	for(int k = 0; k <= NUMBER_OF_ANIMALS; k++)
		if(i + j + k == 100 && BULL_COST*i + COW_COST*j + CALF_COST*k == MONEY)
			printf("%d быков, %d коров, %d телят\n", i, j, k);

	return 0;
}

