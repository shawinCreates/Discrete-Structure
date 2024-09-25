#include<stdio.h>
void floor(float a) {
	int f=a;
	printf("\nThe Floor value of %f is %d",a,f);
}
void ceiling(float a) {
	int c=a+1;
	printf("\nThe ceiling value of %f is %d",a,c);
}
int main() {
	float num;
	printf("Enter the number: ");
	scanf("%f", &num);
	floor(num);
	ceiling(num);
	return 0;
}
