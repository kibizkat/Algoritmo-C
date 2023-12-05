#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int n0;
    int* maior;
    int* menor;

    printf("Digite 2 valores aletorios: ");
        scanf("%d", &n);
        scanf("%d", &n0);
    
    if(n > n0){
        maior = &n;
        menor = &n0;
    }else{
        maior = &n0;
        menor = &n;
    }

    printf("O maior valor é %d, e o menor valor é %d", *maior,*menor);
}