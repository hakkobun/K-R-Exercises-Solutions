#include <stdio.h>
/* In two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Because  x-1 will turn the rightmost 1-bit into 0, while all bits to the left unchanged. */

int bitcount_slow(unsigned x);
int bitcount_fast(unsigned x);

int main()
{
    int i;

    for (i = 0; i < 200; ++i)
        if (bitcount_fast(i) != bitcount_slow(i)) {
            printf("INVALID");
            return 0;
        }

    printf("you did it");

	return 0;
}

int bitcount_fast(unsigned x)
{
    int b;

    for (b = 0; x !=0; x &= (x-1))
        ++b;
    
    return b;
}



int bitcount_slow(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}