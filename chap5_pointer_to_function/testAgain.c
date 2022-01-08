#include <stdio.h>
#include <stdlib.h>

void printer(int (*func)(void))
{
	printf("%d", (*func)());
}

int f1(void)
{
	return 1;
}
int f2(void)
{
	return 2;
}

int main(int argc, char *argv[])
{
	int option = atoi(argv[1]);
	
	printer((int (*)(void))(option == 1 ? f1 : f2));

	return 0;
}