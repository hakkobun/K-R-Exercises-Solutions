#include <string.h>
#include <stdio.h>
#include <limits.h>

#define MAXLEN 100

void itoa_textbook(int n, char s[]);
void itoa_mod(int n, char s[]);

int main()
{

    // printf("%d\n", INT_MAX);
    // printf("%d\n", INT_MIN);

    // int b = 0;
    // int M = INT_MIN;
    // while ((M /= 2) != 0) {
    //     b++;
    // } 
    // printf("b = %d\n", b);


    char s[MAXLEN];

    // itoa_textbook(INT_MIN, s);  /* gonna overflow */
    itoa_mod(INT_MIN, s);       /* gonna works */
    
    printf("%s\n", s);

}



void reverse(char s[]);

#define TRUE 1
#define FALSE 0

/* itoa: convert the number n to characters in s */
void itoa_mod(int n, char s[])
{
    int i, sign;
    int MIN;

    MIN = FALSE;

    /* handle negative number */
    if ((sign = n) < 0) {
        if (n == INT_MIN) {
            MIN = TRUE;
            n += 1;
        }
        n = -n;         
    }
        
    i = 0;
    do {
        s[i++] = (n%10) + '0';
    } while ((n /= 10) > 0);
    if(MIN)
        s[0]++;                 /* s[0] = 9 when, INT_MIN's last digit is 0, which is impossible for a 2's complement since INT_MIN = -POW(2,WORDSIZE-1), which ends in 2,4,8,6,2,...*/
    if (sign < 0) 
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

/* itoa: convert the number n to characters in s */
void itoa_textbook(int n, char s[])
{
    int i, sign;

    /* handle negative number */
    if ((sign = n) < 0)
        n = -n;         /* can't handle the largest negative number cuz in 2's complement system abs(INT_MIN) = abs(INT_MAX)+1*/

    i = 0;
    do {
        s[i++] = (n%10) + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) 
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

}
