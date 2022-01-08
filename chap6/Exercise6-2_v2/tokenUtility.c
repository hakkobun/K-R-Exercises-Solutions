/* Token Utilities Functions */

#include "share.h"

#define PARENTHESIS 0	/* () */
#define BRACKETS	1	/* [] */
#define CURLYBRACES	2	/* {} */

#define MAX_TOKEN_BUFFER 10

static int openclose_balance[3] = {0, 0, 0};

struct token_buffer {
	char token[MAXTOKEN];
	int token_type;
};

static struct token_buffer tbuf[MAX_TOKEN_BUFFER];
static int token_bufp = 0;


struct pbcBalanceArray getPBCBalance()
{
	struct pbcBalanceArray curBalance;
	for (int i = 0; i < 3; ++i)
		curBalance.pbc[i] = openclose_balance[i];
	return curBalance;
}

int getBlockBalance()
{
	return openclose_balance[2];
}

/* Return 1 if open close is balanced (to the initial pbcBalance), and zero otherwise */
int isBalance(struct pbcBalanceArray pbcbalance)
{
	for (int i = 0; i < 3; ++i)
		if (pbcbalance.pbc[i] != openclose_balance[i])
			return 0;
	return 1;
}

void updateBalance(int c)
{
	switch (c) {
		case '(' :
			openclose_balance[0]++; 
			break;
		case ')' :
			if (openclose_balance[0])
				openclose_balance[0]--;
			else {
				printf("Error: Expected '(' token\n");
				exit(1);
			}
			break;
		case '[' :
			openclose_balance[1]++; 
			break;
		case ']' :
			if (openclose_balance[1])
				openclose_balance[1]--;
			else {
				printf("Error: Expected '[' token\n");
				exit(1);
			}
			break;
		case '{' :
			openclose_balance[2]++; 
			break;
		case '}' :
			if (openclose_balance[2])
				openclose_balance[2]--;
			else {
				printf("Error: Expected '{' token\n");
				exit(1);
			}
			break;
		default:
			break;
	}
	// nestPrinter();
	// printf("Updating Balance for the token '%c': current balances are %d %d %d\n", c, openclose_balance[0], openclose_balance[1], openclose_balance[2]);
}

/* Skip through all consecutive space and comments and return the next non-comment token or EOF */
int blankSkipper()
{
	int TOKEN_found = FALSE;
	int EOC_found = FALSE;	/* (End Of Comment) Found This part-> */
	char c;

	while (!TOKEN_found) {
		while (isspace(c = getch())) {
			if (c == '\n')
				input_line++;
		}
			
		if (c == '/') {
			if ((c = getch()) == '*') {	/* In a comment */
				while (!EOC_found) {
					while ((c = getch()) != '*')
						;

					if ((c = getch()) == '/') 
						EOC_found = TRUE;
					else {
						ungetch(c);		/* c might be an asterisk */
					}
				}
				EOC_found = FALSE;
			} 
			else {
				ungetch(c);
				TOKEN_found = TRUE;
			}
		} 
		else {
			TOKEN_found = TRUE;
		}
	}
	return c;
}

void getStringConst(char *token)
{
	int EOS_found = FALSE;	/* (End Of String) Found (") but not (\") */
	char c;
	char *p = token;

	*p++ = '\"';
	while (!EOS_found) {
		while ((c = getch())!= '\\' && c!='\"')
			*p++ = c;
		if (c == '\"') {
			*p++ = c;
			EOS_found = TRUE;
		} else {	/* c is a backslash */
			*p++ = getch();
		}
	}
	*p = '\0';
}

void getCharConst(char *token)
{
	char c;
	char *p = token;
	*p++ = '\'';
	if((*p++ = getch()) == '\'')
		*p++ = getch();
	*p++ = getch();
	*p = '\0';
}


int tokentype(char *s)
{
	if (mystrcmp(s, "typedef", WHOLE) == 0)
		return TOKEN_TYPEDEF;
	else if (mystrcmp(s, "struct", WHOLE) == 0)
		return TOKEN_STRUCT;
	else if (isValidDataType(s))
		return TOKEN_VALID_DATATYPE;
	else
		return TOKEN_VALID_VARNAME;
}


int getNextToken(char *token)
{
	char c;
	char *p = token;
	
	if (isalpha(c = blankSkipper()) || c == '_') {	/* 1: Datatype, varname, typedef, struct */
		*p++ = c;
		while (isalnum(c = getch()) || c == '_')
			*p++ = c;
		ungetch(c);
		*p = '\0';
		return tokentype(token);
	} 
	else if (c == '\"') {	/* 2: String constants */
		getStringConst(token);
		return TOKEN_STRING_CONST;
	}
	else if (c == '\'') {		/* 3: Character constants */ 
		getCharConst(token);
		return TOKEN_CHAR_CONST;
	}
	else {					/* 4: Others */
		*p++ = c;
		if (c != EOF)
			*p = '\0';
		return c;
	}
}

int getToken(char *token)
{
	int t;
	if (token_bufp > 0) {
		mystrcpy(token, tbuf[--token_bufp].token, WHOLE);
		t = tbuf[token_bufp].token_type;
		return t;
	}
	else
		return getNextToken(token); 
}

void ungetToken(char *token, int t)
{
	++nest_level;
	if (token_bufp < MAX_TOKEN_BUFFER) {
		mystrcpy(tbuf[token_bufp].token, token, WHOLE);
		tbuf[token_bufp++].token_type = t; 
	}
	else {
		printf("Error: Buffer is full\n");
		exit(1);
	}
	--nest_level;
}



void setPrefixLen(int argc, char *argv[])
{
	if (argc == 1)
		prefixlen = DEFAULT_PREFIX_LEN;
	else
		prefixlen = atoi(*++argv);
	printf("Prefix Len Sets to %d\n", prefixlen);
}

