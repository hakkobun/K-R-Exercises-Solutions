#include <stdio.h>

#define MAXLEN 100
/* expands the shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. */

/* a-b-c means abbc */
/* TestA-D means TestABCD */
/* a-d- means abcd-, while -a-d means -abcd */


int expand(char s1[], char s2[])
{
	int i, c;

	for (i = 0, c = s1[0]; c <= s1[2]; ++i, ++c)
		s2[i] = c;

	s2[i] = '\0';
	return i;
}

int expand_v2(char s1[], char s2[])
{
	int i; /* reading pos in s1 */
	int j; /* writing pos in s2 */
	int c; 
	int p; /* position of the second letter after the last '-' */ 

	for (i = j = p = 0; s1[i] != '\0'; ++i) {
		for (; s1[i]!='-' && s1[i]!='\0'; ++i)
			;
		if (s1[i]!= '\0' && i != 0 && s1[i+1] != '\0') {	/* legal '-' is found */
			for (; p < i - 1; ++p)							/* copy the non-expanding parts */
				s2[j++] = s1[p];
			
			for (c = s1[i-1]; c <= s1[i+1]; ++c)			/* expansion */
				s2[j++] = c;

			p = i + 2;										/* set new p */
		}
	}
	for (; s1[p] != '\0'; ++p)								/* copy the leftover, if any */
		s2[j++] = s1[p];
	s2[j] = '\0';
	return j;
}

int main()
{
	char s1[MAXLEN];
	char s2[MAXLEN];

	scanf("%s", s1);
	expand_v2(s1, s2);
	printf("%s\n", s2);
	
	return 0;
}