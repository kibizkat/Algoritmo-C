#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main(){
    FILE* arq;
    char palavra[999];
    int n = 0;
    char resp;

    arq = fopen("Cliente.txt", "w");

    if(arq == NULL){

    }else{
    printf("Arquivo criado com sucesso.\n");}


    // printf("Digite sua frase: ");
    // fgets(palavra, sizeof(palavra), stdin);

    // fprintf(arq , "%s " , palavra);

    // if(fprintf != 0){
    //     printf("Arquivo salvo");
    // }else if("fprintf == 0"){
    //     printf("Houve um erro ao salvar o arquivo.");
    // }

    int r = 0;
    while(true){
    printf("Deseja adicionar uma frase?\n");
    scanf("%c", &resp);
    setbuf(stdin,NULL);
    if(resp == 's'){
        n+=1;
    }else if(resp != 's'){
        break;
    }

    for(int i = n-1; i < n; i++){
    palavra[999];
    printf("Digite sua frase: ");
    fgets(palavra, sizeof(palavra), stdin);
    setbuf(stdin, NULL);

    int tamanho = 0;
    
    tamanho += strlen(palavra);

    for(int i = 0; i < tamanho; i++){
    r = fputc(palavra[i], arq);
    };
    
    }
    }

    if(r == EOF){
        printf("Houve um erro ao salvar o arquivo.\n");
    }else if(r != EOF){
        printf("Arquivo salvo.\n");
    }

    int fclose(FILE* arq);
}