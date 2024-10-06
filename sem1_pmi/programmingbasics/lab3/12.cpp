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

    printf("%s", (x == y && z != x && z != y) || (x == z && x != y && y != z) || (z == y && x != y && z != x) ? "True" : "False");
    printf("\n");

    return 0;
}
