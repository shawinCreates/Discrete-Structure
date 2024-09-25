#include <stdio.h>

int main() {
    int n, r;

    // User input
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of r: ");
    scanf("%d", &r);

    // Calculate and display permutations (nPr)
    int nPr = 1;
    for (int i = n; i > n - r; i--) {
        nPr *= i;
    }

    // Calculate and display combinations (nCr)
    int nCr = 1;
    for (int i = 1; i <= r; i++) {
        nCr *= n - (r - i);
        nCr /= i;
    }

    printf("Permutations (nPr) when n=%d and r=%d is %d\n", n, r, nPr);
    printf("Combinations (nCr) when n=%d and r=%d is %d\n", n, r, nCr);

    return 0;
}

