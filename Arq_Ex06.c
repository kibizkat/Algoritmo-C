#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct criador{
    char nome[50];
    char frase[999];
    char frase2[999];
};

typedef struct criador Cria;

void cria(Cria *criacao){
    printf("Digite o nome do arquivo: ");
    fgets(criacao->nome, sizeof(criacao->nome), stdin);

    printf("Digite a frase a ser Salva: ");
    fgets(criacao->frase, sizeof(criacao->frase), stdin);
}

void cria2(Cria *criacao2){
    printf("Digite o nome do arquivo: ");
    fgets(criacao2->nome, sizeof(criacao2->nome), stdin);

    printf("Digite a frase a ser Salva: ");
    fgets(criacao2->frase2, sizeof(criacao2->frase2), stdin);
}

// void cria2(Cria *criacao2, Cria criacao){
//     int n = 1;
//     int tamanho = 0;

//     tamanho += strlen(criacao.nome);
//     for(int i = 0; i < (tamanho+1); i++){
//         if(i == tamanho){
//             criacao.nome[i] = n;
//         }else if(criacao.nome[i] == n){
//             criacao.nome[i] = n+1;
//         }else if(criacao.nome[i] == (n+1)){
//             criacao.nome[i] = n+2;
//         }
//     }
// }

int main(){
    Cria criacao;
    Cria criacao2;
    FILE* arq;
    char charac = '*';

    cria(&criacao);

    // cria2(&criacao2, criacao);

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

        cria(&criacao2);

    arq = fopen(criacao2.nome, "w");

    if(arq == NULL){
    
    }else{
        printf("Arquivo criado com sucesso.\n");}

     r = 0;
    
    setbuf(stdin, NULL);

     tamanho = 0;
    
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
    for(int i = 0; i < (tamanho2); i++){
        if(i == (tamanho2-1)){
            criacao.nome[i] = '3';
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
            r = fputc(criacao.frase[i], arq);
    }

    setbuf(stdin, NULL);
    r = 0;
        
    tamanho = 0;

    tamanho += strlen(criacao2.frase2);
    
    for(int i = 0; i < tamanho; i++){
            r = fputc(criacao2.frase2[i], arq);
    }

        if(r == EOF){
        printf("Houve um erro ao salvar o arquivo.\n");
    }else if(r != EOF){   
        printf("Arquivo salvo.\n");
    }

    int fclose(FILE* arq);

}