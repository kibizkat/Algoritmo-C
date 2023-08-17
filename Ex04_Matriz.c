#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

    int matriz[3][6];
    int tempo = time(0);
    int maior = 0;
    srand(tempo);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){        
            matriz[i][j] = rand() % 100;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            printf("%d ",matriz[i][j]);
        }
    printf("\n");
    }

}