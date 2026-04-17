/* At a lemonade stand, each lemonade costs $5, Customers are standing in a queue to buy from you and order at a time (in the order 
specified by bills). Each customer will only buy one lemonade and pay with either a 5$, 10$ or 20$ bill. You must provide the correct 
change to each customer so thatthe next transaction is that the customer pays 5$.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the i^th customer pays, return true if you can provide every customer woth the
correct change, or false otherwise*/

//verificar se é possível dar o troco pra todos os clientes
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool LemonadeChange (int contas[], int tamanho) {
    //quantidade de notas disponíveis
    int cinco = 0;
    int dez = 0;

    //percorrer todos os clientes 
    for (int i = 0; i < tamanho; i++) {
        if (contas[i] == 5) { //se pagar com 5$
            cinco++; //não precisa de troco

        } else if (contas [i] == 10) { //se pagar com 10$ 
            if (cinco > 0) { //precisa de troco de $5
                cinco--;
                dez++;
            } else {
                return false;
            }

        } else if (contas[i] == 20) { //se pagar com 20$
            if (dez > 0 && cinco > 0) { //precisa de troco de $10 e $5
                dez--; 
                cinco--;
            } else if (cinco>=3) { //precisa de troco de 3 notas de $5
                cinco -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

//main
int main(void) {

    //exemplo 1
    int contas1[] = {5, 5, 5, 10, 20};
    int tamanho1 = sizeof(contas1)/sizeof(contas1[0]);

    //exemplo 2
    int contas2[] = {5, 5, 10, 10, 20};
    int tamanho2 = sizeof(contas2)/sizeof(contas2[0]);

    //teste 1
    if (LemonadeChange(contas1, tamanho1)) {
        printf("Exemplo 1: true\n");
    } else {
        printf("Exemplo 1: false\n");
    }

    //teste 2
    if (LemonadeChange(contas2, tamanho2)) {
        printf("Exemplo 2: true\n");
    } else {
        printf("----------------------------------\n");
        printf("Exemplo 2: false\n");
    }
    system("pause");
    return 0;
}