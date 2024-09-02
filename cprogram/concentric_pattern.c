/* concentric_pattern.c
 step1       step2
5 5 5 5 5 | 5 5 5 5
5 4 4 4 4 | 4 4 4 5
5 4 3 3 3 | 3 3 4 5
5 4 3 2 2 | 2 3 4 5
5 4 3 2 1 | 2 3 4 5

step3       step4
5 4 3 2 2 | 2 3 4 5
5 4 3 3 3 | 3 3 4 5
5 4 4 4 4 | 4 4 4 5
5 5 5 5 5 | 5 5 5 5 */

#include <stdio.h>

int main () {
        int n,r;
        printf("Enter the number : ");
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
                //step1
                for (int j = 1; j <= n; j++) {
                        r = i < j ? i : j;
                        printf("%d ",n-r+1);
                }
                //step2
                for (int j = n-1; j >= 1; j--) {
                        r = i < j ? i : j;
                        printf("%d ",n-r+1);
                }
                printf("\n");
        }

        for (int i = n-1; i >= 1; i--) {
                //step3
                for (int j = 1; j <= n; j++) {
                        r = i < j ? i : j;
                        printf("%d ",n-r+1);
                }
                //step4
                for (int j = n-1; j >= 1; j--) {
                        r = i < j ? i : j;
                        printf("%d ",n-r+1);
                }
                printf("\n");
        }


	printf("\n\n");

	for (int i = 1; i <= n; i++) {
                //step1
                for (int j = 1; j <= n; j++) {
                        r = i < j ? i : j;
                        printf("%d ",r);
                }
                //step2
                for (int j = n-1; j >= 1; j--) {
                        r = i < j ? i : j;
                        printf("%d ",r);
                }
                printf("\n");
        }

        for (int i = n-1; i >= 1; i--) {
                //step3
                for (int j = 1; j <= n; j++) {
                        r = i < j ? i : j;
                        printf("%d ",r);
                }
                //step4
                for (int j = n-1; j >= 1; j--) {
                        r = i < j ? i : j;
                        printf("%d ",r);
                }
                printf("\n");
        }

        return 0;
}

