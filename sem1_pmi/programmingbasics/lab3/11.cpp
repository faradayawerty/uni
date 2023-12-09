#include <cstdio>

int main()
{
    int x;
    printf("x = ");
    scanf("%d", &x);

    int y;
    printf("y = ");
    scanf("%d", &y);

    int z;
    printf("z = ");
    scanf("%d", &z);

    printf("%s", x == y && y == z ? "True" : "False");
    printf("\n");

    return 0;
}
