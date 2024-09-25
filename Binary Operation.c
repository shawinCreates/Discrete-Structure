#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    int start = 0, end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to perform binary addition
char* binaryAddition(const char* binary1, const char* binary2) {
    int len1 = strlen(binary1);
    int len2 = strlen(binary2);
    int carry = 0;
    int maxSize = (len1 > len2) ? len1 : len2;
    char* result = (char*)malloc(sizeof(char) * (maxSize + 2)); // +1 for potential carry, +1 for null terminator
    int i = 0;

    while (len1 > 0 || len2 > 0) {
        int bit1 = (len1 > 0) ? (binary1[len1 - 1] - '0') : 0;
        int bit2 = (len2 > 0) ? (binary2[len2 - 1] - '0') : 0;

        int sum = bit1 + bit2 + carry;
        result[i++] = (sum % 2) + '0';
        carry = sum / 2;

        if (len1 > 0) len1--;
        if (len2 > 0) len2--;
    }

    if (carry > 0) {
        result[i++] = carry + '0';
    }

    result[i] = '\0';
    reverseString(result); // Reverse the result before returning
    return result;
}

// Function to perform binary multiplication (basic logic, not using bitwise operations)
char* binaryMultiplication(const char* binary1, const char* binary2) {
    int num1 = strtol(binary1, NULL, 2);
    int num2 = strtol(binary2, NULL, 2);
    int result = num1 * num2;

    char* resultBinary = (char*)malloc(sizeof(char) * 33); // Assuming 32-bit integer
    itoa(result, resultBinary, 2);
    return resultBinary;
}

// Function to perform binary division (basic logic, not using bitwise operations)
char* binaryDivision(const char* binary1, const char* binary2) {
    int num1 = strtol(binary1, NULL, 2);
    int num2 = strtol(binary2, NULL, 2);
    int result = num1 / num2;

    char* resultBinary = (char*)malloc(sizeof(char) * 33); // Assuming 32-bit integer
    itoa(result, resultBinary, 2);
    return resultBinary;
}

int main() {
    char binary1[64], binary2[64];

    printf("Enter the first binary number: ");
    scanf("%s", binary1);

    printf("Enter the second binary number: ");
    scanf("%s", binary2);

    printf("\nBinary Addition: %s + %s = %s\n", binary1, binary2, binaryAddition(binary1, binary2));

    printf("\nBinary Multiplication: %s * %s = %s\n", binary1, binary2, binaryMultiplication(binary1, binary2));

    printf("\nBinary Division: %s / %s = %s\n", binary1, binary2, binaryDivision(binary1, binary2));

    return 0;
}

