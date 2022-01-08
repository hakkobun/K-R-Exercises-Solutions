#include <stdio.h>
#define YES 1
#define NO  0



int main()
{
    int cur, prev, reg;
    int incom, instr;

    incom = instr = NO;
    reg = prev = -1;

    while ((cur=getchar()) != EOF) {
        if (instr == YES) {
            if (cur=='\"' && prev!='\\')
                instr = NO;
            reg = prev;
            prev = cur;
        }
        else if (incom == YES) {
            if (cur=='/' && prev=='*') {
                incom = NO;
                reg = prev = -1;
            }
            else {
                reg = prev;
                prev = cur;
            }
        }
        else {
            if (cur=='*' && prev=='/')
                incom = YES;
            else if (cur=='\"')
                instr = YES;
            reg = prev;
            prev = cur;
        }
        if (reg!=-1 && incom==NO)
            putchar(reg);
    }
    if(prev != -1)
        putchar(prev);

    return 0;
}
