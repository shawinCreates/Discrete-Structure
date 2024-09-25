#include <stdio.h>
#include <string.h>

#define MAX 1000

void add(char a[], char b[], char res[]) {
    int carry = 0, i, sum;
    int len1 = strlen(a);
    int len2 = strlen(b);

    int maxLen = len1 > len2 ? len1 : len2;

    for (i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? (a[len1 - 1 - i] - '0') : 0;
        int digit2 = (i < len2) ? (b[len2 - 1 - i] - '0') : 0;

        sum = carry + digit1 + digit2;
        res[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) {
        res[i++] = carry + '0';
    }
    res[i] = '\0';

    for (i = 0; i < strlen(res) / 2; i++) {
        char temp = res[i];
        res[i] = res[strlen(res) - 1 - i];
        res[strlen(res) - 1 - i] = temp;
    }
}

void multiply(char a[], char b[], char res[]) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int i, j, k = 0;
    int carry = 0;

    int *result = (int *)malloc(sizeof(int) * (len1 + len2));
    memset(result, 0, sizeof(int) * (len1 + len2));

    for (i = len1 - 1; i >= 0; i--) {
        int digit1 = a[i] - '0';
        carry = 0;
        k = len1 - 1 - i;

        for (j = len2 - 1; j >= 0; j--) {
            int digit2 = b[j] - '0';
            int sum = digit1 * digit2 + result[k] + carry;
            carry = sum / 10;
            result[k++] = sum % 10;
        }

        if (carry) {
            result[k++] = carry;
        }
    }

    k--;
    i = 0;

    while (k >= 0) {
        res[i++] = result[k--] + '0';
    }

    res[i] = '\0';
}

int main() {
    char num1[MAX], num2[MAX], res[MAX];

    printf("Enter first number: ");
    scanf("%s", num1);

    printf("Enter second number: ");
    scanf("%s", num2);

    printf("Addition of numbers: ");
    add(num1, num2, res);
    printf("%s\n", res);

    printf("Multiplication of numbers: ");
    multiply(num1, num2, res);
    printf("%s\n", res);

    return 0;
}

