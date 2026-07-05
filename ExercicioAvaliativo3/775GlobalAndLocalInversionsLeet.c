/* 
LeetCode 775 - Inversoes Globais e Locais (Global and Local Inversions)
Versao usando AVL para estudar arvore balanceada.

Ideia:
- Inversoes locais: contar pares adjacentes nums[i] > nums[i+1]
- Inversoes globais: ao inserir nums[i] na AVL, contar quantos elementos
  ja inseridos sao maiores que nums[i].
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AVLNode {
    int val;
    int height;
    int size;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int height(const AVLNode *n) {
    return n ? n->height : 0;
}

static int size(const AVLNode *n) {
    return n ? n->size : 0;
}

static void updateNode(AVLNode *n) {
    int he, hd;
    if (!n) return;
    he = height(n->left);
    hd = height(n->right);
    n->height = 1 + max(he, hd);
    n->size = 1 + size(n->left) + size(n->right);
}

static int balance(const AVLNode *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

static AVLNode *createNode(int v) {
    AVLNode *n = (AVLNode *)malloc(sizeof(AVLNode));
    n->val = v;
    n->height = 1;
    n->size = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

static AVLNode *rotateRight(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    updateNode(y);
    updateNode(x);
    return x;
}

static AVLNode *rotateLeft(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    updateNode(x);
    updateNode(y);
    return y;
}

static AVLNode *rebalance(AVLNode *n) {
    int b;
    if (!n) return n;
    updateNode(n);
    b = balance(n);

    if (b > 1) {
        if (balance(n->left) < 0) {
            n->left = rotateLeft(n->left);
        }
        return rotateRight(n);
    }

    if (b < -1) {
        if (balance(n->right) > 0) {
            n->right = rotateRight(n->right);
        }
        return rotateLeft(n);
    }
    return n;
}

static AVLNode *insertAVL(AVLNode *r, int v, long long *greaterCount) {
    if (!r) {
        return createNode(v);
    }
    if (v < r->val) {
        *greaterCount += 1 + size(r->right);
        r->left = insertAVL(r->left, v, greaterCount);
    } else {
        r->right = insertAVL(r->right, v, greaterCount);
    }
    return rebalance(r);
}

static void freeAVL(AVLNode *n) {
    if (!n) return;
    freeAVL(n->left);
    freeAVL(n->right);
    free(n);
}

bool isIdealPermutation(int *nums, int numsSize) {
    long long local = 0;
    long long global = 0;
    AVLNode *root = NULL;

    // locais
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            local++;
        }
    }

    // globais
    for (int i = 0; i < numsSize; i++) {
        long long greaterCount = 0;
        root = insertAVL(root, nums[i], &greaterCount);
        global += greaterCount;
    }

    freeAVL(root);

    return global == local;
}

static void imprimirArray(int *v, int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

static int RodarTeste(int id, int *nums, int n, bool esperado) {
    bool obtido = isIdealPermutation(nums, n);

    printf("Teste %d: ", id);
    imprimirArray(nums, n);
    printf(" -> esperado = %s | obtido = %s | %s\n",
           esperado ? "true" : "false",
           obtido ? "true" : "false",
           (esperado == obtido) ? "OK" : "ERRO");

    return (esperado == obtido) ? 1 : 0;
}

/*
int main(void) {
    int passou;

    int t1[]  = {1, 0, 2};          // exemplo 1 do enunciado
    int t2[]  = {1, 2, 0};          // exemplo 2 do enunciado
    int t3[]  = {0};                // elemento unico
    int t4[]  = {0, 1, 2, 3, 4};    // identidade: zero inversoes
    int t5[]  = {1, 0, 3, 2, 4};    // trocas adjacentes disjuntas
    int t6[]  = {2, 0, 1};          // valor a 2 posicoes do lugar
    int t7[]  = {4, 3, 2, 1, 0};    // permutacao reversa
    int t8[]  = {0, 2, 1};          // uma troca adjacente no fim
    int t9[]  = {1, 0, 2, 4, 3};    // trocas nas duas pontas
    int t10[] = {3, 0, 1, 2};       // 3 globais, 1 local

    passou = 0;

    passou += RodarTeste(1,  t1,  3, true);
    passou += RodarTeste(2,  t2,  3, false);
    passou += RodarTeste(3,  t3,  1, true);
    passou += RodarTeste(4,  t4,  5, true);
    passou += RodarTeste(5,  t5,  5, true);
    passou += RodarTeste(6,  t6,  3, false);
    passou += RodarTeste(7,  t7,  5, false);
    passou += RodarTeste(8,  t8,  3, true);
    passou += RodarTeste(9,  t9,  5, true);
    passou += RodarTeste(10, t10, 4, false);

    printf("\nResultado final: %d/10 testes passaram.\n", passou);

    return 0;
}
*/