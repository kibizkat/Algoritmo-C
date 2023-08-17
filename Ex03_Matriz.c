#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

    int matriz[3][4];
    int tempo = time(0);
    int maior = 0;
    srand(tempo);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){        
            matriz[i][j] = rand() % 100;
            if(maior < matriz[i][j]){
                maior = matriz[i][j];
            }
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(matriz[i][j] % 2 == 0){
            matriz[i][j] *= 2;
            }else{
                matriz[i][j] *= 3;
            }
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ",matriz[i][j]);
        }
    printf("\n");
    }

}