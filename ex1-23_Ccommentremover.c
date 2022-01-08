
// /* this program removes all comments from a C program */

// "/*this is not to be removed*/"

#include <stdio.h>
#define IN  1
#define OUT 0
int main()
{
    int cur, prev, reg;
    prev = -1;
    reg = -1;

    int comment_state;
    comment_state = OUT;

    while ((cur = getchar())!=EOF) {
        if (prev == '/' && cur == '*') {
            comment_state = IN;
            reg = prev;
            prev = cur;
        }
        else if (prev == '*' && cur == '/') {
            comment_state = OUT;
            reg = prev = -1;
        }
        else {
            reg = prev;
            prev = cur;
        }
        
        if (reg != -1 && comment_state == OUT)
            putchar(reg);
                            
    }
    if(prev != -1)
        putchar(prev);
    
    return 0;
}



// go into string if encounter "
// get out of string if encounter " and the previous one wasn't





