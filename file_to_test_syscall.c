#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/types.h>

#define KERNEL_2D_MEMCPY 451

float arr_cpy[3][5];

void main(){
    float arr[3][5] ={
        {1,4,2,6,0},
        {8,6,1,3,0},
        {9,0,1,5,3}
    };
    
    long sys_call_status = syscall(KERNEL_2D_MEMCPY , (float*)arr , (float*)arr_cpy , 3 , 5 );
    if(sys_call_status != EFAULT){
        int i = 0 ;
        int j = 0 ;
        while(i < 3){
            while(j < 5){
                if(!(*(arr+i*5) == *(arr_cpy+i*5))){
                    printf("%s" , "unequal");
                    return ;
                }
                j++;
            }
            i++;
        }
        printf("%s" , "equal");
        return ;
        
    }
    return ; 
}
    
