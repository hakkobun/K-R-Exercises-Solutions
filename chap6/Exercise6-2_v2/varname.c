/* Add, store, print Variable names in groups using BST */

#include "share.h"

struct varnamenode {
	char *name;
	struct varnamenode *left, *right;
};

struct groupnode {
	char *prefix;	/* using some special code for variable names that are shorter than PREFIXLEN */
	int total;
	struct varnamenode *root;
	struct groupnode *left, *right;
};

struct groupnode *VarNameTreeRoot;

/* add the varname v to the tree, pointed from the corresponding groupnode with the matching prefix */
struct varnamenode *addToVarNameTree(struct varnamenode *p, char *v, struct groupnode *pg)
{
	int cond;
	if (p == NULL) {	/* a new word has arrived */
		p = (struct varnamenode *) malloc(sizeof(struct varnamenode));
		p->name = mystrdup(v, WHOLE);
		p->left = p->right = NULL;
	} else if ((cond = mystrcmp(v, p->name, WHOLE)) == 0)
		pg->total--;	/* not counting duplicates */
	else if (cond < 0)
		p->left = addToVarNameTree(p->left, v, pg);
	else
		p->right = addToVarNameTree(p->right, v, pg);
	return p;
}

struct groupnode *addToGroupTree(struct groupnode *p, char *v)
{
	//compare the first six letters of the word with the current node
	int cond;
	char *v_prefix = (mystrlen(v) <= prefixlen ? mystrdup(SHORTER_THAN_PREFIX_LEN, WHOLE) : mystrdup(v, PREFIX));

	if (p == NULL) {	/* a new prefix has arrived */
		printf("In addToGroupTree: NULL\n");
		if ((p = (struct groupnode *) malloc(sizeof(struct groupnode)))== NULL) {
			printf("In addToGroupTree: malloc error\n");
		}
		p->left = p->right = NULL;
		p->prefix = mystrdup(v_prefix, WHOLE);
		p->root = addToVarNameTree(p->root, v, p);
		p->total = 1;
	} else if ((cond = mystrcmp(v_prefix, p->prefix, PREFIX)) == 0) {	/* same prefix: add to the tree */
		printf("In addToGroupTree: Same prefix exist\n");
		p->total++;
		p->root = addToVarNameTree(p->root, v, p);
	} else if (cond < 0) {
		printf("In addToGroupTree: Go left\n");
		p->left = addToGroupTree(p->left, v);
	} else {
		printf("In addToGroupTree: Go right\n");
		p->right = addToGroupTree(p->right, v);
	}
	return p;

}
void addNewVarName(char *v)
{
	
	++nest_level;

	VarNameTreeRoot = addToGroupTree(VarNameTreeRoot, v);


	nestPrinter();
	printf("Added New Variable Name: [ %s ] to the VarNameTree\n", v);
	--nest_level;

}
void initGroupTree()
{

	nestPrinter();
	printf("Group Tree Initialized\n");
	++nest_level;

	VarNameTreeRoot = NULL;

	--nest_level;

}
void printVarNameTree(struct varnamenode *p, int *pcount, int total)
{
	if (p != NULL) {
		printVarNameTree(p->left, pcount, total);
		printf(++*pcount == total ? "%s\n" : "%s, ", p->name);
		printVarNameTree(p->right, pcount, total);
	}
}
void printGroupTree(struct groupnode *p)
{
	int count = 0;
	int *pcount = &count;
	if (p != NULL) {

		
		printGroupTree(p->left);
		
		printf("%s (%d) : ", mystrcmp(p->prefix, SHORTER_THAN_PREFIX_LEN, WHOLE) == 0 ? "Names which are not greater than prefix len" : p->prefix, p->total);
		printVarNameTree(p->root, pcount, p->total);
		
		printGroupTree(p->right);
	}	

}

void showResult()
{
	printf("Showing Results\n");
	printGroupTree(VarNameTreeRoot);
}

