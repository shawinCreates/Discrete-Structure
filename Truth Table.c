#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to perform logical OR
int OR(int p, int q) {
    if ((p == 0) && (q == 0)) {
        return 0;
    } else {
        return 1;
    }
}

// Function to perform logical AND
int AND(int p, int q) {
    if ((p == 1) && (q == 1)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to perform logical NOT
int NOT(int p) {
    if (p == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to perform conditional (if-then)
int conditional(int p, int q) {
    if ((p == 1) && (q == 0)) {
        return 0;
    } else {
        return 1;
    }
}

// Function to perform biconditional (if and only if)
int biconditional(int p, int q) {
    if (p == q) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int p, q;

    printf("|p\t |q\t |p v q\t |p ^ q\t |-p\t |p -> q |p <--> q|\n");
    printf("----------------------------------------------------------\n");
    for (p = 0; p <= 1; p++) {
        for (q = 0; q <= 1; q++) {
            printf("|%d\t |%d\t |%d\t |%d\t |%d\t |%d\t |%d\t|\n", p, q, OR(p, q), AND(p, q), NOT(p), conditional(p, q), biconditional(p, q));
        }
    }
	printf("----------------------------------------------------------\n");
	
    return 0;
}

