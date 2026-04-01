/*16. Leia um valor de comprimento em polegadas e apresente-o convertido em centímetros. A formula de conversão é: C = P ∗ 2,54.
17. Leia um valor de comprimento em centímetros e apresente-o convertido em polegadas. A formula de conversão é: P = C/2,54.
22. Leia um valor de comprimento em jardas e apresente-o convertido em metros. A formula de conversão é: M = 0,91 ∗ J.
23. Leia um valor de comprimento em metros e apresente-o convertido em jardas. A formula de conversão é: J = M/0,91.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int op;
    float p, cm, j, m;

    printf("Digite a conversao que deseja executar: \n");
    printf("1. Polegadas -> Centimetros\n");
    printf("2. Centimetros -> Polegadas\n");
    printf("3. Jardas -> Metros\n");
    printf("4. Metros -> Jardas\n");
    scanf("%d", &op);

    if (op==1) {
        printf("\nDigite o comprimento em polegadas: \n");
        scanf("%f", &p);
        cm = p*2.54;
        printf("A medida %.1f em centimetros e: %.1f\n", p, cm);
    }
    else if(op==2) {
        printf("\nDigite o comprimento em centimetros: \n");
        scanf("%f", &cm);
        p = cm/2.54;
        printf("A medida %.1f em polegadas e: %.1f\n", cm, p);
    }
    else if(op==3) {
        printf("\nDigite o comprimento em jardas: \n");
        scanf("%f", &j);
        m = 0.91*j;
        printf("\nA medida %.1f em metros e: %.1f\n", j, m);
    }
    else if (op==4) {
        printf("\nDigite o comprimento em metros: \n");
        scanf("%f", &m);
        j = m/0.91;
        printf("A medida %.1f em jardas e: %.1f\n", m, j);
    }
    else {
        printf("Opcao invalida.\n");
        return 0;
    }
    system("pause");
    return 0;
}
