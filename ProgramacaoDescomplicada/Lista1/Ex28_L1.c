//28. Faça a leitura de três valores e apresente como resultado a soma dos quadrados dos três valores lidos.
#include <stdio.h>
#include <stdlib.h>

int main() {
    float a, b, c, d;

    printf("Escreva os tres valores: \n");
    scanf("%f %f %f", &a, &b, &c);

    d = (a*a)+(b*b)+(c*c);

    printf("Resultado: %.2f\n", d);

    system("pause");
    return 0;
}