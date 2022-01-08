#include <stdio.h>


/* questions about multi dimensional arrays and pointer */

/* why do we need the number of columns and not rows ? */
/* more generally why do we need every dimension except the first ? */



#define dprint(expr) printf(#expr " = %d\n", expr)

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int func();
int main()
{

	int *******p;

	dprint(daytab[0][0]);

	func(daytab);
	dprint(daytab[0][0]);
	
	func(daytab);
	dprint(daytab[0][0]);
	
	return 0;
}

int func(char (*daytab)[13])
{
	daytab[0][0]++;
	return 0;
}