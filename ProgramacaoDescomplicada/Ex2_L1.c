//Faca um programa que leia um numero real e o imprima.
#include <stdio.h>
#include <stdlib.h>

int main () {
    double x;

    printf("Escreva um numero real: ");
    scanf("%lf", &x);

    printf("O numero escolhido foi: %.10lf\n", x);
    system("pause");
    return 0;
}
