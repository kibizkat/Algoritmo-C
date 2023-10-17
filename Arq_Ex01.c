#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main(){
    FILE* arq;
    char palavra[999];
    char resp;

    arq = fopen("arq.txt", "w");

    if(arq == NULL){

    }else{
    printf("Arquivo criado com sucesso.\n");}

    int r = 0;

    printf("Digite sua frase: ");
    
    fgets(palavra, sizeof(palavra), stdin);
    
    setbuf(stdin, NULL);

    int tamanho = 0;
    
    tamanho += strlen(palavra);

    for(int i = 0; i < tamanho; i++){
        if(palavra[i] == '0'){
            break;
        }
    
        r = fputc(palavra[i], arq);
    }

    if(r == EOF){
        printf("Houve um erro ao salvar o arquivo.\n");
    }else if(r != EOF){   
        printf("Arquivo salvo.\n");
    }

    int fclose(FILE* arq);
}