#include <stdio.h>
#include "ex5-4_strend.h"
// #include <string.h>
#define MAXLEN 1000

char *strcat(char *, char *);

/* detected a behavior: declaring char a[] = "string", then concatenating it with a string b, makes b[0] disappeared. */
int main()
{
    char a[MAXLEN] = "012345234567";
    char b[MAXLEN] = "2345";

    /* 5-4 strend.h test */

    printf("strend check = %d\n", strend(a,b));


    /* end of 5-4 testing */


    /* 5-3 strcat test*/ 
    // printf("%d\n", *(a + strlen(a)) == '\0');
    // printf("%d\n", *(a + strlen(a) + 1) == '\0');
    // printf("%d\n", *(a + strlen(a) + 2) == '\0');
    // printf("%d\n", *(a + strlen(a) + 3) == '\0');
    // printf("%d\n", *(a + strlen(a) + 4) == '\0');

    // printf("%d\n", *(b + strlen(b)) == '\0');
    // printf("%d\n", *(b + strlen(b) + 1) == '\0');
    // printf("%d\n", *(b + strlen(b) + 2) == '\0');
    // printf("%d\n", *(b + strlen(b) + 3) == '\0');
    // printf("%d\n", *(b + strlen(b) + 4) == '\0');

    
    // printf("%d %d\n", strlen(a), strlen(b));    
    // char *c = strcat(a,b);
    
    // printf("a = %s\n", a);
    // printf("b = %s\n", b);
    // printf("c = %s\n", c);
    // printf("%d %d\n", strlen(a), strlen(b));    /* strlen(b) is 1 character short, b[0] is gone! */

    /* end of 5-3 testing */

}

char *strcat(char *s, char *t)
{
    char *p = s;

    while(*p != '\0')
        ++p;
    while((*p++ = *t++))
        ;
    return s;
}
