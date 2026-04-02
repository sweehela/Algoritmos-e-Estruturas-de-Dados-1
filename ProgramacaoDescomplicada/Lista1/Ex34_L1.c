//Leia o valor do raio de um círculo e calcule e imprima a área do círculo correspondente. A área do círculo é pi*raio^2, considere pi=3,141592.
#include <stdio.h>
#include <stdlib.h>

int main() {
    float r, a;

    printf("Digite o valor do raio do circulo: \n");
    scanf("%f", &r);

    a=3.141592*(r*r);

    printf("A area do circulo e aproximadamente: %.2f\n", a);
    
    system("pause");
    return 0;
}