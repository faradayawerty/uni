#include <cstdio>
#include <cmath>

/* THE function */
long int f(int, int);

/* finds all possible integer values for THE function */
int main()
{
    int x, a;
    printf("x = ");
    scanf("%d", &x);
    printf("a = ");
    scanf("%d", &a);

    printf("y = %d\n", f(x, a));

    return 0;
}

long int f(int x, int a)
{
    return (long int)(abs(pow(x, 5) + abs(a*x - pow(x, 3)) - a) + a*pow(x, 2) + pow(a, 8));
}

