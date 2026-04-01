/*10. Leia uma velocidade em km/h e apresente-a convertida em m/s . A fórmula de conversão é: M = K/3.6, sendo K a velocidade em
km/h e M em m/s.
11. Leia uma velocidade em m/s e apresente-a convertida em km/h. A fórmula de conversão é: K = M*3.6, sendo K a velocidade
em km/h e M em m/s.
12. Leia uma distancia em milhas e apresente-a convertida em quilômetros. A fóormula de conversão é: K = 1, 61*M, sendo K a distância em quilômetros e M em milhas.
13. Leia uma distancia em quilômetros e apresente-a convertida em milhas. A fórmula de conversão é: M = K*1,61 , sendo K a distancia em quilômetros e M em milhas. */
#include <stdio.h>
#include <stdlib.h>

int main () {
    int op;
    float vk, vm, dk, dm;

    printf("Digite a conversao que deseja executar: \n");
    printf("1. Velocidade em km/h -> Velocidade em m/s\n");
    printf("2. Velocidade em m/s -> Velocidade em km/h\n");
    printf("3. Distancia em milhas -> Distancia em quilometros\n");
    printf("4. Distancia em quilometros -> Distancia em milhas\n");
    scanf("%d", &op);

    if (op==1) {
        printf("\nDigite a velocidade em km/h: \n");
        scanf("%f", &vk);
        vm = vk/3.6;
        printf("A velocidade %.1fkm/h em m/s e: %.1fm/s.\n", vk, vm);
    }
    else if(op==2) {
        printf("\nDigite a velocidade em m/s: \n");
        scanf("%f", &vm);
        vk = vm*3.6;
        printf("A velocidade %.1fm/s em km/h e: %.1fkm/h.\n", vm, vk);
    }
    else if(op==3) {
        printf("\nDigite a distancia em milhas: \n");
        scanf("%f", &dm);
        dk = 1.61*dm;
        printf("\nA distancia %.1f milhas em quilometros e: %.1f quilometros.\n", dm, dk);
    }
    else if (op==4) {
        printf("\nDigite a distancia em quilometros: \n");
        scanf("%f", &dk);
        dm = dk*1.61;
        printf("A distancia %.1f quilometros em milhas e: %.1f milhas.", dk, dm);
    }
    else {
        printf("Opcao invalida.\n");
        return 0;
    }
    system("pause");
    return 0;
}