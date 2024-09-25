#include <stdio.h>

// Function to find the Greatest Common Divisor (GCD) using Euclidean Algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the GCD using Extended Euclidean Algorithm and calculate coefficients
int extendedGCD(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcdVal = extendedGCD(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcdVal;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\nGCD of %d and %d using Euclidean Algorithm is: %d\n\n", a, b, gcd(a, b));

    int x, y;
    int gcdVal = extendedGCD(a, b, &x, &y);
    printf("GCD of %d and %d using Extended Euclidean Algorithm is: %d\n\n", a, b, gcdVal);
    printf("Coefficients x and y: %d and %d\n", x, y);

    return 0;
}

