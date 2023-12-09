#include <cstdio>
#include <cmath>

int main()
{
    int x1;
    printf("x1 = ");
    scanf("%d", &x1);

    int y1;
    printf("y1 = ");
    scanf("%d", &y1);

    int x2;
    printf("x2 = ");
    scanf("%d", &x2);

    int y2;
    printf("y2 = ");
    scanf("%d", &y2);

    printf("%s", abs(x1-x2)==2 && abs(y1-y2)==1 || abs(x1-x2)==1 && abs(y1-y2)==2? "True" : "False");
    printf("\n");

    return 0;
}
