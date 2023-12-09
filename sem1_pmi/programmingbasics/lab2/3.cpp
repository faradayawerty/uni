#include <cstdio>

int main()
{
    int n;
    printf("enter a three digit number: ");
    scanf("%d", &n);

    printf("%d\n", n + 1000 * (n%10));

    return 0;
}

