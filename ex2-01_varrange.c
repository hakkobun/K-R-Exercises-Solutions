#include <stdio.h>

/* (char)(127+1) = (char)-128 because the 2's complement system */
/* c + 1 > c will be comparing int with int not char to char */

int main()
{
	{
		unsigned char c, minc, maxc;

		for (c = 0; (unsigned char)(c + 1) > c; ++c)
			;
		maxc = c;
		for (c = 0; (unsigned char)(c - 1) < c; --c)
			;
		minc = c;

		printf("%d %d\n", minc, maxc);
	}

	{
	int i, mini, maxi;

	for (i = 0; i + 10000000 > i; i+=10000000)
		;
	maxi = i;
	for (i = 0; i - 10000000 < i; i-=10000000)
		;
	mini = i;

	printf("%d %d\n", mini, maxi);
	}
	
	return 0;
}