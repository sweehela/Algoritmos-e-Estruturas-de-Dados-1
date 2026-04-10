/*43. Escreva um programa de ajuda para vendedores. A partir de um valor total lido, mostre:
• o total a pagar com desconto de 10%;
• o valor de cada parcela, no parcelamento de 3× sem juros;
• a comissao do vendedor, no caso da venda ser a vista (5% sobre o valor com desconto)
• a comissao do vendedor, no caso da venda ser parcelada (5% sobre o valor total)*/
#include <stdio.h.>
#include <stdlib.h>

int main() {
    float valor, desconto, parcela, comivista, comiparc;

    printf("Digite o valor da compra: R$");
    scanf("%f", &valor);

    desconto = valor-(valor*0.1);
    parcela = valor/3;
    comivista = desconto+(desconto*0.05);
    comiparc = valor+(valor*0.05);

    printf("\nO total com desconto e de: R$%.2f", desconto);
    printf("\nO valor a ser pago com o parcelamento de 3x: R$%.2f", parcela);
    printf("\nA comissao a ser paga na venda a vista e de: R$%.2f", comivista);
    printf("\nA comissao a ser paga na venda parcelada e de: R$%.2f\n", comiparc);

    system("pause");
    return 0;
}