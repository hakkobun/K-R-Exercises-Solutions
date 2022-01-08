/* Handler Functions for different states */

#include "share.h"

void (*pVar)(char *token) = &addNewVarName;
void (*pType)(char *token) = &addNewDataType;

void simpleListHandler(void (*addFunc)(char *token))
{	/* The first token that this handler is going to see must be a datatype, varname or a ';' */
	nestPrinter();
	printf("Parsing a simple list of names\n");
	++nest_level;
	int t;

	for(t = getToken(token); t!=';'; t = getToken(token)) {
		if (t == TOKEN_VALID_VARNAME || t== TOKEN_VALID_DATATYPE) {
			(*addFunc)(token);
			if ((t = getToken(token)) == ';')
				break;
			if (t != ',') {
				nestPrinter();
				printf("Error At line %d: Expected ',' or ';' token but found %s\n", input_line, token);
				exit(1);
			}
		} else {
			nestPrinter();
			printf("Error At line %d:  Expected a datatype or varname token but found %s\n", input_line, token);	
			exit(1);
		}
	}

	--nest_level;
	nestPrinter();
	printf("List parsed successfully\n");

}

/* blockHandler template. Will be used for insideStructHandler, insideFunctionHandler, and a free block */
void blockHandler(int init_balance)
{	
	nestPrinter();
	printf("Handling Inside Block @ Line %d\n", input_line);
	++nest_level;

	int t;

	do {
		updateBalance((t = getToken(token)));
		if (t == '{')
			blockHandler(getBlockBalance() - 1);
		else if (t == TOKEN_TYPEDEF)
			typedefHandler();
		else if (t == TOKEN_STRUCT)
			structHandler();
		else if (t == TOKEN_VALID_DATATYPE) {
			validTypeNameHandler(getPBCBalance());
		}

	} while(!(t=='}' && getBlockBalance()==init_balance));
	
	--nest_level;
	nestPrinter();
	printf("Block handled succesfully @ Line %d\n", input_line);
}


void insideStructHandler(int init_balance)
{	
	nestPrinter();
	printf("Handling Inside Struct\n");
	++nest_level;

	int t;
	do {
		updateBalance((t = getToken(token)));
		if (t == '{') {		/* no definition inside a struct. And we're not considering union here. */
			nestPrinter();
			printf("Inside struct Error At line %d: expected a declaration before '{' token\n", input_line);
			exit(1);
		}
		else if (isValidDataType(token)) {
			validTypeNameHandler(getPBCBalance());
		} 
		else if (t == TOKEN_STRUCT) {
			structHandler();
		} 
		// else if (t != '}') {
		// 	nestPrinter();
		// 	printf("Inside struct Error At line %d: expected a declaration but found [ %s ] token\n", input_line, token);
		// 	exit(1);
		// }

	} while(!(t=='}' && getBlockBalance()==init_balance));

	--nest_level;
}

void insideFunctionHandler(int init_balance, char *func_name)
{	
	nestPrinter();
	printf("Handling Inside Declaration of Function [ %s ]\n", func_name);
	++nest_level;
	
	int t;
	do {
		updateBalance((t = getToken(token)));
		if (t == '{') {
			blockHandler(getBlockBalance() - 1);
		}
		else if (t == TOKEN_TYPEDEF) {
			typedefHandler();
		}
		else if (t == TOKEN_STRUCT) {
			structHandler();
		}
		else if (t == TOKEN_VALID_DATATYPE) {
			validTypeNameHandler(getPBCBalance());
		}

	} while(!(t=='}' &&  getBlockBalance()==init_balance));
		
	--nest_level;
}

