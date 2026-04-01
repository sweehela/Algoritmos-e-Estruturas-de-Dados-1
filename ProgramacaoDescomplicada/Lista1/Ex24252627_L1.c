/*24. Leia um valor de area em metros quadrados e apresente-o convertido em acres. A formula de conversão é: A = M ∗ 0,000247.
25. Leia um valor de area em acres e apresente-o convertido em metros quadrados. A formula de conversão é: M = A ∗ 4048,58.
26. Leia um valor de area em metros quadrados e apresente-o convertido em hectares. A formula de conversão é: H = M ∗ 0,0001.
27. Leia um valor de area em hectares e apresente-o convertido em metros quadrados. A formula de conversão é: M = H ∗ 10000.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int op;
    float m2, a, h;

    printf("Digite a conversao que deseja executar: \n");
    printf("1. Metros quadrados -> Acres\n");
    printf("2. Acres -> Metros Quadrados\n");
    printf("3. Metros quadrados -> Hectares\n");
    printf("4. Hectares -> Metros quadrados\n");
    scanf("%d", &op);

    if (op==1) {
        printf("\nDigite a area em metros quadrados: \n");
        scanf("%f", &m2);
        a = m2*0.000247;
        printf("A area %.2f em acres e: %.2f\n", m2, a);
    }
    else if(op==2) {
        printf("\nDigite a area em acres: \n");
        scanf("%f", &a);
        m2 = a*4048.58;
        printf("A area %.2f em metros quadrados e: %.2f\n", a, m2);
    }
    else if(op==3) {
        printf("\nDigite a area em metros quadrados: \n");
        scanf("%f", &m2);
        h = m2*0.0001;
        printf("A area %.2f em hectares e: %.2f\n", m2, h);
    }
    else if (op==4) {
        printf("\nDigite a area em hectares: \n");
        scanf("%f", &h);
        m2 = h*10000;
        printf("A area %.2f em metros quadrados e: %.2f\n", h, m2);
    }
    else {
        printf("Opcao invalida.\n");
        return 0;
    }
    system("pause");
    return 0;
}
