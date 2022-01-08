#include <stdio.h>

char *month_name(int n)
{
	static char *name[] = {
		"Illegal Month", "January", "Febuary", "March"
	};

	return (n < 1 || n > 3) ? name[0] : name[n];
}

int main()
{
	printf("%s\n", month_name(2));
	
	return 0;
}