/*A importância de R$ 780.000,00 será dividida entre três ganhadores de um concurso. Sendo que da quantia total:
• O primeiro ganhador recebera 46%;
• O segundo recebera 32%;
• O terceiro recebera o restante;
Calcule e imprima a quantia ganha por cada um dos ganhadores.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i=780;
    float p, s, t;

    p = i*0.46;
    s = i*0.32;
    t = i-(p+s);

    printf("---Resultado---\n");
    printf("Primeiro ganhador: R$%.3f\n", p);
    printf("Segundo ganhador: R$%.3f\n", s);
    printf("Terceiro ganhador: R$%.3f\n", t);

    system("pause");
    return 0;
}