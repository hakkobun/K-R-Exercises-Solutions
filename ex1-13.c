#include<stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define EOF 'q'

/* prints histogram of length of words in its input horizontally, and vertically */

main()
{
    int c, len, max, state;
    int histo[20];

    for (int i = 0; i < 20; ++i)
        histo[i] = 0;

    state = OUT;
    len = max = 0;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                state = OUT;
                if (++histo[len] > max)
                    max = histo[len];
                len = 0;
            }
        }
        else if (state == OUT) {
            state = IN;
            len = 1;
        }
        else {
            ++len;
        }
    
    /* horizontal display */
    for (int i = 0; i < 20; ++i)
        if (histo[i] != 0) {
            printf("%2d ",i);
            
            for (int j = 0; j < histo[i]; ++j)
                printf("+");
            
            printf("\n");
        }

    /* vertical display */
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (i >= max - histo[j]) 
                printf("  +");
            else
                printf("   ");
        }
        printf("\n");
    }

    for (int i = 0; i < 20; ++i)
        printf("%3d", i);

    printf("\n");
}