#include <stdio.h>

// Função para trocar dois valores
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ordenar três valores
void ordenarValores(int *val1, int *val2, int *val3) {
    if (*val1 > *val2) {
        trocar(val1, val2);
    }
    if (*val1 > *val3) {
        trocar(val1, val3);
    }
    if (*val2 > *val3) {
        trocar(val2, val3);
    }
}

int main() {
    int valor1, valor2, valor3;

    // Ler três valores inteiros
    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    printf("Digite o terceiro valor inteiro: ");
    scanf("%d", &valor3);

    // Chamar a função para ordenar os valores
    ordenarValores(&valor1, &valor2, &valor3);

    // Exibir os valores ordenados
    printf("Valores ordenados: %d, %d, %d\n", valor1, valor2, valor3);

    return 0;
}
