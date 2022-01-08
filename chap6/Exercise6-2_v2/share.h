#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define PREFIX 0
#define WHOLE 1

#define FALSE 0
#define TRUE 1

#define BALANCED 0
#define UNBALANCED 1

#define DECLARATION	0
#define DEFINITION	1

/* types of token */
#define TOKEN_VALID_DATATYPE	1
#define TOKEN_VALID_VARNAME		2
#define TOKEN_TYPEDEF			3
#define TOKEN_STRUCT			4
#define TOKEN_STRING_CONST		5
#define TOKEN_CHAR_CONST		6

#define MAXTOKEN 100
#define MAXNAMELEN 100
#define MAXTYPE 100
#define DEFAULT_PREFIX_LEN 6

#define SHORTER_THAN_PREFIX_LEN "\a"
#define BLANK_STR "\0"


char token[MAXTOKEN];
int prefixlen;

#ifndef GLOBAL_DEBUG
#define GLOBAL_DEBUG
int nest_level;
int input_line;
#endif

#ifndef PBC_STRUCT
#define PBC_STRUCT
struct pbcBalanceArray {
	int pbc[3];
};
#endif


/* token Utilities */
int getToken(char *token);
void ungetToken(char *token, int t);
void setPrefixLen(int argc, char *argv[]);
int blankSkipper();
void updateBalance(int c);
int getBlockBalance();
int isBalance(struct pbcBalanceArray pbcbalance);
struct pbcBalanceArray getPBCBalance();

/* String Utilities */
int mystrcmp(char *s, char *t, int option);
char *mystrdup(char *s, int option);
void mystrcpy(char *to, char *from, int option);
int mystrlen(char *s);

/* Scenario Handlers */
void mainHandler();
void structHandler();
void typedefHandler();
void blockHandler(int init_balance);
int validTypeNameHandler(struct pbcBalanceArray pbcbalance);

/* Variable Name Manager */
void addNewVarName(char *v);
void initGroupTree();
void showResult();

/* Datatype Manager */
int isValidDataType(char *token);
void addNewDataType(char *token);
void initHashTable();

/* Getch and ungetch */
int getch(void);
void ungetch(int c);

/* Display Utilities */
void nestPrinter();