/*44. Receba a altura do degrau de uma escada e a altura que o usuario deseja alcançar subindo a escada. Calcule e mostre quantos degraus 
o usuario deverá subir para atingir seu objetivo.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int degrau, h, total;

    printf("Digite a altura do degrau da escada: \n");
    scanf("%d", &degrau);
    printf("Digite a altura total: \n");
    scanf("%d", &h);

    total = h/degrau;

    printf("A quantidade de degraus a serem subidos e de aproximadamente: %d\n", total);
    
    system("pause");
    return 0;
}