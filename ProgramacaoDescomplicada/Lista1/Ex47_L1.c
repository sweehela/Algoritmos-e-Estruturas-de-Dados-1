/* 47. Leia um numero inteiro de 4 dígitos (de 1000 a 9999) e imprima 1 dígito por linha.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, mil, cen, dez, uni;

    printf("Digite um numero inteiro de 4 digitos (1000 - 9999): \n");
    scanf("%d", &n);

    if (n < 1000 || n > 9999) {
        printf("Numero invalido.\n");
        return 1;
    }

    mil = n/1000; //pega o milhar
    cen = (n/100) % 10; //pega a centena
    dez = (n/10) % 10; //pega a dezena
    uni = n % 10; //pega a unidade

    printf("---Numero em linhas---\n");
    printf("%d\n", mil);
    printf("%d\n", cen);
    printf("%d\n", dez);
    printf("%d\n", uni);

    system("pause");
    return 0;
}