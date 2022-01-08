#include <stdio.h>

#define abs(a) (int)((a>0)?a:-a)

int mod(int , int);

int main()
{
    /* Truncation towards zero remainder version */
    /* C99 requires that when a/b is representable */
    /* (a/b)*b + a%b == a */


    /* Euclidean definition, 0 <=r |n|*/
    /* n>0: q = floor(a/n) */
    /* n<0: q = ceil(a/n) */

    /* i want -1 % 8 == 7 */

    int a = (5) % (-3);
    int b = (-5) % (3);
    int c = (-5) % (-3);

    int d = (5) / (-3);     /* so (5/-3) */
    int e = (-5) / 3;
    int f = (-5) / (-3);

    printf("%d %d\n", abs(2), abs(-2));
    printf("%d %d %d\n", a, b, c);
    printf("%d %d %d\n", mod(5,-7), mod(-5,7), mod(-5,-7));

    return 0;

}

int mod(int a, int b)
{
    int r = a % b;
    // printf("*a = %d b = %d r = %d abs(b) = %d\n", a, b, r, abs(b));
    return (r<0) ? r+abs(b) : r;
}