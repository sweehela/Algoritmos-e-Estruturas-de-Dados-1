//31. Leia um número inteiro e imprima o seu antecessor e o seu sucessor.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &x);

    printf("Antecessor: %d\nSucessor: %d\n", x-1, x+1);

    system("pause");
    return 0;
}