//32. Leia um número inteiro e imprima a soma do sucessor de seu triplo com o antecessor de seu dobro.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &x);

    printf("O triplo do sucessor de %d somado com o dobro do antecessor de %d e igual a: %d\n", (x+1)*3, (x-1)*2, ((x+1)*3)+((x-1)*2));

    system("pause");
    return 0;
}