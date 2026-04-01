/*14. Leia um ângulo em graus e apresente-o convertido em radianos. A fórmula de conversão é:  R = G ∗ π/180.
// 15. Leia um angulo em radianos e apresente-o convertido em graus. A fórmula de conversão é: G = R ∗ 180/π.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int op;
    float ag, ar, g, r;

    printf("Digite a conversao que deseja executar: \n");
    printf("1. Grau -> Radiano\n");
    printf("2. Radiano -> Grau\n");
    scanf("%d", &op);

    if (op==1) {
        printf("Digite o valor do angulo em graus: \n");
        scanf("%f", &ag);
        r = ag*(3.14/180);
        printf("O angulo %.2f em radianos e: %.2f\n", ag, r);
    }
    else if(op==2) {
        printf("Digite o valor do angulo em radianos: \n");
        scanf("%f", &ar);
        g = ar*(180/3.14);
        printf("o angulo %.2f em graus e: %.2f\n", ar, g);
    }
    else {
        printf("Opcao invalida.\n");
        system("pause");
        return 0;
    }
    system("pause");
    return 0;
}