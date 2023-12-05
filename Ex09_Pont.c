#include <stdio.h>

int main() {
    int A;
    int *B, **C, ***D;

    // Inicialização dos ponteiros
    B = &A;
    C = &B;
    D = &C;

    // Leitura da variável A
    printf("Digite o valor de A: ");
    scanf("%d", &A);

    // Cálculo e exibição do dobro, triplo e quádruplo usando ponteiros
    printf("Dobro: %d\n", (*B) * 2);
    printf("Triplo: %d\n", (**C) * 3);
    printf("Quádruplo: %d\n", (***D) * 4);

    return 0;
}
