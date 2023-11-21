//EXERCICIO 1 REVISAO PROVA

#include <stdio.h>
#include <stdlib.h>

struct bolsa{
    char nome[99];
    char atuacao[90];
    float valoratual;
    float valorant;
    double variacao;
};

typedef struct bolsa Bolsa[3];

void cadastro(Bolsa acao){
    printf("Digite o nome da Acao: ");
    fgets(acao->nome, sizeof(acao->nome), stdin);

    printf("Digite a Area de Atuacao da Acao: ");
    fgets(acao->atuacao, sizeof(acao->atuacao),stdin);

    printf("Digite o Valor atuacao: R$");
    scanf("%f", &acao->valoratual);

    printf("Digite o Valor Antigo: R$");
    scanf("%f", &acao->valorant);

    acao->variacao = ((acao->valoratual - acao->valorant) / acao->valorant) * 100; 

    setbuf(stdin, NULL);

}

void imprimir(Bolsa acao){
    printf("Nome: %s", acao->nome);
    printf("Area: %s", acao->atuacao);
    printf("Valor atual: %.2f", acao->valoratual);
    printf("Valor antigo: %.2f", acao->valorant);
    printf("Variacao: %.2f", acao->variacao);
    printf("\n\n");
}


int main(){
    Bolsa acao;
    float investimento = 0;

    for(int i = 0; i < 3; i++){
        cadastro(&acao[i]);
    }

    for(int i = 0; i < 3; i++){
        imprimir(&acao[i]);
    }

    printf("Digite o valor para pesquisar acoes com valores proximos: R$");
    scanf("%f", &investimento);

    for(int i = 0; i < 3; i++){
        if(investimento >= acao->valoratual){
            imprimir(&acao[i]);
        }
    }
}