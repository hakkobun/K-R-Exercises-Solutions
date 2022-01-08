#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>   /* unlike printf in stdio.h */
                    /* we need to run "cc main.c -lm" to LINK the math lib to the program, otherwise "undefined reference to sin" error */
#include "calc.h"
#define MAXOP 100


int main()
{
    int type;
    double op2;     /* tmp variable to collect 2 top most values from stack */
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case VARIABLE:
                push(get_var(cur_var));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                printf("minus\n");
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(mod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case SIN: /* radians */
                push(sin(pop()));
                break;
            case EXP: /* return e^x */
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(),op2));
                break;
            case PRINTTOP:
                printtop();
                break;
            case DUPLICATE_TOP:
                duplicate_top();
                break;
            case SWAP_TOPS:
                swap_tops();
                break;                
            case CLEAR:
                clear();
                break;
            case '\n':      /* create new variable */
                op2 = pop();
                new_var(op2);
                // printf("\t%.8g\n", op2);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

int mod(int a, int b)
{
    int r = a % b;
    return (r<0) ? r+abs(b) : r;
}