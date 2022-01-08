#include <stdio.h>
#define MAXLINE 3200

void myremove(char s[]);
int mygetline(char line[], int maxline);


/* myremove: remove any trailing blanks and tabs from each line of input, and to delete entirely blank lines */
int main()
{
    char line[MAXLINE];
    int len;

    while ((len = mygetline(line, MAXLINE)) > 0) {
        myremove(line);
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

/* myremove: remove any trailing blanks and tabs from a line */
void myremove(char s[])
{
    int i, islastline;

    islastline = 0;
    
    for (i=0; s[i] != '\0'; ++i) 
        ;
    if (i==0 || s[--i]!='\n') 
        islastline = 1;
    for (; i>=0 && (s[i]=='\n' || s[i]==' ' || s[i]=='\t'); --i)
        ;
    if (!islastline && i!=-1)
        s[++i] = '\n';
    s[++i] = '\0';
}