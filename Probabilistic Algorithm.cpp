#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

long long modularExp(long long base, unsigned long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool isProbablePrime(unsigned long long n, int k) {
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    unsigned long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++) {
        unsigned long long base = 2 + rand() % (n - 4);

        unsigned long long x = modularExp(base, d, n);
        if (x == 1 || x == n - 1)
            continue;

        bool isComposite = true;
        while (d != n - 1) {
            x = (x * x) % n;
            d *= 2;

            if (x == 1)
                return false;
            if (x == n - 1) {
                isComposite = false;
                break;
            }
        }

        if (isComposite)
            return false;
    }

    return true;
}

int main() {
    srand(time(NULL));

    unsigned long long numToCheck;
    int rounds;

    printf("Enter a number to check for primality: ");
    scanf("%llu", &numToCheck);

    printf("Enter the number of rounds for the Miller-Rabin test: ");
    scanf("%d", &rounds);

    if (isProbablePrime(numToCheck, rounds))
        printf("%llu is probably a prime number.\n", numToCheck);
    else
        printf("%llu is composite.\n", numToCheck);

    return 0;
}

