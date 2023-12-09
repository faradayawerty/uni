#include <cstdio>
#include <cmath>

int main()
{
    float x;
    printf("x = ");
    scanf("%f", &x);
    
    printf("a) %.4f\n", cos(x) + cos(x)*cos(x)/sqrt(x - 1) + tan(x));
    printf("b) %.4f\n", log(x*x*x)/log(3) + pow(2, x-2));

    return 0;
}

