#include <cstdio>

int main()
{
    int y;
    printf("y = ");
    scanf("%d", &y);

    printf("%s", (y%4==0 && y%100!=0) || y%400==0 ? "True" : "False");
    printf("\n");

    return 0;
}
