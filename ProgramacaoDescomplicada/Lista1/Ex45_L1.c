/*45. Faça um programa para converter uma letra maiuscula em letra minuscula*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char letra;

    printf("Digite uma letra minuscula: \n");
    scanf(" %c", &letra);

    //verificar se a letra é minuscula
    if (letra >= 'a' && letra <= 'z') {
        letra = letra - 32; //converte para maiuscula

        printf("Letra maiuscula: %c\n", letra);
    } else {
        printf("Nao e uma letra minuscula valida\n");
    }
    system("pause");
    return 0;
}