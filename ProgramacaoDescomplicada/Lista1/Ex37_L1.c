//37. Faça um programa que leia o valor de um produto e imprima o valor com desconto, tendo em vista que o desconto foi de 12%.
#include <stdio.h>
#include <stdlib.h>

int main() {
    float x, y;

    printf("Digite o valor do produto: R$\n");
    scanf("%f", &x);

    y = x-(x*0.12);

    printf("O valor do produto com desconto e de: R$%.2f\n", y);

    system("pause");
    return 0;
}