#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MAXLEN 5000

void delay(int seconds);
char* showtime(void);
void readlines(char *s /*, int maxlen */);
int strlen(char *s);
void strcpy(char *to, char *from);

int main()
{
    char original[MAXLEN];
    char copied[MAXLEN];
    readlines(original);
    strcpy(copied, original);

    printf("%s\n", copied);
    // // delay(1);
    // // system("clear");

    // destruct(copied);
    // printf("%s\n", copied);


    while(destruct(copied) >= 0) {
        printf("%s\n", copied);
        delay(50);
        for(int i = 0;i < 50; ++i)
            printf("\n");
        // printf("long have you wait\n");
        // printf("%s", showtime());

    }
    delay(3000);

    printf("Now, that you have destroyed everything, you are once again, free to create\n");

}

void delay(int seconds)
{
    int milliseconds = seconds * 1000;
    clock_t start = clock();
    while (start + milliseconds > clock())
        ;
}

char* showtime()
{
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    return asctime(timeinfo);
}
/* read the input text and stores it in the string array, return a positive number if it fits, and -1 otherwise */
void readlines(char *s /*, int maxlen */)
{
    int c;

    while((c = getchar()) != EOF)
        *s++ = c;

    *s = '\0';
    return ;
}

int strlen(char *s)
{
    int i;
    i = 0;
    while (*s++)
        i++;
    return i;
}

void strcpy(char *to, char *from)
{
    while (*to++ = *from++)
        ;
}

int destruct(char *s)
{
    int len = strlen(s);
    if (!len)
        return -1;
    s[len-1] = '\0';
    return len - 1;
}

