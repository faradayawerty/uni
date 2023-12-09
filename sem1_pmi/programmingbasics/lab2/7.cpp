#include <cstdio>
#include <cmath>

int main()
{
    float alpha, beta, gamma, r;
    printf("Enter three angles of a triangle in degrees: ");
    scanf("%f %f %f", &alpha, &beta, &gamma);

    if (abs(alpha + beta + gamma - 180.0) >= 0.0001) {
        printf("Angles must add up to 180°!\n");
        return 1;
    }

    printf("Enter the radius of enscribed circle: ");
    scanf("%f", &r);
    
    printf("Triangle sides: %.4f %.4f %.4f\n",
        2*r*sin(alpha * M_PI / 180),    
        2*r*sin(beta * M_PI / 180),
        2*r*sin(gamma * M_PI / 180));

    return 0;
}

