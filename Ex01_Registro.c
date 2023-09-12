#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor{
    int cod;
    char sex;
    float hours;
};
typedef struct professor Prof;

int main(){
    Prof x[10];
    float mediam =0;
    float mediaf = 0;
    int contm = 0;
    int contf = 0;
    float salario[10];
    float liq[10];
    float desc[10];
    char masc = 'm';
    char fem = 'f';

    for(int i = 0; i < 2; i++){
        scanf("%d", &x[i].cod);
        setbuf(stdin,NULL);
        scanf("%c", &x[i].sex);
        setbuf(stdin,NULL);
        scanf("%f", &x[i].hours);
        salario[i] = x[i].hours * 60.5;
        if(x[i].hours >= 70){
            liq[i] = salario[i] - (salario[i]*0.05);
            desc[i] = salario[i]*0.05;
        }
        else{
            liq[i] = salario[i] - (salario[i]*0.08);
            desc[i] = salario[i]*0.08;
        }
    }

    for(int i = 0; i < 10; i++){
    if(x[i].sex == masc){
    mediam = x[i].hours + mediam;
    }
    else{
    mediaf = x[i].hours + mediaf;
    }
    }

    for(int i = 0; i < 10; i++){
        printf("\n\nO %d° professor possui as seguintes informações atribuidas:\n",(i+1));
        printf("Código: %d\nSexo: %c\nHoras: %.2f\n", x[i].cod, x[i].sex, x[i].hours);
        printf("Salario bruto: R$%.2f\n",salario[i]);
        printf("salario liquido: R$%.2f\n", liq[i]);
        printf("Desconto: %.2f", desc[i]);
    }

    printf("Media salarial masculina: R$%.2f\n",mediam);
    printf("Media salarial feminina: R$%2.f\n", mediaf);
}