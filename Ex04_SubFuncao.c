#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void vetorial(int *num){
    for(int i = 0; i < 25; i++){
        if(*num < 0){
            *num = 0;
        }
    }
}

int main(){
    int num[25];
    int m = 0;

    printf("digite 25 valores inteiros:\n");
    for(int i = 0; i < 25; i++){
        scanf("%d" ,&num[i]);
    }

    for(int i = 0; i < 25; i++){
        vetorial(&num[i]);
        printf("%d ",num[i]);
    }
}