/* 40. Uma empresa contrata um encanador a R$30,00 por dia. Faça um programa que solicite o número de dias trabalhados pelo encanador e
imprima a quantia líquida que deverá ser paga, sabendo-se que sao descontados 8% para imposto de renda.*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int dias; 
    float total;

    printf("Digite o numero de dias trabalhados: \n");
    scanf("%d", &dias);
    
    total = (30*dias)-(30*dias*0.08);

    printf("O total com o desconto do imposto e de: %.2f\n", total);

    system("pause");
    return 0;
}