/* String Utility Functions */

#include "share.h"

/* mystrcmp: >0 means s is lexicographically greater than t */
int mystrcmp(char *s, char *t, int option)
{
	int len = prefixlen;
	if (option == PREFIX) {
		for (; *s == *t; len--, s++, t++)
			if (len == 1)
				return 0;
	}
	else
		for(; *s == *t; s++, t++)
			if (*s == '\0')
				return 0;

	return *s - *t;
}


/* duplicate either WHOLE or just PREFIX */
char *mystrdup(char *s, int option)
{
	char *p;
	int len = (option == PREFIX ? prefixlen : mystrlen(s));
	p = (char *) malloc(len + 1);
	if (p != NULL)
		mystrcpy(p, s, option);
	return p;
}

/* copy either WHOLE or just PREFIX */
void mystrcpy(char *s, char *t, int option)
{
	if (option == PREFIX) {
		int len = prefixlen;
		for(; len-- > 0;)
			*s++ = *t++;
		*s = '\0';
	} else 
		while (*s++ = *t++)
			;
}

int mystrlen(char *s)
{
	int len = 0;
	while(*s++)
		len++;
	return len;
}
