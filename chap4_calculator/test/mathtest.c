#include <stdio.h>
#include <math.h>

double myfunc(double f)
{
    return sin(f);
}

int main()
{
    printf("%g", myfunc(3.1415));
}