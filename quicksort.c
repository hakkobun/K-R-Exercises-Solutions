#include <stdio.h>

void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);



int main()
{
    int v[] = {5,10,2,4,6,3,0,0,0,7, 7,98798,11,1};
    int len = sizeof(v) / sizeof(int);
    qsort(v, 0, len - 1);

    for (int i = 0; i < len; ++i)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}


/* qsort: sort v[left]...v[right] into increasing order */    
/* developed by C. A. R. Hoare in 1962 */

void qsort(int v[], int left, int right)
{
    int i, j, last ;
    /* int len = right - left + 1; */
    
    if (left >= right)  /* */
        return ;

    /*printf("BEFORE: left = %d right = %d\n", left, right);
    for (int i = left; i < left+len; ++i)
        printf("%d ", v[i]);
    printf("\n");
    */
    
    swap(v, left, (left + right)/2);    /* move partition element to v[left]*/
    
    /* printf("e = %d\n", v[left]); */


/* Partition all non-greater elements from v[left+1] to v[right] into before last */
/* Partition all greater elements into after last */

    for (i = left + 1, j = right; i < j; )
        if (v[i] < v[left])
            ++i;
        else if (v[j] > v[left])
            --j;
        else
            swap(v, i++, j--);
    
    for (last = left + 1; v[last]<v[left] && last<=right; ++last)
        ;
    
    swap(v, left, --last);                /* restore partition element */

    /* 
    printf("last = %d\n", last);
    printf("AFTER\n");
    for (int i = left; i < len+left; ++i)
        printf("%d ", v[i]);
    printf("\n\n"); */
    
    qsort(v, left, last - 1);            /*recur here*/
    qsort(v, last + 1, right);           /*recur here*/


}

void swap(int v[], int i, int j)
{
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
