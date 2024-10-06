#include <cstdio>

int main()
{
    unsigned int n;
    printf("Введите четырехзначеное число: ");
    scanf("%d", &n);

    printf("%s\n", n / 1000 + n / 100 % 10 == n % 100 / 10 + n % 10 ? "True" : "False");

    return 0;
}
