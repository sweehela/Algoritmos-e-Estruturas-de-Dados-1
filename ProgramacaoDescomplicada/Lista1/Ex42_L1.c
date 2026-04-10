/*42. Receba o salário base de um funcionário. Calcule e imprima o salário a receber, sabendo-se que esse funcionario tem uma gratificão de
5% sobre o salário base. Além disso, ele paga 7% de imposto sobre o salario base.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    float base, bonus, imposto, total;

    printf("Digite o salario base: R$");
    scanf("%f", &base);

    bonus = base*0.05;
    imposto = base*0.07;
    total = base+bonus-imposto;

    printf("\nO total do salario sera de: R$%.2f\n", total);

    system("pause");
    return 0;
}