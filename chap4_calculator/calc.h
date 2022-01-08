/* no need to compile this header file */
/* just run "cc main.c stack.c getop.c getch.c -lm" */

#define NUMBER '0'

#define PRINTTOP 'P'
#define DUPLICATE_TOP 'D'
#define SWAP_TOPS 'T'
#define CLEAR 'C'

#define VARIABLE 'a'


#define SIN 'S'
#define EXP 'E'
#define POW 'W'

int cur_var;        /* stores the variable that is just called 0 = a, 1 = b, ...*/

int getop(char []); /* return the type of op and store the op in the array */
int getch(void);
void ungetch(int);

void push(double);
double pop(void);
int mod(int, int);

void new_var(double f);
double get_var(int i);

void printtop(void);
void duplicate_top(void);
void swap_tops(void);
void clear(void);