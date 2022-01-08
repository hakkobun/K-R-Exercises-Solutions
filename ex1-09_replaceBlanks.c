#include<stdio.h>
// #define EOF 'x'

#define NOT_BLANK 0
#define BLANK 1

main(){
    int c, state;
    state = NOT_BLANK;
    while((c = getchar()) != EOF){
        if(c == ' ' && state == NOT_BLANK){
            state = BLANK;
            putchar(c);
        }
        else if(c != ' '){
            state = NOT_BLANK;
            putchar(c);
        }
    }
}