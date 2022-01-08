/* C-GRAMMAR */
/* dcl: 		optional *'s direct-dcl */
/* direct-dcl:	name
                (dcl)
				direct-dcl()
				direct-dcl[optional size] */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"

#define MAXTOKEN 100




enum {NAME, PARENS, BRACKETS} ;

int gettoken(void);
int tokentype;				/* type of last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char datatype[MAXTOKEN];	/* data type = char, int, etc */
char out[1000];				/* output string */


/* undcl: convert word description to delcaration */
int main()
{
	int type;
	char temp[MAXTOKEN];

	while(gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
		printf("%s\n", out);
	}
	return 0;
}

/* gettoken: skip blanks and tabs, then finds the next token in the input */
/* a "token" is a name, a pair of parenthesis, a pair of brackets perhaps including a number, or any other single character */
int gettoken(void) 
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}