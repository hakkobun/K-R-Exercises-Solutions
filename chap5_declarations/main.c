/* C-GRAMMAR */
/* dcl: 		optional *'s direct-dcl */
/* direct-dcl:	name
                (dcl)
				direct-dcl()
				direct-dcl[optional size] */

/* why use only two types ? (dcl and dir-dcl ? why not three why not just one ?) */

/* question: what about other types of dir-dcl ? that are not name and (dcl) ? */

/* why does dirdcl doesn't call itself recursively even though the grammar specified so */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"

#define MAXTOKEN 100




enum {NAME, PARENS, BRACKETS} ;

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;				/* type of last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char datatype[MAXTOKEN];	/* data type = char, int, etc */
char out[1000];				/* output string */


/* convert declaration to words */
int main()
{
	while (gettoken() != EOF) {
		strcpy(datatype, token);	/* 1st token on line is the datatype */
		out[0] = '\0';
		dcl();						/* parse the rest of the line */ /* why not start with dirdcl() ? */
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; )
		ns++;
	dirdcl();			/* what is this for ? */
	while (ns-- > 0)
		strcat(out, " pointer to");

}

/* dir-dcl: parse a direct declarator */
void dirdcl(void)
{
	int type;
	if (tokentype == '(') {					/* ( dcl ) */
		dcl();			/* what is this for ? */
		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME)			/* variable name */
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);				/* probably a [optional size] or just [] */
			strcat(out, " of");
		}
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