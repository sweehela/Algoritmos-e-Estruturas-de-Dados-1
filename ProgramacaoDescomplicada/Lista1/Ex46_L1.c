/* Faça um programa que leia um numero inteiro positivo de três díıgitos (de 100 a 999). Gere outro número formado pelos dígitos invertidos do numero lido.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, cen, dez, uni, inv;

    printf("Digite um numero inteiro de 3 digitos (100 - 999): \n");
    scanf("%d", &n);

    if (n < 100 || n > 999) {
        printf("Numero invalido.\n");
        return 1;
    }

    cen = n/100; //pega a centena
    dez = (n/10) % 10; //pega a dezena
    uni = n % 10; //pega a unidade

    inv = uni * 100 + dez * 10 + cen;

    printf("Numero invertido: %d\n", inv);

    system("pause");
    return 0;
}