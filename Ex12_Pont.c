#include <stdio.h>

// Protótipo da função
void preencherArray(int *array, int tamanho, int valor);

int main() {
    int tamanho;

    // Solicitar ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Criar um array dinamicamente
    int *meuArray = (int *)malloc(tamanho * sizeof(int));

    // Solicitar ao usuário um valor para preencher o array
    int valor;
    printf("Digite o valor para preencher o array: ");
    scanf("%d", &valor);

    // Chamar a função para preencher o array
    preencherArray(meuArray, tamanho, valor);

    // Exibir o array preenchido
    printf("Array preenchido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", meuArray[i]);
    }

    // Liberar a memória alocada para o array
    free(meuArray);

    return 0;
}

// Implementação da função
void preencherArray(int *array, int tamanho, int valor) {
    // Usar aritmética de ponteiros para percorrer o array e preencher os elementos
    for (int i = 0; i < tamanho; i++) {
        *(array + i) = valor;
    }
}
