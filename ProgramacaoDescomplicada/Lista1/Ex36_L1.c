//36. Leia a altura e o raio de um cilindro circular e imprima o volume do cilindro. O volume é calculado por: v=pi*raio^2*altura.
#include <stdio.h>
#include <stdlib.h>

int main() {
    float a, r, v;

    printf("Digite a altura do cilindro circular: \n");
    scanf("%f", &a);
    printf("Digite o raio do cilindro circular: \n");
    scanf("%f", &r);

    v = 3.141592*(r*r)*a;

    printf("O volume do cilindo circular e: %.2f\n", v);

    system("pause");
    return 0;
}