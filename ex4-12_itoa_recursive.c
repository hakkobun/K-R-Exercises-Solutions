#include <stdio.h>

#define MAXLEN 100

/* adapting the idea of printd to write a recursive version of itoa */

int i;
void printd(int n);
void itoa(char [], int);

int main()
{

	char s[MAXLEN];
	itoa(s, -3754769);

	printf("%s\n", s);

	return 0;
}


/* itoa: convert an integer into a string */
void itoa(char s[], int n)
{
	if (n < 0) {
		s[i++] = '-';	/* consider using putchar('-'); instead */
		n = -n;
	}

	if (n/10 > 0)
		itoa(s, n/10);
	s[i++] =  n%10 + '0';
}


/* printd: print n in decimal as a character string*/
void printd(int n)
{
	if (n < 0) {
		printf("-");	/* consider using putchar('-'); instead */
		n = -n;
	}

	if (n/10 > 0)
		printd(n/10);
	printf("%c", n%10 + '0');
}