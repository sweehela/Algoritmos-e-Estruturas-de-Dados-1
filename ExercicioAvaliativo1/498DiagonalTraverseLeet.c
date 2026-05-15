int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize;
    int n = matColSize[0];

    int* result = (int*) malloc(m * n * sizeof(int));
    int index = 0;

    for(int d = 0; d < m + n - 1; d++) {
        int lin, col;

        if(d % 2 == 0) {
            // sobe
            lin = d < m ? d : m - 1;
            col = d - lin;

            while(lin >= 0 && col < n) {
                result[index++] = mat[lin][col];
                lin--;
                col++;
            }
        } else {
            // desce
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