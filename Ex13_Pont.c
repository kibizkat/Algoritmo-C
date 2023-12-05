#include <stdio.h>

// Protótipo da função
void encontrarMaiorEContarOcorrencias(int *array, int tamanho);

int main() {
    int tamanho;

    // Solicitar ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Criar um array dinamicamente
    int *meuArray = (int *)malloc(tamanho * sizeof(int));

    // Solicitar ao usuário os elementos do array
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &meuArray[i]);
    }

    // Chamar a função para encontrar o maior elemento e contar as ocorrências
    encontrarMaiorEContarOcorrencias(meuArray, tamanho);

    // Liberar a memória alocada para o array
    free(meuArray);

    return 0;
}

// Implementação da função
void encontrarMaiorEContarOcorrencias(int *array, int tamanho) {
    if (tamanho <= 0) {
        printf("O array está vazio.\n");
        return;
    }

    int maior = array[0];
    int ocorrencias = 1;

    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
            ocorrencias = 1;
        } else if (array[i] == maior) {
            ocorrencias++;
        }
    }

    // Exibir o maior elemento e o número de ocorrências
    printf("Maior elemento: %d\n", maior);
    printf("Número de ocorrências: %d\n", ocorrencias);
}
