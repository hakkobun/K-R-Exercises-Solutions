#include <stdio.h>
#include "ex1-21_entab.h"
#define MAXLEN 1000

/* Exercise 1-20 & 1-21 TWO IN ONE */


void detab(char[], int);
int mygetline(char[], int);

int main()
{
	int len;
	char s[MAXLEN];

	while ((len = mygetline(s, MAXLEN)) > 0)
		// detab(s, 4);
		entab(s, 4);
	
	return 0;
}


/* replaces tabs in the input with the proper number of blanks to space to the next tab stop */
void detab(char s[], int n)
{
	int i, j, len;

	for (i = 0, j = 0, len = 0; s[i] != '\0'; ++i)
		if (s[i] != '\t') {
			putchar(s[i]);
			j = (j+1) % n;
			++len;
		}
		else {
			len += n-j;
			for (; j < n; ++j)
				putchar(' ');
			j = 0;
		}
	printf("\nLen = %d\n", len);
}

int mygetline(char s[], int lim)
{
	int i, c;

	for (i = 0; --lim>0 && (c=getchar())!=EOF && c!='\n';)
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
	
}