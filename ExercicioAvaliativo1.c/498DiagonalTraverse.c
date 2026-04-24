// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize;
    int n = matColSize[0];

    int* result = (int*) malloc(m * n * sizeof(int));
    int index = 0;

    for(int d = 0; d < m + n - 1; d++) {
        int lin, col;

        if(d % 2 == 0) { //se d for par
            //sobe
            lin = d < m ? d : m - 1;
            col = d - lin;

            while(lin >= 0 && col < n) {
                result[index++] = mat[lin][col];
                lin--;
                col++;
            }
        } else { //se d for impar
            //desce
            col = d < n ? d : n - 1;
            lin = d - col;

            while(col >= 0 && lin < m) {
                result[index++] = mat[lin][col];
                lin++;
                col--;
            }
        }
    }
    *returnSize = m * n;
    return result;
}

//main
int main() {
    int m, n;
    printf("Digite o numero de linhas: ");
    scanf("%d", &m);

    printf("Digite o numero de colunas: ");
    scanf("%d", &n);

    int** mat = (int**) malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++) {
        mat[i] = (int*) malloc(n * sizeof(int));
    }

    printf("Digite os elementos da matriz: \n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j< n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int returnSize;
    int * matColSize = (int*) malloc(sizeof(int));
    matColSize[0] = n;

    int* result = findDiagonalOrder(mat, m, matColSize, &returnSize);

    printf("----------------------------------\n");
    printf("Resultado: [");
    for(int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if(i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(result);
    free(matColSize);
    for(int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);

    system("pause");
    return 0;
}