#include <stdio.h>
#include <ctype.h>
#include "calc.h"


int test_static()
{
	
	extern int bufp;	// error cuz we wrote "static int bufp"
	return bufp;
}


/* retrieve the next operator or operand */
int getop(char s[])
{
    /* skip blanks and tabs */
    int c, i;
    while ((s[0] = c = getch())=='\t' || c==' ')
        ;
    s[1] = '\0';
    
    
    if (!isdigit(c) && c!='.') {                    /* if not digit or decimal point, return it */
        if (s[0] == '-') {
            c = getch();
            if (c == '.')
                s[1] = c;
            /* else if ('a' <= s[0] && s[0] <= 'z') */
            else {
                ungetch(c);
                if (!isdigit(c))
                    return s[0];
            }
        }   
        else if ('a' <= s[0] && s[0] <= 'z') {
            cur_var = s[0] - 'a';
            return VARIABLE;                        /* signal for variable */
        }
        else
            return s[0];
    }


    // if (!isdigit(c) && c!='.')
    //     return c;


    i = (s[1] == '\0') ? 0 : 1;
    /* otherwise collect the string of digits and return NUMBER */
    if (isdigit(c))         /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')           /* collect the fractional part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}