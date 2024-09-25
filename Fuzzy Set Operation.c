#include <stdio.h>

void displayFuzzySet(float set[], int size) {
    printf("{ ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%.2f ", set[i]);
    }
    printf("}\n");
}

void fuzzyUnion(float set1[], float set2[], int size) {
    float result[size];
    printf("Fuzzy Set 1: ");
    displayFuzzySet(set1, size);
    printf("Fuzzy Set 2: ");
    displayFuzzySet(set2, size);
    printf("Fuzzy Union of sets: ");
    int i;
    for (i = 0; i < size; i++) {
        result[i] = (set1[i] > set2[i]) ? set1[i] : set2[i];
        printf("%.2f ", result[i]);
    }
}

void fuzzyIntersection(float set1[], float set2[], int size) {
    float result[size];
    printf("\nFuzzy Intersection of sets: ");
    int i;
    for (i = 0; i < size; i++) {
        result[i] = (set1[i] < set2[i]) ? set1[i] : set2[i];
        printf("%.2f ", result[i]);
    }
}

void fuzzyComplement(float set[], int size) {
    float result[size];
    printf("\nFuzzy Complement of set: ");
    int i;
    for (i = 0; i < size; i++) {
        result[i] = 1 - set[i];
        printf("%.2f ", result[i]);
    }
}

void fuzzyDifference(float set1[], float set2[], int size) {
    float result[size];
    printf("\nFuzzy Difference of sets: ");
    int i;
    for (i = 0; i < size; i++) {
        result[i] = (set1[i] < (1 - set2[i])) ? set1[i] : (1 - set2[i]);
        printf("%.2f ", result[i]);
    }
}

void readFuzzySet(float set[], int size) {
    printf("Enter values for Fuzzy Set (separated by space): ");
    int i;
    for (i = 0; i < size; i++) {
        scanf("%f", &set[i]);
    }
}

int main() {
    float set1[4], set2[4];
    int size = sizeof(set1) / sizeof(set1[0]);

    printf("Enter values for first Fuzzy Set:\n");
    readFuzzySet(set1, size);

    printf("Enter values for second Fuzzy Set:\n");
    readFuzzySet(set2, size);

    fuzzyUnion(set1, set2, size);
    fuzzyIntersection(set1, set2, size);
    fuzzyComplement(set1, size);
    fuzzyDifference(set1, set2, size);

    return 0;
}

