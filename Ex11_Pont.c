#include <stdio.h>

// Protótipo da sub-rotina
void medidas_retangulo(double *lado1, double *lado2);

int main() {
    double comprimento, largura;

    // Solicitar ao usuário as medidas dos lados do retângulo
    printf("Digite o comprimento do retângulo: ");
    scanf("%lf", &comprimento);

    printf("Digite a largura do retângulo: ");
    scanf("%lf", &largura);

    // Chamar a sub-rotina para calcular a área e o perímetro do retângulo
    medidas_retangulo(&comprimento, &largura);

    // Exibir os resultados
    printf("Área do retângulo: %.2lf\n", comprimento);
    printf("Perímetro do retângulo: %.2lf\n", largura);

    return 0;
}

// Implementação da sub-rotina
void medidas_retangulo(double *var1, double *var2) {
    // Calcular a área e o perímetro do retângulo
    *var1 = (*var1) * (*var2);      // Área = comprimento * largura
    *var2 = 2 * ((*var1) + (*var2));  // Perímetro = 2 * (comprimento + largura)
}
