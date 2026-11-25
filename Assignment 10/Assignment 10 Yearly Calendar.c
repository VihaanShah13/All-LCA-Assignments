#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, day;
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("Enter year: ");
    scanf("%d", &year);

    // Check leap year
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        days[1] = 29;
    }

    // Find first day of the year
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = 0;
    date.tm_mday = 1;

    time_t t = mktime(&date);
    struct tm *first = localtime(&t);

    int start = first->tm_wday;

    // Print all 12 months
    for (month = 0; month < 12; month++)
    {
        printf("\n\n       %s %d\n", months[month], year);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        // Print blank spaces
        for (day = 0; day < start; day++)
        {
            printf("    ");
        }

        // Print dates
        for (day = 1; day <= days[month]; day++)
        {
            printf("%4d", day);

            if ((start + day) % 7 == 0)
                printf("\n");
        }

        // Calculate starting day of next month
        start = (start + days[month]) % 7;
    }

    return 0;
}