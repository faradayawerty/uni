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

    printf("%s", x+y>z && x+z>y && y+z>x? "True" : "False");
    printf("\n");

    return 0;
}
