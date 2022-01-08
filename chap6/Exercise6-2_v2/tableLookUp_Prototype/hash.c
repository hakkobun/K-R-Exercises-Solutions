#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101
#define MAXWORD 100

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
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
		if (strcmp(np->name, s) == 0)
			return np;
	}
	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {	/* not found */
		np = (struct nlist *) malloc(sizeof(struct nlist));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;

	} else {	/* already there */
		free((void *) np->defn);
	}
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	
	printf("installed %s\n", name);
	return np;
}

int main()
{
	char name[MAXWORD], defn[MAXWORD];
	struct nlist *np;

	do {
		scanf("%s", name);
		if (strcmp(name, "q") == 0) 
			break;
		scanf("%s", defn);

		if (install(name, defn) == NULL)
			exit(1);

	} while(1);

	printf("setup complete\n");
	printf("now you can lookup\n");

	do {
		scanf("%s", name);
		if (strcmp(name, "q") == 0) 
			break;
		if ((np = lookup(name)) == NULL)
			printf("not found\n");
		else 
		printf("found match: %s: %s\n", name, np->defn);
	} while(1);


}