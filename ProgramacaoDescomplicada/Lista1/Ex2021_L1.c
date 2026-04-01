/*Leia um valor de massa em quilogramas e apresente-o convertido em libras. A formula de conversão é: L = K/0.45.
21. Leia um valor de massa em libras e apresente-o convertido em quilogramas. A formula de conversão é: K = L ∗ 0.45.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int op;
    float kg, l;

    printf("Digite a conversao que deseja executar: \n");
    printf("1. Quilogramas -> Libras\n");
    printf("2. Libras -> Quilogramas\n");
    scanf("%d", &op);

    if (op==1) {
        printf("\nDigite a massa em quilogramas: \n");
        scanf("%f", &kg);
        l = kg/0.45;
        printf("A massa %.2f em libras e: %.2f\n", kg, l);
    }
    else if(op==2) {
        printf("\nDigite a massa em libras: \n");
        scanf("%f", &l);
        kg = l*0.45;
        printf("A massa %.2f em quilogramas e: %.2f\n", l, kg);
    }
    else {
        printf("Opcao invalida.\n");
        return 0;
    }
    system("pause");
    return 0;
}
