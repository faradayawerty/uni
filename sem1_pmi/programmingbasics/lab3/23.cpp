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

    float d;
    printf("d = ");
    scanf("%f", &d);

    printf("%s", a <= c && b <= d || a >= c && b >= d ? "True" : "False");
    printf("\n");

    return 0;
}
