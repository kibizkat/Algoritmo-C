#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float maior(float n1, float n2){
    if(n1 > n2){
        return n1;
    }else{
        return n2;
    }
}

float raiz(float n3){
    n3 = sqrt(n3);
    return n3;
}

float fato(float n4, int fat){
    fat = 1;
    for(int i = 1; i <= n4; i++){
        fat *= i;
    }
    return fat;
}

int main(){
    float n1 = 0;
    float n2 = 0;
    float n3 = 0;
    float n4 = 0;
    float m = 0;
    float r = 0;
    float fac = 0;
    int fat = 0;

    printf("Digite dois valores para saber qual é o maior: \n");
    scanf("%f", &n1);
    scanf("%f", &n2);

    m = maior(n1,n2);
    
    printf("%.1f\n",m);

    printf("Digite um valor para saber sua raiz: \n");
    scanf("%f", &n3);

    r = raiz(n3);

    printf("%.0f\n",r);

    printf("Digite um valor para saber seu fatorial: \n");
    scanf("%f", &n4);

    fac = fato(n4,fat);

    printf("%.0f\n",fac);
}