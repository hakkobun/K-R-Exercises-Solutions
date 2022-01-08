#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"
#define MAXOP 100

#define dprint(expr) printf(#expr "= %c\n", expr)

int main(int argc, char *argv[])
{
    double op2;
    while (--argc > 0 && argv++) {

        // dprint(**argv);
        switch(**argv) {
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                // printf("minus\n");
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
            default:
                push(atof(*argv));
                break;
        }
    }

    if (getStackSize() != 1) {
        printf("Illegal Calculation\n");
        return -1;
    }
    else {
        printf("Calculated Value: %g\n", pop());
    }
   
    return 0;
}
