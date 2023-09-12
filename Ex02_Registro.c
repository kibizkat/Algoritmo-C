#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct cidade{
    int year;
    float salary;
    char sex;
    int kids;
};

typedef struct cidade City;

int main(){
    City x;
    int contador = 0;
    int idade = 0;
    float salario = 0;
    int idadem = 0;
    int filho = 0;
    char masc = 'M';
    char fem = 'F';
    float maiors =0;
    int menori = 100;
    int contm =0;
    
    while(true){
        printf("Digite a idade: ");
        scanf("%d", &x.year);
        idade = idade + x.year;

        if(x.year == 0){
            break;
        }

        setbuf(stdin,NULL);
        
        printf("Digite o generio (Utilizando M ou F): ");
        scanf("%c", &x.sex);

        printf("Digite o salario: R$");
        scanf("%f", &x.salary);
        salario = salario + x.salary;

        printf("Digite a quantidade de filhos: ");
        scanf("%d", &x.kids);
        filho = filho + x.kids;

        contador++;
        
        if(x.sex == fem){
            contm++;
        }

        if(x.salary < 300 && x.sex == fem){
        idadem = idadem + x.year;
        }

        if(maiors < x.salary){
            maiors = x.salary;
        }

        if(menori > x.year){
            menori = x.year;
        }
    }

    idadem = idadem/contm;
    salario = salario/contador;
    filho = filho/contador;

    printf("\n\n\nMedia da idade das mulheres que recebem salario inferiores a R$300,00\n%d\n",idadem);
    printf("A média de salario da população: R$%.2f\n",salario);
    printf("A média de filhos da populacao é de %d filho(s)\n",filho);
    printf("O Maior salario é de R$%.2f\n",maiors);
    printf("A menor idade é de %d\n",menori);

}