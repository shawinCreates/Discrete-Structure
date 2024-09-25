#include <stdio.h>

int power_mod(int base, int exponent, int mod);

int main() {
    int base, exponent, mod;

    // Ask the user to enter base, exponent, and mod
    printf("Enter the base number: ");
    scanf("%d", &base);

    printf("Enter the exponent number: ");
    scanf("%d", &exponent);

    printf("Enter the mod number: ");
    scanf("%d", &mod);

    // Calculate and display the result
    int result = power_mod(base, exponent, mod);
    printf("%d^%d mod %d = %d\n", base, exponent, mod, result);

    return 0;
}

int power_mod(int base, int exponent, int mod) {
    // Base case: when exponent is 0, any number to the power of 0 is 1
    if (exponent == 0) {
        return 1;
    } else {
        // Recursive case: b^n mod m = (b^(n/2) mod m * b^(n/2) mod m) mod m
        int temp = power_mod(base, exponent / 2, mod);
        int result = (temp * temp) % mod;

        // If exponent is odd, multiply by base once more
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        return result;
    }
}