void structHandler()
{
	nestPrinter();
	printf("Handling Struct\n");
	++nest_level;
	int t;
	if ((t=getToken(token)) == '{') {
		updateBalance(t);
		insideStructHandler(getBlockBalance() - 1);
	}
	else {	/* User provided a tag name */
		if ((t=getToken(token)) == '{') {
			updateBalance(t);
			insideStructHandler(getBlockBalance() - 1);
		} else {
			ungetToken(token, t);
		}
	}
	
	// simpleListHandler(pVar);
	validTypeNameHandler(getPBCBalance());

	--nest_level;
	// nestPrinter();
	// printf("Struct successfully parsed\n");
}
void typedefHandler()
{
	nestPrinter();
	printf("Handling Typedef\n");
	++nest_level;
	
	int t;
	if ((t = getToken(token)) == TOKEN_STRUCT) {	
		if ((t = getToken(token)) == '{') {
			updateBalance(t);
			insideStructHandler(getBlockBalance() - 1);
		}
		else {	/* User provided a tag name */
			if ((t = getToken(token)) == '{') {
				updateBalance(t);
				insideStructHandler(getBlockBalance() - 1);
			} 
			else {
				ungetToken(token, t);
			}
		}
	}
	else { /* now it's still a var name */
		;
	}


	simpleListHandler(pType);

	
	--nest_level;
	// nestPrinter();
	// printf("Typedef successfully parsed\n");
}


// void beforeName()
// {
// 	++nest_level;

// 	--nest_level;
	
// }
// void afterName()
// {
// 	++nest_level;
	
// 	--nest_level;

// }
// void assignment()
// {
// 	++nest_level;
	
// 	--nest_level;

// }

int validTypeNameHandler(struct pbcBalanceArray pbcbalance)
{
	nestPrinter();
	printf("Handling a valid data type\n");
	++nest_level;

	int t;
	char *name_tmp;
	int return_type;

	while(1) {
		for (t = getToken(token); t != TOKEN_VALID_VARNAME; t = getToken(token)) {
			if (t == ';') {
				return_type = DECLARATION;
				goto exit_scenario;
			}
			updateBalance(t);
		}

		name_tmp = mystrdup(token, WHOLE);

		/* Encounter a var name now */
		if ((t = getToken(token)) == '(')	{	/* It's a function, which is mutually exclusive to assignment */ 
			nestPrinter();
			printf("Handling a function name\n");
			updateBalance(t);
			for (t = getToken(token); !(t==',' && isBalance(pbcbalance)) && t!='{'; t = getToken(token)) {	
				if (t == ';') {
					return_type = DECLARATION;
					goto exit_scenario;
				}
				updateBalance(t);
			}

			if (t == '{') {	/* a function definition */
				updateBalance(t);
				insideFunctionHandler(getBlockBalance() - 1, name_tmp);
				return_type = DEFINITION;	/* definition signal */
				goto exit_scenario;
			}
			else {	/* a function declaration */
				;	
			}
		}
		else {
			ungetToken(token, t);
			addNewVarName(name_tmp);	/* not a function, so add it */
			for (t = getToken(token); !(t==',' && isBalance(pbcbalance)) || t == '='; t = getToken(token)) {	
				if (t == ';') {
					return_type = DECLARATION;
					goto exit_scenario;
				}
				updateBalance(t);
			}
			if (t == '=') {
				for (t = getToken(token); !(t==',' && isBalance(pbcbalance)); t = getToken(token)) {
					if (t == ';') {
						return_type = DECLARATION;
						goto exit_scenario;
					}
					updateBalance(t);
				}
			}
		}
	}
	
	exit_scenario:
	--nest_level;
	return return_type;	
	// nestPrinter();
	// printf("Successfully handled valid data type\n");
}

void mainHandler()
{
	initHashTable();
	initGroupTree();

	int t;
	while((t = getToken(token)) != EOF) {
		// printf("%s\n", token);
		updateBalance(t);
		if (t == '{') {
			blockHandler(getBlockBalance() - 1);
		}
		else if (t == TOKEN_TYPEDEF) {
			typedefHandler();
		}
		else if (t == TOKEN_STRUCT) {
			structHandler();
		}
		else if (isValidDataType(token)) {
			validTypeNameHandler(getPBCBalance());
		}
	}
	
}