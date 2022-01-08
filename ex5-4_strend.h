#include <stdio.h>

int strlen(char *p)
{
    int i = 0;
    while(*p++)
        i++;
    return i;
}

/* substrcmp: return 1 if subarray starting with s contains t, and zero otherwise */
int substrcmp(char *s, char *t)
{
    for (; *s == *t; ++s, ++t)
        ;
    if (*t == '\0')
            return 1;
    return 0;

}


/* strend: return 1 if the string t occurs at the end of string s, and zero otherwise */
int strend(char *s, char *t)
{
    char *p;
    int len_t = strlen(t);

    p = s;
    while (*p) {
        if (substrcmp(p, t) && p[len_t] == '\0')
            return 1;
        ++p;
    }
    return 0;
}