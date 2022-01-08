#ifndef IO
#define IO
#include <stdio.h>
#endif
#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* alloc: return pointer to n characters*/
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    else {
        return NULL;
    }
}

/* releases the storage acquired from alloc */
void afree(char *p)
{
    if (allocbuf <= p && p < allocbuf + ALLOCSIZE)
        allocp = p;
}