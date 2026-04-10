/* 41. Faça um programa que leia o valor da hora de trabalho (em reais) e numero de horas trabalhadas no mes. Imprima o valor a ser pago ao
 funcionário, adicionando 10% sobre o valor calculado.*/
 #include <stdio.h>
 #include <stdlib.h>
  int main() {
    int horas;
    float valor, total;

    printf("Digite o valor por hora trabalhada: R$");
    scanf("%f", &valor);
    printf("\nDigite o numero de horas trabalhadas no mes: ");
    scanf("%d", &horas);

    total = (valor*horas)+(valor*horas*0.10);

    printf("\nValor a ser pago: R$%.2f\n", total);

    system("pause");
    return 0;
  }