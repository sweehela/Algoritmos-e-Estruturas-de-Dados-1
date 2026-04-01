//30. Leia um valor em real e a cotação em dólar. Em seguida, imprima o valor correspondente em dólares.
#include <stdio.h>
#include <stdlib.h>

int main() {
    float real, dolar;

    printf("Valor em real: \n");
    scanf("%f", &real);

    dolar = real*5.16;

    printf("R$%.2f em dolar: $%.2f\n", real, dolar);

    system("pause");
    return 0;
}