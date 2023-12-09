#include <cstdio>

int main()
{
    unsigned int s;
    printf("enter the number of seconds since the start of the day: ");
    scanf("%d", &s);

    /* check if the entered number is bigger than 24 hours */
    if (s >= 86400) {
        printf("there is only 86400 seconds in a day!!\n");
        return 1;
    }

    /* get minutes */
    int m = s / 60;
    s %= 60;
    
    /* get hours */
    int h = m / 60;
    m %= 60;

    /* print time in format hh:mm:ss */
    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}

