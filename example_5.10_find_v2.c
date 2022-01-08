
/* Not wiring the search pattern deep into the program anymore */
/* Optional arguments should be permitted in any order. */
/* And the rest of the program should be independent of the number of arguments that were present */

#include <stdio.h>
#include <string.h>
#include "mygetline.h"

#define dprint(expr) printf(#expr "=: %d\n", expr)

#define MAXLINE 1000
/* find: print lines that match pattern from 1st arg */
/* with the options -n -x or -nx supported */
int main(int argc, char *argv[])
{

	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}


	if (argc != 1)
		printf("Usage: find -x -n pattern\n");

	else
		while (mygetline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld: ", lineno);
				printf("%s", line);
				found++;
			}
		}

	return found;
}