#include <cstdio>

int main()
{
    float x;
    printf("x = ");
    scanf("%f", &x);

    float a;
    printf("a = ");
    scanf("%f", &a);

    float b;
    printf("b = ");
    scanf("%f", &b);

    printf("%s", x >= a && x <= b ? "True" : "False");
    printf("\n");

    return 0;
}

