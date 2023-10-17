#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct aluninho{
    char nome[10];
    char nomecomp[500];
    char curso[50];
    char nota1[5];
    char nota2[5];
};

typedef struct aluninho Aluno;

void nomezinho(Aluno *aluno){
    printf("Digite seu nome completo: ");
    scanf("%s", aluno->nome);
    fgets(aluno->nomecomp, sizeof(aluno->nomecomp), stdin);

}

void materia(Aluno *cursinho){
    printf("Digite seu Curso: ");
    fgets(cursinho->curso, sizeof(cursinho->curso),stdin);
}

void notinhainha(Aluno *notinha){
    printf("Digite sua nota 1: ");
    fgets(notinha->nota1, sizeof(notinha->nota1), stdin);
    printf("Digite sua nota 2: ");
    scanf("%s", notinha->nota2);

}

int main(){
    Aluno aluno;
    Aluno cursinho;
    Aluno notinha;
    FILE* arq;

    nomezinho(&aluno);


    arq = fopen(aluno.nome, "w");

    if(arq == NULL){
    
    }else{
        printf("Arquivo criado com sucesso.\n");}

    int r = 0;
    
    setbuf(stdin, NULL);

    int tamanho1 = 0;
    int tamanho2 = 0;
    
    tamanho1 += strlen(aluno.nome);
    tamanho2 += strlen(aluno.nomecomp);

    for(int i = 0; i < tamanho1; i++){
        r = fputc(aluno.nome[i], arq);
    }
    for(int i = 0; i < tamanho2; i++){
        r = fputc(aluno.nomecomp[i], arq);
    }

    materia(&cursinho);
    
    tamanho1 = 0;
    tamanho1 += strlen(cursinho.curso);

    for(int i = 0; i < tamanho1; i++){
        r = fputc(cursinho.curso[i], arq);
    }

    notinhainha(&notinha);

    tamanho1 = 0;
    tamanho1 += strlen(notinha.nota1);

    for(int i = 0; i < tamanho1; i++){
        r = fputc(notinha.nota1[i], arq);
    }
    
    tamanho1 = 0;
    tamanho1 += strlen(notinha.nota2);

    for(int i = 0; i < tamanho1; i++){
        r = fputc(notinha.nota2[i], arq);
    }





}