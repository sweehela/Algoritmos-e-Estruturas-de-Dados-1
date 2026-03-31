//Leia um numero real e imprima o resultado do quadrado desse núumero.
#include <stdio.h>
#include <stdlib.h>

int main () {
    float x, y;

    printf("Digite um numero real: \n");
    scanf("%f", &x);
    y=x*x;
    printf("O quadrado do numero %.2f e: %.2f\n", x, y);

    system("pause");
    return 0;
}