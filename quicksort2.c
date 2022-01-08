#include <stdio.h>

void swap(int v[], int i, int j);
void my_qsort(int v[], int left, int right);



int main()
{
    int v[] = {5,10,2,4,6,3,0,0,0,7, 7,98798,11,1};
    int len = sizeof(v) / sizeof(int);
    my_qsort(v, 0, len - 1);

    for (int i = 0; i < len; ++i)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}


    


void my_qsort(int v[], int left, int right)
{
    int i, j, last ;
    
    if (left >= right)  
        return ;
    
    swap(v, left, (left + right)/2);    

    /* v0.1 partition */
    
    for (i = left + 1, j = right; i < j; )
        if (v[i] < v[left])
            ++i;
        else if (v[j] > v[left])
            --j;
        else
            swap(v, i++, j--);
    
    for (last = left + 1; v[last]<v[left] && last<=right; ++last)
        ;
    swap(v, left, --last);              
    

    /* v_K&R partition */
    // last = left;
    // for (i = left + 1; i <= right; ++i)
    //     if (v[i] < v[left])
    //         swap(v, i, ++last);
    // swap(v, left, last);

    
    
    
    my_qsort(v, left, last - 1);            
    my_qsort(v, last + 1, right);           
}

void swap(int v[], int i, int j)
{
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
