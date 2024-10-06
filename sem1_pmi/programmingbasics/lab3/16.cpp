#include <cstdio>

int main()
{
    float x;
    printf("x = ");
    scanf("%f", &x);

    float y;
    printf("y = ");
    scanf("%f", &y);

    float r;
    printf("r = ");
    scanf("%f", &r);

    printf("%s", (x-1)*(x-1) + y*y >= r*r ? "True" : "False");
    printf("\n");

    return 0;
}
