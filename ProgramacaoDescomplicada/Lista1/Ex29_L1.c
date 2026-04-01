//28. Leia quatro notas, calcule a média aritmética e imprima o resultado.
#include <stdio.h>
#include <stdlib.h>

int main() {
    float nota, soma=0;

    for (int i=1; i<=4; i++) {
        printf("Digite a nota %d: \n", i);
        scanf("%f", &nota);

        while (nota<0||nota>10) {
            printf("Nota invalida. Digite novamente: ");
            scanf("%f", &nota);
        }
        soma+=nota;
    }

    printf("Media: %.2f\n", soma/4);

    system("pause");
    return 0;
}