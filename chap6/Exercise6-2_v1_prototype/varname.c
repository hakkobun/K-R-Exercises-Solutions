#include "local.h"
#include "getch.h"
#include "mystring.h"


#define MAXWORD 100
#define DEFAULTLEN 6

struct wnode {	/* node names */
	char *word;
	struct wnode *left;
	struct wnode *right;
};


struct gnode {	/* group names */
	char *prefix;
	int count;
	struct wnode *wroot;	/* points to the root of the word tree */
	struct gnode *left;
	struct gnode *right;
};


struct gnode *addgTree(struct gnode *p, char *w);
struct wnode *addwTree(struct wnode *p, char *w);

void printgTree(struct gnode *p);
void printwTree(struct wnode *p, int *pcount, int total);

int getword(char *word, int limit);


extern int PREFIXLEN = DEFAULTLEN;

int main(int argc, char *argv[])
{

	if (argc != 1) {
		char *p = *++argv;
		PREFIXLEN = atoi(p);
	}
	

	char word[MAXWORD];
	struct gnode *groot = NULL;

	// char word1[] = "chemiatry";
	// char word2[] = "chemiatry";

	// printf("%d\n", mystrcmp(word1, word2, PREFIX));


	while(getword(word, MAXWORD) >= 0) {
		if(mystrlen(word) > PREFIXLEN) {
			printf("newword : %s\n", word);
			groot = addgTree(groot, word);
		}
	}
	printgTree(groot);
	return 0;
}

void printgTree(struct gnode *p)
{
	int count = 0;
	int *pcount = &count;
	if (p != NULL) {
		printgTree(p->left);
		
		printf("%s (%d) : ", p->prefix, p->count);
		printwTree(p->wroot, pcount, p->count);
		
		printgTree(p->right);
	}
}

void printwTree(struct wnode *p, int *pcount, int total)
{
	if (p != NULL) {
		printwTree(p->left, pcount, total);
		printf(++*pcount == total ? "%s\n" : "%s, ", p->word);
		printwTree(p->right, pcount, total);
	}

}

struct wnode *addwTree(struct wnode *p, char *w)
{
	int cond;
	if (p == NULL) {	/* a new word has arrived */
		p = (struct wnode *) malloc(sizeof(struct wnode));
		p->word = mystrdup(w, WHOLE);
		p->left = p->right = NULL;
	} else if ((cond = mystrcmp(w, p->word, WHOLE)) == 0)
		;
	else if (cond < 0)
		p->left = addwTree(p->left, w);
	else
		p->right = addwTree(p->right, w);
	return p;
}



/* addTree: add new word to the tree */
struct gnode *addgTree(struct gnode * p, char *w)
{
	//compare the first six letters of the word with the current node
	int cond;

	if (p == NULL) {	/* a new prefix has arrived */
		p = (struct gnode *) malloc(sizeof(struct gnode));
		p->left = p->right = NULL;
		p->prefix = mystrdup(w, PREFIX);
		p->wroot = addwTree(p->wroot, w);
		p->count = 1;
	} else if ((cond = mystrcmp(w, p->prefix, PREFIX)) == 0) {	/* same prefix: add to the tree */
		p->wroot = addwTree(p->wroot, w);
		p->count++;
	} else if (cond < 0) {
		p->left = addgTree(p->left, w);
	} else {
		p->right = addgTree(p->right, w);
	}
	return p;
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