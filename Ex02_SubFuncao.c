#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void produto(float antigo, float novo, float *acres){
    if(antigo > novo){
        *acres = ((antigo - novo)/antigo)*100;
    }else if(novo > antigo){
        *acres = ((novo - antigo)/antigo)*100;
    }
}

int main(){
    float antigo = 0;
    float novo = 0;
    float acres = 0;

    printf("Digite o valor antigo do produto: R$");
    scanf("%f", &antigo);

    printf("Digite o valor atual deste produto: R$");
    scanf("%f", &novo);

    produto(antigo, novo, &acres);

    if(antigo > novo){
        printf("O produto teve uma depreciação de %.1f porcento",acres);
    }else if(novo > antigo){
        printf("O produto teva uma valorizacao de %.1f porcento",acres);
    }
}