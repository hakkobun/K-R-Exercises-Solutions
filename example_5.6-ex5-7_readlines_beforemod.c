/* This program sorts a set of text lines into alphabetic order */
/* It will also modify the function readlines: see below for details */

/* Questions: */
/* Q1: Why do we have to use alloc ? What's the meaning behind (p = alloc(len)) ? */
/* A1: Allocbuf is where we actually store the characters. p moves along the array. And lineptr just marks certain position on the allocbuf array */
/* Q2: What does the line strcpy(p, line) do? */
/* A2: It copies all the characters in line that was read, onto allocbuf array starting at postion where p is pointing to */
/* Q3: Why do we have to delete the newline by line[len - 1] = '\0' */
/* A3: probably to save some storage in allocbuf, since every non-final line always have a '\n', so we just handle that with writeline instead of wasting space */
/* A3(continue) and also we have to collect the last character from the last line (in case the last line doesn't end with \n) */


#ifndef IO
#define IO
#include <stdio.h>
#endif

#include <string.h>     /* for strcmp, strcpy */
#include "alloc.h"
#include "mygetline.h" 

#define debugp(i) printf("debug @ %d\n", i)


#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *[], int);
void qsort(char *[], int, int);
void writelines(char *[], int);

int main()
{
    int nlines;     /* number of input lines read */
    // debugp(-1);
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
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
/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    char temp, templen;

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            temp = line[len-1];
            templen = len;      /* saving the last letter of the last line */

            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);    /* copy the string in array <line> to <allocbuf> */
            lineptr[nlines++] = p;
        }
    p[templen - 1] = temp;      /* fixing the last letter of the last line, assuming it doesn't exceed ALLOCBUF */
    p[templen] = '\0';
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

void swap(char *v[], int i, int j) /* works fine because v[i] and v[j] is a pointer anyway */
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}