#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int multi(int n){
    return (n*2);
}

int multi2(int n1){
    return (n1*2);
}

int main(){
    int n;
    int n1;

    printf("Digite 2 valores aleatorios: ");
    scanf("%d", &n);
    scanf("%d", &n1);

    multi(n);
    multi2(n1);

    n = multi(n);
    n1 = multi2(n1);

    printf("Primeiro valor %d, Segundo Valor %d\n",n,n1);
}