/* This program sorts a set of text lines into alphabetic order */
/* It will also modify the function readlines: see below for details */


#ifndef IO
#define IO
#include <stdio.h>
#endif

#include <string.h>     /* for strcmp, strcpy */
#include "mygetline.h" 

#define debugp(i) printf("debug @ %d\n", i)


#define MAXLINES 5000
#define BUFFERSIZE 1000

char *lineptr[MAXLINES];

int readlines(char *[], int, char [], int);
void qsort(char *[], int, int);
void writelines(char *[], int);

int main()
{
    int nlines;     /* number of input lines read */
    char buffer[BUFFERSIZE];

    // debugp(-1);
    if ((nlines = readlines(lineptr, MAXLINES, buffer, BUFFERSIZE)) >= 0) {
        // debugp(0);
        qsort(lineptr, 0, nlines - 1);
        // debugp(1);
        writelines(lineptr, nlines);
        // debugp(2);
        return 0;
    }
    else {
        // debugp(3);
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
/* readlines: read input lines and store lines in an array supplied by main */
int readlines(char *lineptr[], int maxlines, char buffer[], int maxbuffer)
{
    int len, nlines;
    char line[MAXLEN];
    
    char *nbuf = buffer;

    char temp, templen;

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || buffer + maxbuffer - nbuf < len)
            return -1;  /* insufficient space */
        else {
            temp = line[len-1]; /* saving the last letter of the last line */
    
            line[len-1] = '\0'; /* delete newline */
            strcpy(nbuf, line);    /* copy the string in array <line> to <allocbuf> */
            lineptr[nlines++] = nbuf;
            nbuf += len;
        }

    nbuf[0] = '\0';      /* fixing the last letter of the last line, assuming it doesn't exceed ALLOCBUF */
    nbuf[-1] = temp;
    return nlines;
}


void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; ++i)
        printf("%s\n", lineptr[i]);
}


void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; ++i)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}