#include <stdio.h>
#include <stdlib.h>


int * NextGreaterElements( int *nums, int numsSize, int *returnSize ) {
	int *result;
	int *stack;
	int top;

	result = ( int * ) malloc( sizeof( int ) * numsSize );
	stack = ( int * ) malloc( sizeof( int ) * numsSize );

	top = -1;

	// inicializa o resultado com -1
	for ( int i = 0; i < numsSize; i++ ) {
		result[ i ] = -1;
	}

	// percorre o círculo
	for ( int i = 0; i < 2 * numsSize; i++ ) {
		int index;

		index = i % numsSize;

		// enquanto o elemento atual é maior que o topo da pilha
		while ( top >= 0 && nums[ index ] > nums[ stack[ top ] ] ) {
			result[ stack[ top ] ] = nums[ index ];
			top--;
		}

		if ( i < numsSize ) {
			stack[ ++top ] = index;
		}
	}

	free( stack );

	*returnSize = numsSize;

	return result;
}

//main

int main( void ) {
	int nums[] = { 1, 2, 1 };
	int numsSize;
	int returnSize;
	int *result;

	numsSize = sizeof( nums ) / sizeof( nums[ 0 ] );

	result = NextGreaterElements( nums, numsSize, &returnSize );

	printf( "Resultado: [" );

	for ( int i = 0; i < returnSize; i++ ) {
		printf( "%d", result[ i ] );

		if ( i < returnSize - 1 ) {
			printf( ", " );
		}
	}

	printf( "]\n" );

	free( result );

    system("pause");
	return 0;
}