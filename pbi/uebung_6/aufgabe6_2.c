#include <stdio.h>
#include <stdlib.h>


void in_sort2(int *numptr1, int *numptr2)
{
    int tmp;
    
    if(*numptr1 > *numptr2)
    {
        tmp = *numptr1;
        *numptr1 = *numptr2;
        *numptr2 = tmp;
    }
    
}


void in_sort3(int *numptr1, int *numptr2, int *numptr3)
{
    int tmp;
    
    if((*numptr2 > *numptr3))
    {
        tmp = *numptr1;
        *numptr1 = *numptr2;
        *numptr2 = tmp;
    }
    
    if((*numptr1 > *numptr2) || (*numptr1 > *numptr3))
    {
        if((*numptr1 > *numptr3))
        {
            tmp = *numptr1;
            *numptr1 = *numptr3;
            *numptr3 = tmp;
            
        } else {
            
            tmp = *numptr1;
            *numptr1 = *numptr2;
            *numptr2 = tmp;
            
        }               
    }
}


int main(int argc, char *argv[])
{
    int a, b, c, i;
    
    if(argc != 4)
    {
        fprintf(stderr, "\tFAIL!\n");
        exit(EXIT_FAILURE);
    }
    
    for(i = 1; i < argc; i++)
    {
        sscanf(argv[i], "%d", (i == 1 ? &a : (i == 2 ? &b : &c)));
    }
    
    in_sort2(&a, &b);
    
    printf("\ta = %d; b = %d\n", a, b);
    
    in_sort3(&a, &b, &c);
    
    printf("\ta = %d; b = %d; c = %d\n", a, b, c);
    
    
    return(EXIT_SUCCESS);    
}