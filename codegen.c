#include <stdio.h>
/* this code gen a template C program into a file*/

#define MAXNAMELEN 20
void write();
int main() 
{
    /* filname option
    char filename[MAXNAMELEN];

    int len;
    len = getfilename(filename);
    */
    write();


    return 0;

}

void write()
{
    char code[] =   "#include <stdio.h>\n" 
                    "int main()\n"
                    "{\n"
                    "\t\n"
                    "\treturn 0;\n"
                    "}";
    printf("%s", code);
}

int getfilename(char filename[])
{
    int c, i;
    i = 0;

    while((c=getchar()) != '\n')
        filename[i++] = c;

    return i;
}