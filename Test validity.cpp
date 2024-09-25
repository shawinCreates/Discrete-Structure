#include <stdio.h>
#include <stdbool.h>

// Function to print truth table for given number of variables and logical expressions
void printTruthTable(int n) {
    int numCombinations = 1 << n; // Number of possible combinations for n variables
    
    // Print the header with variable names and logical expressions for premises and conclusion
    printf("P  Q  R | P ^ Q | P -> R |  R  \n");
    printf("---------+-------+--------+-----\n");

    // Iterate through all combinations of truth values
    for (int i = 0; i < numCombinations; i++) {
        int val = i;
        for (int j = 0; j < n; j++) {
            printf("%d  ", val >> j & 1);
        }

        // Evaluate the premises and conclusion for the current combination of truth values
        bool p = (i & 1) != 0;
        bool q = (i & 2) != 0;
        bool r = (i & 4) != 0;

        bool premise1 = p && q;
        bool premise2 = !p || r;
        bool conclusion = r;

        printf("|   %d   |   %d    |  %d  \n", premise1, premise2, conclusion);
    }
}

int main() {
    int numVariables = 3; // Number of variables (p, q, r)

    printf("Truth Table:\n");
    printf("Premise 1: p ^ q\n");
    printf("Premise 2: p -> r\n");
    printf("Conclusion: r\n");
    printTruthTable(numVariables);

    return 0;
}

