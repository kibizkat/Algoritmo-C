#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct funcionariozinho{
    char nome[999];
    int idade;
    char sexo[999];
    char cpf[20];
    int dia;
    int mes;
    int ano;
    int setor;
    char cargo[999];
    float salario;
};

typedef struct funcionariozinho Fun;


void cadastro(Fun *diversao){

    printf("Digite seu nome completo:\n");
    fgets(diversao->nome, sizeof(diversao->nome), stdin);

    printf("Digite sua idade: \n");
    scanf("%d", &diversao->idade);
    setbuf(stdin, NULL);

    printf("Digite seu Sexo: \n");
    fgets(diversao->sexo, sizeof(diversao->sexo), stdin);
    setbuf(stdin, NULL);

    printf("Digite seu CPF: \n");
    fgets(diversao->cpf, sizeof(diversao->cpf), stdin);
    setbuf(stdin, NULL);

    printf("Digite sua data de nascimento (Separada com espaço) \n");
    scanf("%d %d %d", &diversao->dia, &diversao->mes, &diversao->ano);

    printf("digite seu codigo de setor\n");
    while(true){
        scanf("%d", &diversao->setor);
        if(diversao->setor >= 0 && diversao->setor < 100){
            break;
        }else{
            printf("Codigo invalido, tente novamente. \n");
        }
    }
    setbuf(stdin,NULL);

    printf("Digite seu cargo\n");
    fgets(diversao->cargo,sizeof(diversao->cargo),stdin);

    printf("Digite seu salario: R$");
    scanf("%f", &diversao->salario);
}

int main(){
    Fun diversao;

    cadastro(&diversao);

    printf("\n\n\n\nOs dados cadastrados foram:\n\n");

    printf("Nome: %s",diversao.nome);
    printf("Idade: %d\n",diversao.idade);
    printf("Sexo: %s",diversao.sexo);
    printf("CPF: %s",diversao.cpf);
    printf("Data de nascimento: %d/%d/%d",diversao.dia, diversao.mes, diversao.ano);
    printf("\nCodigo de setor: %d",diversao.setor);
    printf("\nCargo: %s",diversao.cargo);
    printf("Salario: R$%.2f\n",diversao.salario);

}