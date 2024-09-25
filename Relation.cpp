#include <stdio.h>

#define MAX_SIZE 100

int isInRelation(int a, int b, int relation[][2], int size) {
    for (int i = 0; i < size; i++) {
        if (relation[i][0] == a && relation[i][1] == b) {
            return 1;
        }
    }
    return 0;
}

int isReflexive(int set[], int setSize, int relation[][2], int relSize) {
    for (int i = 0; i < setSize; i++) {
        if (!isInRelation(set[i], set[i], relation, relSize)) {
            return 0;
        }
    }
    return 1;
}

int isSymmetric(int relation[][2], int relSize) {
    for (int i = 0; i < relSize; i++) {
        int a = relation[i][0];
        int b = relation[i][1];
        if (!isInRelation(b, a, relation, relSize)) {
            return 0;
        }
    }
    return 1;
}

int isTransitive(int relation[][2], int relSize) {
    for (int i = 0; i < relSize; i++) {
        int a = relation[i][0];
        int b = relation[i][1];
        for (int j = 0; j < relSize; j++) {
            int c = relation[j][0];
            int d = relation[j][1];
            if (b == c && !isInRelation(a, d, relation, relSize)) {
                return 0;
            }
        }
    }
    return 1;
}

int isEquivalence(int set[], int setSize, int relation[][2], int relSize) {
    return isReflexive(set, setSize, relation, relSize) &&
           isSymmetric(relation, relSize) &&
           isTransitive(relation, relSize);
}

int main() {
    int setA[] = {1, 2, 3};
    int sizeA = sizeof(setA) / sizeof(setA[0]);

    int setB[] = {4, 5};
    int sizeB = sizeof(setB) / sizeof(setB[0]);

    int relation[][2] = {{1, 1}, {2, 2}, {3, 3}, {1, 1}, {2, 2}, {3, 3}, {1, 3}, {3, 1}}; // An equivalence relation
    int relSize = sizeof(relation) / sizeof(relation[0]);

    printf("Relation R:\n");
    for (int i = 0; i < relSize; i++) {
        printf("(%d, %d) ", relation[i][0], relation[i][1]);
    }
    printf("\n\n");

	printf("Reflexive: %s\n", isReflexive ? "Yes" : "No");
    printf("Symmetric: %s\n", isSymmetric ? "Yes" : "No");
    printf("Transitive: %s\n", isTransitive ? "Yes" : "No");
    
    printf("Equivalence Relation: %s\n", isEquivalence(setA, sizeA, relation, relSize) ? "Yes" : "No");

    return 0;
}

