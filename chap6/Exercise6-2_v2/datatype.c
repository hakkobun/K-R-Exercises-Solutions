/* Add, store, check existence of typenames using Hash */

#include "share.h"

/* TODO: Create HashTable */
#define HASHSIZE 101
#define MAXWORD 100

struct nlist {
	struct nlist *next;
	char *name;
	// char *defn;
};

struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
		if (mystrcmp(np->name, s, WHOLE) == 0)
			return np;
	}
	return NULL;
}

struct nlist *install(char *name)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {	/* not found */
		np = (struct nlist *) malloc(sizeof(struct nlist));
		if (np == NULL || (np->name = mystrdup(name, WHOLE)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;

	} else {	/* already there */
		;
		// free((void *) np->defn);
	}
	// if ((np->defn = strdup(defn)) == NULL)
	// 	return NULL;
	
	printf("installed %s\n", name);
	return np;
}


/* Find if the datatype is in the Hash Table */
int isValidDataType(char *t)
{
	if (lookup(t) == NULL)
		return 0;
	return 1;

}
void addNewDataType(char *t)
{
	
	nestPrinter();
	printf("Adding New Data Type: [ %s ] to the HashTable\n", t);
	++nest_level;

	install(t);

	--nest_level;
}

void initHashTable()	/* Add in all the predefined types */
{
	install("int");
	install("float");
	install("double");
	install("char");
	install("void");
}


