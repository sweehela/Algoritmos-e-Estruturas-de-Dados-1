//Leia o salário de um funcionário. Calcule e imprima o valor do novo salário, sabendo que ele recebeu um aumento de 25%.
#include <stdio.h>
#include <stdlib.h>

int main() {
    float x, y;

    printf("Digite o salario do funcionario: R$\n");
    scanf("%f", &x);

    y = x+(x*0.25);

    printf("O salario com o aumento e de: R$%.2f\n", y);

    system("pause");
    return 0;
}