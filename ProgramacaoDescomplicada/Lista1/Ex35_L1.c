//35. Sejam a e b os catetos de um triângulo, onde a hipotenuca é obtida pela equação: raiz de a^2+b^2. faça um programa que receba os valores a e b e calcule o valor da hipotenusa.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a, b, h;

    printf("Digite os catetos do triangulo: \n");
    scanf("%f %f", &a, &b);

    h = sqrt((a*a)+(b*b)); //sqrt calcula a raiz na biblioteca math.h

    printf("O valor da hipotenusa e: %.2f\n", h);

    system("pause");
    return 0;
}
