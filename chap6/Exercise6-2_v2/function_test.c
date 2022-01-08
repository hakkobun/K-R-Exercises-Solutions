#include "share.h"

int main(int argc, char *argv[])
{
	int t;
	int balance;

	nest_level = 0;
	input_line = 1;
	
	// char s[MAXNAMELEN];
	// scanf("%s", s);
	
	// int cond = mystrcmp(SHORTER_THAN_PREFIX_LEN, s, WHOLE);
	// if (cond > 0)
	// 	printf("The special code is greater than %s\n", s);
	// else if (cond < 0)
	// 	printf("The special code is less than %s\n", s);
	


	initHashTable();
	initGroupTree();
	setPrefixLen(argc, argv);
	mainHandler();
	
	showResult();
}
