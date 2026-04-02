//33. Leia o tamanho do lado de um quadrado e imprima como resultado a sua área.
#include <stdio.h>
#include <stdlib.h>

int main() {
    float l, a;

    printf("Digite o tamanho do lado do quadrado: \n");
    scanf("%f", &l);

    a = l*l;

    printf("A area do quadrado e: %.2f\n", a);
    
    system("pause");
    return 0;
}