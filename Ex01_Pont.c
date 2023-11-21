#include <stdio.h>
#include <stdlib.h>

int main(void){
    int inteiro = 0;
    float real = 0;
    char letra = 0;
    int *i;
    float *r;
    char *l;

    printf("Digite um numero inteiro: ");
    scanf("%d", &inteiro);
    printf("Digite um numero real: ");
    scanf("%f", &real);
    setbuf(stdin,NULL);
    printf("Digite uma letra: ");
    scanf("%c", &letra);

    i = &inteiro;
    r = &real;
    l = &letra;


    printf("\n\nFoi salvo na memória:\n Inteiro %d\n Real %f\n Letra %c",*i,*r,*l);
    
    *i *= 2;
    *r *= 2;
    
    if((*l == 'a') || (*l == 'A')){
        *l = 'B';
    }else if((*l != 'a') || (*l !='A')){
        *l = 'A';
    }

    printf("\n\nOs novos numeros e letras são:\n Inteiro: %d\n Real: %f\n Letra: %c\n",*i,*r,*l);
    
}