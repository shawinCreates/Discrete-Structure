#include <stdio.h>

int linearSearch(int arr[], int key, int size, int index);

int main() {
    int size, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = linearSearch(arr, key, size, 0);

    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}

int linearSearch(int arr[], int key, int size, int index) {
    if (index >= size) {
        return -1; // Element not found
    }

    if (arr[index] == key) {
        return index; // Element found at the current index
    } else {
        return linearSearch(arr, key, size, index + 1); // Continue searching in the rest of the array
    }
    return 0;
}

