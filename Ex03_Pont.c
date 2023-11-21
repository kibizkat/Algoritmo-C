#include <stdlib.h>
#include <stdio.h>

int main(void){
    int inteiro = 0;
    int inteiro2 = 0;
    int *A;
    int *B;

    printf("Digite um valor Inteiro: ");
    scanf("%d", &inteiro);

    A = &inteiro;

    printf("Digite um outro valor Inteiro: ");
    scanf("%d", &inteiro2);

    B = &inteiro2;

    if(*A > *B){
        printf("O maior valor digitado foi: %d\n", *A);
    }else if(*A == *B){
        printf("Os valores são iguais.\n");
    }else if(*A < *B){
        printf("O Maior valor digitado foi: %d\n", *B);
    }
}