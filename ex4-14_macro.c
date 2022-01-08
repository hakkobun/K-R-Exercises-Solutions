#include <stdio.h>

/* block structure is used, so tmp is destroyed once it leaves the right brace */
#define swap(t,x,y) {t tmp; tmp = x; x = y; y = tmp;}
int main()
{
    double x = 399.3;
    double y = 3.5;
    swap(double, x, y);
    printf("%4g %4g\n", x, y);
}
