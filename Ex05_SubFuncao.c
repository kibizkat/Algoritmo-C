#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void matrizinhapai(int matriz[3][4]){
    printf("Digite os valores da matriz: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("Matriz [%d][%d]: ",i,j);
            scanf("%d", &matriz[i][j]);
        }
    }

}

void vetorzinho(int vetor[12], int matriz[3][4]){
    int k = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            vetor[k] = matriz[i][j];
            k++;
        }
    }
}

int main(){
    int matriz[3][4];
    int vetor[12];

        matrizinhapai(matriz);
        vetorzinho(vetor, matriz);

        printf("Valores Resultantes:\n");

        for(int k = 0; k < 12; k++){
            printf("%d ",vetor[k]);
        }

        printf("\n");
}