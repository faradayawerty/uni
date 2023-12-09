#include <cstdio>

int main()
{
    int n;
    printf("Введите число: ");
    scanf("%d", &n);

    int k;
    printf("Введите число: ");
    scanf("%d", &k);

    printf("%s\n", n%2 == k%2 ? "True" : "False");

    return 0;
}
