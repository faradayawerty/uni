#include <cstdio>
#include <cmath>

int main()
{
    float ax, ay, bx, by;
    printf("Enter the coordinates of point A: ");
    scanf("%f %f", &ax, &ay);
    printf("Enter the coordinates of point B: ");
    scanf("%f %f", &bx, &by);

    printf("AB = %.2f\n", sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by)));
    printf("Center of AB: (%.2f, %.2f)\n", (ax+bx)/2, (ay+by)/2);

    return 0;
}

