#ifndef IO
#define IO
#include <stdio.h>
#endif

#define MAXLEN 1000 /* max length of any input line */

/* getline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}