#include <cstdio>
#include <ctime>

#define PASSPORT_AGE 14
#define DRIVING_RIGHTS_AGE 16
#define DUMA_ELECTION_AGE 21

int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int today_day = tm.tm_mday,
        today_month = tm.tm_mon + 1,
        today_year = tm.tm_year + 1900;
    //printf("%d %d %d\n", today_day, today_month, today_year);

    int user_day, user_month, user_year;

    printf("Введите день своего рождения: ");
    scanf("%d", &user_day);

    printf("Введите номер месяца своего рождения: ");
    scanf("%d", &user_month);
    
    printf("Введите год своего рождения: ");
    scanf("%d", &user_year);

    if (user_day == today_day && user_month == today_month)
        printf("С днем рождения !!\n");

    int age = today_year - user_year - 1;
    age += today_month > user_month
        || today_month == user_month && today_day <= user_day ? 1 : 0;

    if (age >= PASSPORT_AGE)
        printf("Вы можете получать паспорт РФ.\n");
    if (age >= DRIVING_RIGHTS_AGE)
        printf("Вы можете получать права на вождение РФ.\n");
    if (age >= DUMA_ELECTION_AGE)
        printf("Вы можете избираться в думу РФ.\n");

    return 0;
}
