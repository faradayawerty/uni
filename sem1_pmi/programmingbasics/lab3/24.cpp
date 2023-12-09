#include <cstdio>

int main()
{
    unsigned int k;
    printf("k = ");
    scanf("%d", &k);
    
    // a
    printf("Мы нашли в лесу %d гриб", k);
    if (k%100 >= 10 && k%100 < 20)
        printf("ов");
    else if (k%10 == 0 || k%10 > 4)
        printf("ов");
    else if (k%10 < 5 && k%10 != 1)
        printf("а");
    printf("\n");

    // b
    printf("Мы купили на всех %d пицц", k);
    if (k%100 >= 10 && k%100 < 20)
        printf("");
    else if (k%10 == 0 || k%10 > 4)
        printf("");
    else if (k%10 < 5 && k%10 != 1)
        printf("ы");
    else if (k%10 == 1)
        printf("у");
    printf("\n");

    // c
    printf("Я сегодня прошел %d уров", k);
    if (k%100 >= 10 && k%100 < 20)
        printf("ней");
    else if (k%10 == 0 || k%10 > 4)
        printf("ней");
    else if (k%10 < 5 && k%10 != 1)
        printf("ня");
    else if (k%10 == 1)
        printf("ень");
    printf(" в игре\n");

    return 0;
}
