#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void calculo(float *total, float avaliacao, float nota1, float nota2, float nota3){

if((avaliacao == 'A') || (avaliacao == 'a')){
 *total = (nota1+nota2+nota3)/3;

}else if((avaliacao == 'P') || (avaliacao == 'p')){
    *total = ((nota1 * 5) + (nota2 * 3) + (nota3 * 2))/10;
}

}

int main(){
    float nota1 = 0;
    float nota2 = 0;
    float nota3 = 0;
    char avaliacao;
    float total;

    printf("Digite A para calcular a media aritmetica do aluno ou P para calcular a media ponderada: \n");
    
    while(true){
        scanf("%c", &avaliacao);
        if((avaliacao == 'A') || (avaliacao == 'a') || (avaliacao == 'P') || (avaliacao == 'p')){
            break;
        }else{
            printf("Opcao invalida tente novamente!\n");
        }
    }
    
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    calculo(&total, avaliacao, nota1, nota2, nota3);

    if((avaliacao == 'A') || (avaliacao == 'a')){
        printf("Vossa media Aritmetica é de: %.1f",total);

    }else if((avaliacao == 'P') || (avaliacao == 'p')){
        printf("Vossa media Ponderada é de: %.1f",total);
    }

}