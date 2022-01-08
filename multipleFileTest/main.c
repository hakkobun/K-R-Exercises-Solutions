#include <stdio.h>
#define MAXLINE 1000 

/* trying to compile multiple source programs */
/* 3 functions lies in 3 programs- main in main.c, f1 in f1.c, f2 in f2.c */

extern int f1(int x);
extern int f2();
int f3();

int main()
{
    
    printf("%d", f1(2) + f2() + f4());

    return 0;
}

int f3(int m)
{
    return m*2;
}