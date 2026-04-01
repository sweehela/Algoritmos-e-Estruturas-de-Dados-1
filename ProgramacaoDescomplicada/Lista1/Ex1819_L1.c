/*18. Leia um valor de volume em metros cúbicos m^3 e apresente-o convertido em litros. A formula de conversão é: L = 1000 ∗ M.
19. Leia um valor de volume em litros e apresente-o convertido em metros cúbicos m^3. A formula de conversão é: M = L/1000.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int op;
    float l, m3;

    printf("Digite a conversao que deseja executar: \n");
    printf("1. Metros cubicos -> Litros\n");
    printf("2. Litros -> Metros cubicos\n");
    scanf("%d", &op);

    if (op==1) {
        printf("\nDigite o volume em metros cubicos: \n");
        scanf("%f", &m3);
        l = 1000*m3;
        printf("O volume %.2f em litros e: %.2f\n", m3, l);
    }
    else if(op==2) {
        printf("\nDigite o volume em litros: \n");
        scanf("%f", &l);
        m3 = l/1000;
        printf("O volume %.2f em metros cubicos e: %.2f\n", l, m3);
    }
    else {
        printf("Opcao invalida.\n");
        return 0;
    }
    system("pause");
    return 0;
}
