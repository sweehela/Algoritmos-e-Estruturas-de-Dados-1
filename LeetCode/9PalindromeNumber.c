/* Given an integer x, return true if x is a palindrome, and false otherwise.*/
#include <stdbool.h>

bool isPalindrome(int x) {
    // números negativos nunca serão válidos
    if (x<0) {
        return false;
    }

    int original = x;
    long long reversed = 0;

    while (x>0) {
        int digit = x%10; // pega o último dígito
        reversed = reversed*10+digit; // remove o último dígito
        x = x/10;
    }
    return original == reversed;
}