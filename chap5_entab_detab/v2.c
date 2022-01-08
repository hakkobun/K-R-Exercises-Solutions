#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define DEFAULT_TAB 5

int mygetline(char[], int);

/* modified version of detab. accept a list of tab stops as arguments. */
/* using zero-indexing. So the earliest tab stop possible is 1 */
/* the default tab-stops are at position (DEFAULT_TAB * N) */

int main(int argc, char *argv[])
{
	int len;
	char s[MAXLEN];

	int i;
	int n;		/* total letter printed so far */

	int cur_arg;
	int next_stop;	/* so that we don't have to call atoi twice */

	while ((len = mygetline(s, MAXLEN)) > 0) {
		cur_arg = 1;
		n = 0;
		for (i = 0; s[i] != '\0'; ++i) 
			if (s[i] != '\t') {
				putchar(s[i]);
				n++;
			}
			else {
				while (cur_arg < argc && n >= (next_stop = atoi(argv[cur_arg])))
					cur_arg++;
				if (cur_arg < argc)								/* one of the args */
					for (; n < next_stop; ++n)
						putchar(' ');
				else {		/* cur_arg == argc */				/* default tab stops (after all args) */
					n %= DEFAULT_TAB;
					while (n++ < DEFAULT_TAB)
						putchar(' ');
					n = 0;
				}
			}
	}
	return 0;
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