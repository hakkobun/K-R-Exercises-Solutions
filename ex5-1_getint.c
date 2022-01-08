#include <ctype.h>
#include "getch.h"
#define MAXSIZE 100

int main()
{
    int n, a[MAXSIZE], getint_TEXTBOOK(int *);

    for (n = 0; n < MAXSIZE && getint_TEXTBOOK(&a[n]) != EOF; n++)
        ;

    int i;
    for (i = 0;i <= n; ++i)
        printf("%2d : %d\n", i, a[i]);

    return 0;
}




/* get next integer from input into *pn */
/* returns EOF, 0 (not a number) or Positive value (valid number) */
int getint_TEXTBOOK(int *pn)
{

    int c, temp, sign;

    while (isspace(c = getch())) 
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        temp = c;
        if (!isdigit(c = getch())) {

            printf("temp = %c c = %c\n", temp, c);
            ungetch(c);
            ungetch(temp);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    return c;    
}