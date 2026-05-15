#include <stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int* stack = (int*)malloc(sizeof(int) * numsSize);

    int top = -1;

    // inicializa o resultado com -1
    for (int i=0; i<numsSize; i++) {
        result[i] = -1;
    }

    // percorre o circulo
    for (int i=0; i<2 * numsSize; i++) {
        int index = i % numsSize;
    
        // enquanto o elemento atual é maior que o do PUSH pilha
        while (top>=0 && nums[index]>nums[stack[top]]) {
            result[stack[top]] = nums[index];
            top--;
        }
        if (i<numsSize) {
            stack[++top] = index;
        }
    }
    free(stack);
    *returnSize = numsSize;
    return result;
}