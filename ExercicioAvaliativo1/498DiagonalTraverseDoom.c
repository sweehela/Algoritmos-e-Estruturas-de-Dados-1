#include <stdio.h>
#include <stdlib.h>

int * FindDiagonalOrder( int **mat, int matSize, int *matColSize, int *returnSize ) {

    int m = matSize;
    int n = matColSize[0];

    //armazenar a resposta no vetor
    int *result = ( int * ) malloc( m * n * sizeof( int ) );
    if ( result == NULL ) return NULL;

    int index = 0;

    //quantas diagonais
    for ( int d = 0; d < m + n - 1; d++ ) {

        int lin;
        int col;

        //subir
        if ( d % 2 == 0 ) {

            lin = ( d < m ) ? d : m - 1;
            col = d - lin;

            while ( lin >= 0 && col < n ) {
                result[index] = mat[lin][col];
                index++;
                lin--;
                col++;
            }

        } else {

            //descer
            col = ( d < n ) ? d : n - 1;
            lin = d - col;

            while ( col >= 0 && lin < m ) {
                result[index] = mat[lin][col];
                index++;
                lin++;
                col--;
            }
        }
    }
    *returnSize = m * n;
    return result;
}

//main

int main( void ) {

    int m;
    int n;

    printf( "Digite o numero de linhas: " );
    scanf( "%d", &m );

    printf( "Digite o numero de colunas: " );
    scanf( "%d", &n );

    int **mat = ( int ** ) malloc( m * sizeof( int * ) );
    if ( mat == NULL ) return 1;

    for ( int i = 0; i < m; i++ ) {
        mat[i] = ( int * ) malloc( n * sizeof( int ) );
        if ( mat[i] == NULL ) return 1;
    }

    printf( "Digite os elementos da matriz:\n" );

    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            scanf( "%d", &mat[i][j] );
        }
    }

    //matrizes retangulares
    int *matColSize = ( int * ) malloc( sizeof( int ) );
    if ( matColSize == NULL ) return 1;

    matColSize[0] = n;

    int returnSize;

    int *result = FindDiagonalOrder( mat, m, matColSize, &returnSize );

    // impressão do resultado
    printf( "----------------------------------\n" );
    printf( "Resultado: [" );

    for ( int i = 0; i < returnSize; i++ ) {

        printf( "%d", result[i] );

        if ( i < returnSize - 1 ) {
            printf( ", " );
        }
    }

    printf( "]\n" );

    //memoria free
    free( result );
    free( matColSize );

    for ( int i = 0; i < m; i++ ) {
        free( mat[i] );
    }

    free( mat );

    system( "pause" );

    return 0;
}