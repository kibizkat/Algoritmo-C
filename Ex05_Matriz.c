#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

    float venda[4][3];
    float semana[4];
    float mes = 0;
    int cont = 1;
    float vend1,vend2,vend3;

    for(int i = 0; i < 4; i++){
       
    printf("Semana %d\n",(i+1));
        cont = 1;
        for(int j = 0; j < 3; j++){
        printf("Valor vendido pela vendedora %d\n",cont);
        scanf("%f", &venda[i][j]);
        cont++;
        }
    }

    printf("\n");
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
            vend1 += venda[i][j];
            }else if(j == 1){
            vend2 += venda[i][j];
            }else{
            vend3 += venda[i][j];
            }
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            semana[i] += venda[i][j];

            mes += venda[i][j];
        }
    }
    
    printf("Vendedora 1 vendeu este mes: R$%.2f\n",vend1);
    printf("Vendedora 2 vendeu este mes: R$%.2f\n",vend2);
    printf("Vendedora 3 vendeu este mes: R$%.2f\n\n",vend3);

    cont = 0;

    for(int i = 0; i < 4; i++){
        printf("O total vendido na semana %d foi de R$%.2f\n",cont,semana[i]);
        cont++;
    }

    printf("\nO total vendido neste mes foi de R$%.2f\n",mes);
        
}