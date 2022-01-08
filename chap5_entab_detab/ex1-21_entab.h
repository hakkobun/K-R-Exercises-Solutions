#include <stdio.h>

/* replaces a string of blanks by the minimum number of tabs and blanks to achieve the same spacing */
void entab(char s[], int n)
{
    int i, last;

    for (i=0, last=0; s[i] != '\0'; ++i) {
        if (i % n == n - 1)
            s[last++] = '\t';
    }

    last += i % n;
    s[last] = '\0';

    printf("before = %d, after = %d\n", i, last);
    printf("%s\n", s);

}