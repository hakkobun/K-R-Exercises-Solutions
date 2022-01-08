#include <stdio.h>



int array[20][3];

/* y: function returning pointer to array[3] of int */
int (*y(int i))[3]
{
	int (*p)[3];
    p = array;

	return p + i;
}


int main()
{
    int i, j;
    for (i = 0; i < 20; ++i)
        for (j = 0; j < 3; ++j)
            array[i][j] = i * j;
    
    int (*p)[3];

    for (j = 0; j < 3; ++j)
        printf(j == 2 ? "%d\n" : "%d ", array[4][j]);

    p = y(4);
    for (j = 0; j < 3; ++j)
        printf(j == 2 ? "%d\n" : "%d ", (*p)[j]);
    // for (j = 0; j < 3; ++j)
    //     printf(j == 2 ? "%d\n" : "%d ", *p++);
    return 0;
}