#include "share.h"

int main(int argc, char *argv[])
{
	initGroupTree();
	setPrefixLen(argc, argv);

	return 0;
}