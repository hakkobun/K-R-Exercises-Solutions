#include "getch.h"
#include "mystring.h"
#include "tree.h"


#define MAXWORD 100
#define DEFAULTLEN 6




int getword(char *word, int limit);


extern int PREFIXLEN = DEFAULTLEN;

int main(int argc, char *argv[])
{

	if (argc != 1) {
		char *p = *++argv;
		PREFIXLEN = atoi(p);
	}
	
	char c;
	char word[MAXWORD];
	struct gnode *groot = NULL;


	while(getword(word, MAXWORD) >= 0) {
		if (mystrcmp(word, "struct", WHOLE) == 0)
			addType(word);
		else if (isValidType(word)) {
			getword(word, MAXWORD);
			if ((c = getch()) != '(') {
				ungetch(c);
				if(mystrlen(word) > PREFIXLEN) {
					printf("newword : %s\n", word);
					groot = addgTree(groot, word);
				}
			}
		}
	}
	
	printgTree(groot);
	return 0;
}


/* getword: return the next "word" */
int getword(char *word, int limit)
{
	int c;
	char *w = word;

	while(isspace(c = getch()))
		;
	if (c == EOF)
		return -1;
	*w++ = c;
	while(isalnum(c = getch()) && c!=EOF && c!='\n')
		*w++ = c;
	ungetch(c);
	*w = '\0';
	return word[0];
}