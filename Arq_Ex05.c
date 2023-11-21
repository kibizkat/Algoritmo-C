#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct criador{
    char nome[50];
    char frase[999];
};

typedef struct criador Cria;

void cria(Cria *criacao){
    printf("Digite o nome do arquivo: ");
    fgets(criacao->nome, sizeof(criacao->nome), stdin);

    printf("Digite a frase a ser Salva: ");
    fgets(criacao->frase, sizeof(criacao->frase), stdin);
}

int vogal (char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main(){
    Cria criacao;
    FILE* arq;
    char charac = '*';

    cria(&criacao);

    arq = fopen(criacao.nome, "w");

    if(arq == NULL){
    
    }else{
        printf("Arquivo criado com sucesso.\n");}

    int r = 0;
    
    setbuf(stdin, NULL);

    int tamanho = 0;
    
    tamanho += strlen(criacao.frase);

    for(int i = 0; i < tamanho; i++){
        r = fputc(criacao.frase[i], arq);
    }

    if(r == EOF){
        printf("Houve um erro ao salvar o arquivo.\n");
    }else if(r != EOF){   
        printf("Arquivo salvo.\n");
    }

    int fclose(FILE* arq);

    int tamanho2 = 0;

    tamanho2 += strlen(criacao.nome);
    for(int i = 0; i < (tamanho2+1); i++){
        if(i == tamanho2){
            criacao.nome[i] += '_2';
        }
    }
    arq = fopen(criacao.nome, "w");

    if(arq == NULL){
    
    }else{
        printf("Arquivo criado com sucesso.\n");}

    r = 0;
    
    setbuf(stdin, NULL);

    tamanho = 0;
    
    tamanho += strlen(criacao.frase);

    for(int i = 0; i < tamanho; i++){
        if(vogal(criacao.frase[i])){
            criacao.frase[i]= charac;
            }
            r = fputc(criacao.frase[i], arq);
    }

        if(r == EOF){
        printf("Houve um erro ao salvar o arquivo.\n");
    }else if(r != EOF){   
        printf("Arquivo salvo.\n");
    }

    int fclose(FILE* arq);

}