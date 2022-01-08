#include <stdio.h>
#include <string.h>

#define MAXLEN 100

/* recursive version of the function reverse(s) */

void reverse(char [], int, int);

int main()
{

	char s[MAXLEN] = "al";

	reverse(s, strlen(s), 0);
	printf("%s\n", s);

	return 0;
}

void reverse(char s[], int len, int i)
{
    char tmp;

    if (2*(i+1) < len)
        reverse(s, len, i+1);
    
    tmp = s[i];
    s[i] = s[len-i-1];
    s[len-i-1] = tmp; 
}




