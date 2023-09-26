#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>  

void somadiv(int num, int *soma){
    for(int i = 1; i <= num; i++){
        if(num % i == 0){
        *soma += i;
        }else{}
    }
}

int main(){
    int num;
    int soma = 0;;

    printf("Digite um valor para saber a soma de seus divisores: \n");

    while(true){
        scanf("%d", &num);
        
        if(num > 0){
            break;
        }else if(num <= 0){
            printf("numero invalido tente novamente!\n\n");
        }
    }

    somadiv(num, &soma);

    printf("A soma de seus divisores é de: %d",soma);
}