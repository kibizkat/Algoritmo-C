#include <stdlib.h>
#include <stdio.h>

void troquinha(int inteiro1, int inteiro2, int A){
    A = inteiro2;
    inteiro2 = inteiro1;
    inteiro1 = A;

    printf("O novo valor de A é %d, e o novo valor de B é %d\n", inteiro1, inteiro2);
}

int main(void){
    int inteiro1 = 0;
    int inteiro2 = 0;
    int A;

    printf("Digite o valor de A: ");
    scanf("%d", &inteiro1);

    printf("Digite o valor de B: ");
    scanf("%d", &inteiro2);

    troquinha(inteiro1,inteiro2,A);
}