#include "svdpi.h"
#include <stdio.h>

int summ_array(const svOpenArrayHandle v){
    int sum;
        
    printf("svLow(v,1)      = %d \n" , svLow(v,1));
    printf("svLeft(v,1)     = %d \n" , svLeft(v,1));
    printf("svRight(v,1)    = %d \n" , svRight(v,1));
    printf("svHigh(v,1)     = %d \n" , svHigh(v,1));
    printf("svDimensions(v) = %d \n" , svDimensions(v));

    for(int i=0; i<svLength(v,1); i++){
        printf("[%d] = %d \n", i , *((int*)svGetArrElemPtr(v,i)));
        sum = sum + *((int*)svGetArrElemPtr(v,i));
    }
    return sum;    
}