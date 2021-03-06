#include <stdio.h>
#include <string.h>
#include "mygetline.h"
#define MAXLINE 1000

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	printf("%d\n", argc);

	if (argc != 2)
		printf("Usage: find pattern\n");
	else
		while (mygetline(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
	return found;
}