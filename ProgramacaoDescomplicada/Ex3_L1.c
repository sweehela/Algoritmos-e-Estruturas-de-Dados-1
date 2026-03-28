//Peca ao usuario para digitar tres valores inteiros e imprima a soma deles.
#include <stdio.h>
#include <stdlib.h>

int main () {
    int x, y, z, soma;

    printf("Digite tres numeros inteiros: ");
    scanf("%d %d %d", &x, &y, &z);

    soma=x+y+z;
    printf("Resultado da soma dos tres numeros: %d\n", soma);
    system("pause");
    return 0;
}