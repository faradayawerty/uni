#include <cstdio>

int main()
{
    float x;
    printf("x = ");
    scanf("%f", &x);

    float y;
    printf("y = ");
    scanf("%f", &y);

    float z;
    printf("z = ");
    scanf("%f", &z);

    printf("%s", x > 0 && y > 0 && z > 0 ? "True" : "False");
    printf("\n");

    return 0;
}
