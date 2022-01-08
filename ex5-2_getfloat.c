#include <stdio.h>
#include <ctype.h>
#include "getch.h"

#define MAXSIZE 100

int getfloat(double *pn);
double atof(char *);

int main()
{
	// char s[] = "-3532.1";
	// printf("%g\n", atof(s));

	double array[MAXSIZE];
	int i, n;
	for (n = 0; n < MAXSIZE && getfloat(&array[n]) != EOF ; ++n)
		;
	for (i = 0; i <= n; ++i)
		printf("%d: %5g\n", i, array[i]);
	return 0;
}


/* getfloat: get next float from input into *pn */
int getfloat(double *pn)
{
    int c, sign;

	double power;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 1; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;	
	}	
	*pn *= sign / power;
	if (c != EOF)
		ungetch(c);
	return c;
}

/* atof: convert string s to double */
double atof(char *s)
{

    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = val * 10.0 + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = val * 10.0 + (s[i] - '0');
		power *= 10.0;
    }
	return sign * val / power;
}
