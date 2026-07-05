#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct avlNode_t {
	int						val;
	int						height;
	int						size;
	struct avlNode_t *		left;
	struct avlNode_t *		right;
} avlNode_t;

static int Max( int a, int b ) {
	return ( a > b ) ? a : b;
}

static int Height( const avlNode_t *node ) {
	return node ? node->height : 0;
}

static int Size( const avlNode_t *node ) {
	return node ? node->size : 0;
}

static void UpdateNode( avlNode_t *node ) {
	int leftHeight;
	int rightHeight;

	if ( !node ) {
		return;
	}

	leftHeight = Height( node->left );
	rightHeight = Height( node->right );

	node->height = 1 + Max( leftHeight, rightHeight );
	node->size = 1 + Size( node->left ) + Size( node->right );
}

static int Balance( const avlNode_t *node ) {
	return node ? Height( node->left ) - Height( node->right ) : 0;
}

static avlNode_t *CreateNode( int value ) {
	avlNode_t *node;

	node = ( avlNode_t * ) malloc( sizeof( avlNode_t ) );
	node->val = value;
	node->height = 1;
	node->size = 1;
	node->left = NULL;
	node->right = NULL;

	return node;
}

static avlNode_t *RotateRight( avlNode_t *nodeY ) {
	avlNode_t *nodeX;
	avlNode_t *temp;

	nodeX = nodeY->left;
	temp = nodeX->right;

	nodeX->right = nodeY;
	nodeY->left = temp;

	UpdateNode( nodeY );
	UpdateNode( nodeX );

	return nodeX;
}

static avlNode_t *RotateLeft( avlNode_t *nodeX ) {
	avlNode_t *nodeY;
	avlNode_t *temp;

	nodeY = nodeX->right;
	temp = nodeY->left;

	nodeY->left = nodeX;
	nodeX->right = temp;

	UpdateNode( nodeX );
	UpdateNode( nodeY );

	return nodeY;
}

static avlNode_t *Rebalance( avlNode_t *node ) {
	int balanceFactor;

	if ( !node ) {
		return node;
	}

	UpdateNode( node );
	balanceFactor = Balance( node );

	if ( balanceFactor > 1 ) {
		if ( Balance( node->left ) < 0 ) {
			node->left = RotateLeft( node->left );
		}
		return RotateRight( node );
	}

	if ( balanceFactor < -1 ) {
		if ( Balance( node->right ) > 0 ) {
			node->right = RotateRight( node->right );
		}
		return RotateLeft( node );
	}

	return node;
}

static avlNode_t *InsertAVL( avlNode_t *root, int value, long long *greaterCount ) {
	if ( !root ) {
		return CreateNode( value );
	}

	if ( value < root->val ) {
		*greaterCount += 1 + Size( root->right );
		root->left = InsertAVL( root->left, value, greaterCount );
	} else {
		root->right = InsertAVL( root->right, value, greaterCount );
	}

	return Rebalance( root );
}

static void FreeAVL( avlNode_t *node ) {
	if ( !node ) {
		return;
	}

	FreeAVL( node->left );
	FreeAVL( node->right );
	free( node );
}

bool isIdealPermutation( int *nums, int numsSize ) {
	long long	local;
	long long	global;
	avlNode_t *	root;

	local = 0;
	global = 0;
	root = NULL;

	// locais
	for ( int i = 0; i < numsSize - 1; i++ ) {
		if ( nums[i] > nums[i + 1] ) {
			local++;
		}
	}

	// globais
	for ( int i = 0; i < numsSize; i++ ) {
		long long greaterCount;

		greaterCount = 0;
		root = InsertAVL( root, nums[i], &greaterCount );
		global += greaterCount;
	}

	FreeAVL( root );

	return global == local;
}

static void ImprimirArray( int *array, int arraySize ) {
	int i;

	printf( "[" );
	for ( i = 0; i < arraySize; i++ ) {
		printf( "%d", array[i] );
		if ( i < arraySize - 1 ) {
			printf( ", " );
		}
	}
	printf( "]" );
}

static int RodarTeste( int id, int *nums, int numsSize, bool esperado ) {
	bool obtido;

	obtido = isIdealPermutation( nums, numsSize );

	printf( "Teste %d: ", id );
	ImprimirArray( nums, numsSize );
	printf( " -> esperado = %s | obtido = %s | %s\n",
		esperado ? "true" : "false",
		obtido ? "true" : "false",
		( esperado == obtido ) ? "OK" : "ERRO" );

	return ( esperado == obtido ) ? 1 : 0;
}

/*
int main( void ) {
	int passou;

	int t1[]  = { 1, 0, 2 };
	int t2[]  = { 1, 2, 0 };
	int t3[]  = { 0 };
	int t4[]  = { 0, 1, 2, 3, 4 };
	int t5[]  = { 1, 0, 3, 2, 4 };
	int t6[]  = { 2, 0, 1 };
	int t7[]  = { 4, 3, 2, 1, 0 };
	int t8[]  = { 0, 2, 1 };
	int t9[]  = { 1, 0, 2, 4, 3 };
	int t10[] = { 3, 0, 1, 2 };

	passou = 0;

	passou += RodarTeste( 1, t1, 3, true );
	passou += RodarTeste( 2, t2, 3, false );
	passou += RodarTeste( 3, t3, 1, true );
	passou += RodarTeste( 4, t4, 5, true );
	passou += RodarTeste( 5, t5, 5, true );
	passou += RodarTeste( 6, t6, 3, false );
	passou += RodarTeste( 7, t7, 5, false );
	passou += RodarTeste( 8, t8, 3, true );
	passou += RodarTeste( 9, t9, 5, true );
	passou += RodarTeste( 10, t10, 4, false );

	printf( "\nResultado final: %d/10 testes passaram.\n", passou );

	return 0;
}
*/