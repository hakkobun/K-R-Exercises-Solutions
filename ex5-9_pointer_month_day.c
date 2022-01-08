#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    // int y, m, d;
    // scanf("%d%d%d", &y, &m, &d);
    // printf("day of year = %d\n", day_of_year(y, m, d));



    int year, yearday;
    scanf("%d%d", &year, &yearday);

    int pm, pd;
    month_day(year, yearday, &pm, &pd);
    printf("month = %d, day = %d\n", pm, pd);


    return 0;
}


/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];

    for (++p; p - daytab[leap] < month; ++p)
        day += *p;
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];

    for (++p; yearday > *p; ++p)
        yearday -= *p;
    *pmonth = p - daytab[leap];
    *pday = yearday;
}