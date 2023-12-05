#include <stdio.h>
#include <stdlib.h>

// Protótipo da função
int somarArrays(const int *array1, const int *array2, int *resultado, int tamanho);

int main() {
    int tamanho;

    // Solicitar ao usuário o tamanho dos arrays
    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    // Criar dois arrays dinamicamente
    int *array1 = (int *)malloc(tamanho * sizeof(int));
    int *array2 = (int *)malloc(tamanho * sizeof(int));

    // Preencher os arrays com valores fornecidos pelo usuário
    printf("Digite os elementos do primeiro array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Digite os elementos do segundo array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array2[i]);
    }

    // Criar um array para armazenar a soma
    int *somaArray = (int *)malloc(tamanho * sizeof(int));

    // Chamar a função para somar os arrays
    int resultado = somarArrays(array1, array2, somaArray, tamanho);

    // Verificar o resultado e exibir a soma se for bem-sucedido
    if (resultado == 1) {
        printf("Soma dos arrays:\n");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", somaArray[i]);
        }
        printf("\n");
    } else {
        printf("Os arrays têm tamanhos diferentes. A soma não pode ser realizada.\n");
    }

    // Liberar a memória alocada para os arrays
    free(array1);
    free(array2);
    free(somaArray);

    return 0;
}

// Implementação da função
int somarArrays(const int *array1, const int *array2, int *resultado, int tamanho) {
    // Verificar se os tamanhos dos arrays são iguais
    if (tamanho <= 0) {
        return 0; // Código de erro: tamanhos diferentes
    }

    // Somar os arrays e armazenar o resultado no terceiro array
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = array1[i] + array2[i];
    }

    return 1; // Código de sucesso
}
