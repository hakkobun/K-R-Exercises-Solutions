#include "mystring.h"

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


struct wnode *type_root = NULL;


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


void initialize()
{
	type_root = addwTree(type_root, "int");
	type_root = addwTree(type_root, "char");
	type_root = addwTree(type_root, "float");
	type_root = addwTree(type_root, "double");
	type_root = addwTree(type_root, "short");
	type_root = addwTree(type_root, "long");
	type_root = addwTree(type_root, "void");
}

