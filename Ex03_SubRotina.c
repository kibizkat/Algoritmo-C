#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct vendedorzinho{
    char nome[999];
    float salario;
    float vendas;
    float comissao;
    float salariof;
};

typedef struct vendedorzinho Vend;

float resumo(Vend *relatorio){

    setbuf(stdin,NULL);

    printf("Digite seu nome: ");
    fgets(relatorio->nome,sizeof(relatorio->nome),stdin);

    printf("Digite seu salario: R$");
    scanf("%f", &relatorio->salario);
    
    printf("Digite seu valor de vendas: R$");
    scanf("%f", &relatorio->vendas);

    relatorio->comissao = relatorio->vendas * 0.06;

    relatorio->salariof = relatorio->salario + relatorio->comissao;

}

float resumo2(Vend *relatorio2){

    setbuf(stdin,NULL);

    printf("Digite seu nome: ");
    fgets(relatorio2->nome,sizeof(relatorio2->nome),stdin);

    printf("Digite seu salario: R$");
    scanf("%f", &relatorio2->salario);
    
    printf("Digite seu valor de vendas: R$");
    scanf("%f", &relatorio2->vendas);

    relatorio2->comissao = relatorio2->vendas * 0.06;

    relatorio2->salariof = relatorio2->salario + relatorio2->comissao;

}

int main(){
    Vend relatorio;
    Vend relatorio2;

    resumo(&relatorio);
    printf("\n");
    resumo2(&relatorio2);

    printf("\nOs dados finais são: \n\n");
    printf("Nome: %s",relatorio.nome);
    printf("Salario fixo: R$%.2f",relatorio.salario);
    printf("\nQuantidade vendida: R$%.2f",relatorio.vendas);
    printf("\nSua comissão foi de R$%.2f",relatorio.comissao);
    printf("\nSeu salario foi de R$%.2f\n\n",relatorio.salariof);

    printf("Nome: %s",relatorio2.nome);
    printf("Salario fixo: R$%.2f",relatorio2.salario);
    printf("\nQuantidade vendida: R$%.2f",relatorio2.vendas);
    printf("\nSua comissão foi de R$%.2f",relatorio2.comissao);
    printf("\nSeu salario foi de R$%.2f\n",relatorio2.salariof);

}