#include <cstdio>

bool square(int n)
{
    for(int i = 1; i*i <= n; i++)
        if (n == i*i)
            return true;
    return false;
}

int main()
{
    unsigned int n;
    printf("n = ");
    scanf("%d", &n);

    printf("%s", square(n) ? "True" : "False");
    printf("\n");

    return 0;
}
