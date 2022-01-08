/* i prototyped in this one */
/* the final version is v2.c which is way better, way simplified ( I accomplished that after slowly asking myself what do I need, simple steps Jo, simple Steps ) */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define DEFAULT_TAB 4

int mygetline(char[], int);

/* modified version of detab. accept a list of tab stops as arguments. */
/* using zero-indexing. So the earliest tab stop possible is 1 */

int main(int argc, char *argv[])
{
	int len;
	char s[MAXLEN];

	int i;			/* current index of char in string s */	
	int j;			/* total character printed since last tab stop */
	int next_tab;	/* current next tab stop. Use default settings if there are no args. */
	int cur_arg;

	while ((len = mygetline(s, MAXLEN)) > 0) {
		cur_arg = 1;
		next_tab = (cur_arg < argc) ? atoi(argv[cur_arg]) - ((cur_arg == 1) ? 0 : atoi(argv[cur_arg - 1])) : DEFAULT_TAB;

		for (i = 0, j = 0; s[i] != '\0'; ++i) {
			if (s[i] != '\t') {
				putchar(s[i]);
				++j;
				if (--next_tab == 0) {	/* set next_tab stop */
					do {
						cur_arg++;
						next_tab = (cur_arg < argc) ? atoi(argv[cur_arg]) : DEFAULT_TAB; 		
					} while ()
				}
			}
			else {						/* substitute a tab with blanks */
				while(next_tab-- > 0 && ++j)
					putchar(' ');
				cur_arg++;
				next_tab = (cur_arg < argc) ? atoi(argv[cur_arg]) - ((cur_arg == 1) ? 0 : atoi(argv[cur_arg - 1])) : DEFAULT_TAB;
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