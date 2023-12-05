#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Protótipo da função
void calc_esfera(float R, float *area, float *volume);

int main() {
    float raio, area, volume;

    // Solicitar ao usuário o raio da esfera
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    // Chamar a função para calcular a área e o volume da esfera
    calc_esfera(raio, &area, &volume);

    // Exibir os resultados
    printf("Área da superfície: %.2f\n", area);
    printf("Volume: %.2f\n", volume);

    return 0;
}

// Implementação da função
void calc_esfera(float R, float *area, float *volume) {
    // Calcular a área da superfície e o volume da esfera
    *area = 4.0 * PI * pow(R, 2);
    *volume = (4.0 / 3.0) * PI * pow(R, 3);
}
