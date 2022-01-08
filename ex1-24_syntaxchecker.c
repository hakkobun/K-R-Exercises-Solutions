#include <stdio.h>
#define MAXLEN 1000
int main()
{
    int c, i;
    char mystack[MAXLEN];

    i = 0;
    while ((c=getchar())!=EOF) {
        if (c=='(' || c=='{' || c=='[')
            mystack[i++] = c;
        else if (c==')') {
            if (i>0 && mystack[--i] == '(')
                mystack[i]

            else {
                printf("invalid");
                return 0;
            }
        }
    }
  
	return 0;
}