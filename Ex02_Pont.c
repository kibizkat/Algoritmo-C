#include <stdlib.h>
#include <stdio.h>

int main(void){
    int inteiro = 15;
    int inteiro2 = 20;
    int *A;
    int *B;

    A = &inteiro;

    B = &inteiro2;

    if(*A > *B){
        printf("O maior valor digitado foi: %d\n", *A);
    }else if(*A == *B){
        printf("Os valores são iguais.\n");
    }else if(*A < *B){
        printf("O Maior valor digitado foi: %d\n", *B);
    }
}