#include <cstdio>

bool has5(int n)
{
    bool has_five = false;
    while(n != 0) {
        if (n%10 == 5)
            has_five = true;
        n /= 10;
    }
    
    return has_five;
}

int main()
{
    unsingned int n;
    printf("Введите трехзначное число: ");
    scanf("%d", &n);

    printf("%s", has5(n) ? "True" : "False");
    printf("\n");

    return 0;
}
