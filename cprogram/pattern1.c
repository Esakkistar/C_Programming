#include <stdio.h>
#include <stdlib.h>

int main () {
	int n;
	printf("Enter the Number : ");
	scanf("%d",&n);
        
	for (int i = n,c = 0; i >= 1; i--,c++) {
                for (int x = 0; x < c; x++) {
			printf("%d",n-x);
		}
		for (int j = 1; j <= i; j++) {
			printf("%d",i);
		}
                for (int x = c-1; 0<=x; x--) {
			printf("%d",n-x);
		}

		for (int j = n,y = 1; y <= i; j--,y++) {
                        printf("%d",j);
                }
		for (int x = 0; x < c; x++) {
                        printf("%d",c+1);
                }

		for (int j = c+1; j <= n; j++) {
                        printf("%d",j);
                }

		printf("\n");
	}
	return 0;
}
