#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void aleatorio(int vetor[20]){
    srand(time(NULL));
        for(int i = 0; i < 20; i++){
            vetor[i] = rand() % 999;
        }
}

void numero(int n, int vetor[20]){
    printf("\ndigite um numero entre 1 e 999\n");
    scanf("%d", &n);

    for(int i = 0; i < 20; i++){
        if(vetor[i] == n){
            n = 0;
            break;
        }
    }
}

int main(){
    int vetor[20];
    int n = 0;

    aleatorio(vetor);
    numero(n,vetor);

    if(n == 0){
        printf("Esse numero esta presente no vetor\n");
    }else{
        printf("Esse numero nao esta presente no vetor\n");
    }


}