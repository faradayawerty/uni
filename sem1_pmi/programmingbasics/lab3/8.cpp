#include <cstdio>

int main()
{
    int k;
    printf("k = ");
    scanf("%d", &k);

    printf("%s", k % 7 == 0 ? "True" : "False");
    printf("\n");

    return 0;
}
