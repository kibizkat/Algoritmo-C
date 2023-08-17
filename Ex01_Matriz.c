#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

    int matriz[3][3];
    int tempo = time(0);
    int maior = 0;
    srand(tempo);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){        
            matriz[i][j] = rand() % 100;
            if(maior < matriz[i][j]){
                maior = matriz[i][j];
            }
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ",matriz[i][j]);
        }
    printf("\n");
    }

    printf("O maior valor da matriz eh %d\n",maior);
}