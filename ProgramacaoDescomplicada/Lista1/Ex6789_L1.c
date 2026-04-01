/*6. Leia uma temperatura em graus Celsius e apresente-a convertida em graus Fahrenheit.
A formula de conversão é: F = C∗(9.0/5.0)+32.0, sendo F a temperatura em Fahrenheite C a temperatura em Celsius.
 7. Leia uma temperatura em graus Fahrenheit e apresente-a convertida em graus Celsius.
A formula de conversão é: C = 5.0 ∗ (F − 32.0)/9.0, sendo C a temperatura em Celsius e F a temperatura em Fahrenheit.
 8. Leia uma temperatura em graus Kelvin e apresente-a convertida em graus Celsius. A
formula de conversão é: C = K − 273.15, sendo C a temperatura em Celsius e K a temperatura em Kelvin.
 9. Leia uma temperatura em graus Celsius e apresente-a convertida em graus Kelvin. A
formula de conversão é: K = C + 273.15, sendo C a temperatura em Celsius e K a temperatura em Kelvin.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int op;
    float c, f, k, temperatura;

    printf("Digite a conversao que deseja executar: \n");
    printf("1. Celsius -> Fahrenheit\n");
    printf("2. Fahrenheit -> Celsius\n");
    printf("3. Kelvin -> Celsius\n");
    printf("4. Celsius -> Kelvin\n");
    scanf("%d", &op);

    if (op==1) {
        printf("Digite a temperatura em graus Celsius: \n");
        scanf("%f", &c);
        f = c*(9.0/5.0)+32.0;
        printf("A temperatura %.1f em graus Fahrenheit e: %.1f\n", c, f);
    }
    else if(op==2) {
        printf("Digite a temperatura em graus Fahrenheit: \n");
        scanf("%f", &f);
        c = 5.0*(f-32.0)/9.0;
        printf("A temperatura %.1f em graus Celsius e: %.1f\n", f, c);
    }
    else if(op==3) {
        printf("Digite a temperatura em graus Kelvin: \n");
        scanf("%f", &k);
        c = k-273.15;
        printf("A temperatura %.1f em graus Celsius e: %.1f\n", k, c);
    }
    else if (op==4) {
        printf("Digite a temperatura em graus Celsius: \n");
        scanf("%f", &c);
        k = c+273.15;
        printf("A temperatura %.1f em graus Kelvin e: %.1f\n", c, k);
    }
    else {
        printf("Opcao invalida.\n");
        return 0;
    }
    system("pause");
    return 0;
}