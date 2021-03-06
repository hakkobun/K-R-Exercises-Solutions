#include <stdio.h>
#define MAXLINE 3200

void myreverse(char s[]);
int mygetline(char line[], int maxline);


/* myreverse: reverses its input a line at a time */
int main()
{
    char line[MAXLINE];
    int len;

    while ((len = mygetline(line, MAXLINE)) > 0) {
        myreverse(line);
        printf("%s", line);
    }

    return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (i < lim-1 && (c = getchar())!=EOF && c!='\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* myreverse: reverses character string s */
void myreverse(char s[])
{
    int i, len;
    for (len=0; s[len]!='\n' && s[len]!= '\0'; ++len)
        ;
    for (i=0; i<len/2; ++i) {
        char tmp;
        tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}