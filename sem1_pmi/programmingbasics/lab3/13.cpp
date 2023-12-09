#include <cstdio>

int main()
{
    float a;
    printf("a = ");
    scanf("%f", &a);

    float b;
    printf("b = ");
    scanf("%f", &b);

    float c;
    printf("c = ");
    scanf("%f", &c);

    printf("%s", b*b - 4*a*c < 0 ? "True" : "False");
    printf("\n");

    return 0;
}
