#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor{
    int cod;
    char sex[15];
    float hours;
};
typedef struct professor Prof;

int main(){
    Prof x[10];

    for(int i = 0; i < 10; i++){
        scanf("%d", &x[i].cod);
        setbuf(stdin,NULL);
        fgets(x[i].sex, sizeof(x[i].sex),stdin);
        setbuf(stdin,NULL);
        scanf("%f", &x[i].hours);
    }

    for(int i = 0; i < 10; i++){
        printf("\n\nO %d° professor possui as seguintes informações atribuidas:\n",(i+1));
        printf("Código: %d\nSexo: %sHoras: %.2f\n", x[i].cod, x[i].sex, x[i].hours);
    }
}