//Leia um numero real e imprima o resultado do quadrado desse numero.
#include <stdio.h>
#include <stdlib.h>
int main() {
    float x, quadrado;

    printf("Digite um numero real: ");
    scanf("%f", &x);

    quadrado=x*x;
    printf("O quadrado do numero %f é: %.2f\n", x, quadrado);
    system("pause");
    return 0;
}