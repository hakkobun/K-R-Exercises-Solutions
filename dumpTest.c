#include <stdio.h>
#include <string.h>
#define VTAB '\013'
#define BELL '\x7'

int dummy() {}

enum horniness {TIFA, ADA, YOUKO, MIA, SONG, ROBIN};

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

void multi_array_func();

int main()
{

    int c;

    c = getchar();

    if(c == '\t')
        putchar(c);
    else
        putchar('X');

    printf("%d [%c]", c, c);


    // int myfunc(void);
    
    // printf("%d", myfunc());

    // dummy();

    /* 
    int a[2];
    a[0] = 5;
    a[1] = 6;

    int i = 0;

    a[i] = ++i;

    printf("%d %d", a[0], a[1]);
    */

    // printf("\"");


    // char a[5] = "x\n\b";
    // printf("%s", a);

    // int x = 0;
    // printf("%d\n", ++x);
    // printf("%d", x);

    // printf("%c", BELL);

    // char str[] = "hello             \"\"wow";

    // printf("%s", str);

    // printf("%d", TIFA);
    // printf("%d", ADA);

    // printf("k%c%cm", VTAB, VTAB);
}

int myfunc(void)
{
    return 55;
}


void multi_array_func()
{

}

