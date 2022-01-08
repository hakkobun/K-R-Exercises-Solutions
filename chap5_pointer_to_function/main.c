/* Questions */


/* what is (int (*)(void *, void *)) in the line that called kr_qsort for? */
/* what is the meaning of int in the front ? */
/* why can't we omit the 'int' */

/* seems like this (int (*)(void *, void *)) chunk can be omitted */


/* why do we need two *'s in (void **) in qsort*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mygetline.h"
#include "alloc.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void kr_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);


int main(int argc, char *argv[])
{
    int nlines;             /* number of input lines read */
    int numeric = 0;        /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        for (int i = 0; i < nlines; ++i)
            printf("converted to number as = %g\n", atof(lineptr[i]));
        kr_qsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}


/* kr_qsort: sort v[left]...v[right] into increasing order */
void kr_qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; ++i)
        if ((comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    kr_qsort(v, left, last - 1, comp);
    kr_qsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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