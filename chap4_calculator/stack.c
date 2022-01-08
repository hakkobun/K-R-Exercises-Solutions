#include <stdio.h>
#include "calc.h"       /* not necessary */

#define MAXVAL 100      /* maximum depth of val stack */
#define MAXVAR 26
#define LETTER(i) i+'a'

static int sp = 0;             /* next free stack position */
static double val[MAXVAL];     /* value stack */

static int vp = 0;             /* next variable to be created*/
static double var[MAXVAR];     /* variable var[0] = a, var[1] = b and so on*/




/* create new variable, if there's enough space */
void new_var(double f)
{
    if (vp < MAXVAR) {
        var[vp++] = f;
        printf("new variable created: %c = %.8g\n", LETTER(vp-1), f);
    }
    else
        printf("number of variables exceeded MAXVAR:\t%.8g\n",f);
}

double get_var(int i)
{
    return var[i];
}


/* print the top element, without popping */
void printtop(void)
{
    if (sp == 0)
        printf("print top error: stack is empty\n");
    else {
        printf("\t%.8g\n", val[sp-1]);
    }
}

/* duplicate the top element */
void duplicate_top(void)
{
    if (sp == 0)
        printf("duplicate error: stack is empty\n");
    else {
        val[sp++] = val[sp-1];
        printf("top duplicated\n");
    }
}

/* swap top two elements */
void swap_tops(void)
{
    int tmp;

    if (sp < 2)
        printf("swap error: less than two elements in stack\n");
    else {
        tmp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = tmp;
        printf("top two elements swapped\n");
    }

}

/* clear the stack */
void clear(void)
{
    sp = 0;
    printf("stack is emptied\n");
}

/* push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}