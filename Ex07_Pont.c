#include <stdlib.h>
#include <stdio.h>

int main(void){
    float n[10];
    int contador = 1;
    float buscador;

    printf("Digite em seguencia 10 numeros");

    for(int i = 0; i < 10; i++){
        printf("\nDigite o %d° numero: ",contador);
        scanf("%f", &n[i]);
        contador++;
    }

    printf("Digite o numero desejado para saber seu endereço: ");
    scanf("%f", &buscador);

    for(int i = 0; i < 10; i++){
        if(buscador == n[i]){
            printf("\nO endereço deste numero é %d",(i+1));
        }
    }
}