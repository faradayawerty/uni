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

    float c;
    printf("c = ");
    scanf("%f", &c);

    float d;
    printf("d = ");
    scanf("%f", &d);

    printf("%s", (x >= a && x <= b) || (x >= c && x <= d) ? "True" : "False");
    printf("\n");

    return 0;
}
