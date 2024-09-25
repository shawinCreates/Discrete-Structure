#include<stdio.h>
int main() {
	int i, j;
	int a[5], b[5];
	printf("\nEnter the elements of set a: ");
	for(i=0; i<5; i++) {
		scanf("%d",&a[i]);
	}
	printf("\nEnter the elements of set b: ");
	for(i=0; i<5; i++) {
		scanf("%d",&b[i]);
	}
	
	//Cartissian product of set a and b
	printf("\nCartisian Product of set a and b is ");
	for(i=0; i<5; i++) {
		for(j=0; j<5; j++) {
			printf("(%d,%d) ",a[i],b[j]);
		}
	}
	printf("\n");
	
	//Union of set a and b
	printf("\nUnion of set a and b is ");
	for(i=0; i<5; i++) {
		printf("%d,",a[i]);
	}
	for(i=0; i<5; i++) {
		int duplicate=0;
		for(j=0; j<5; j++) {
			if(b[i]==a[j]) {
				duplicate=1;
				break;
			}
		}
		if(!duplicate)
		printf("%d,",b[i]);
	}
	printf("\n");
	
	//Intersection of set a and b
	printf("\nIntersection betweeen set a nad set b is ");
	for(i=0; i<5; i++) {
		for(j=0; j<5; j++) {
			if(a[i]==b[j])
			printf("%d, ",a[i]);
		}
	}
	printf("\n");
	
	//Difference between set a and b
	printf("\nDifference between two set a and set b is ");
	for(i=0; i<5; i++) {
		int same=0;
		for(j=0; j<5; j++) {
			if(a[i]==b[j]) {
			same=1;
			break;	
			}	
		}
		if(!same)
		printf("%d, ",a[i]);
	}
	printf("\n");
	//Difference between set b and a 
	printf("\nDifference between two set b and set a is ");
	for(i=0; i<5; i++) {
		int same=0;
		for(j=0; j<5; j++) {
			if(b[i]==a[j]) {
			same=1;
			break;	
			}	
		}
		if(!same)
		printf("%d, ",b[i]);
	}
	printf("\n");
	return 0;
}
