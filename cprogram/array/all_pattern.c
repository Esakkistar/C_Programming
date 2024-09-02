#include <stdio.h>

int main () {
        int n;

        printf("Enter the Number : ");
        scanf("%d",&n);

       for (int i = 1; i <= n; i++) {
                for (int j = n; j >= 1; j--) {
                        if (i >= j)
                              printf("*");
                        else
                              printf(" ");
                }
                for (int x = i-1; x >= 1; x--)
                        printf("*");

                printf("\n");
        }
        printf("\n");
	/**********************************************************/
        
	for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                        if (i >= j)
                              printf("*");
                        else
                              printf(" ");
                }
                printf("\n");
        }
        printf("\n");
	
	/**********************************************************/
        
	for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                        if (j==1 || j==n || i==1 || i==n)
                              printf("*");
                        else
                              printf(" ");
                }
                printf("\n");
        }
        printf("\n");

	/**********************************************************/
        
	for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                        if (j==1 || j==n || i==1 || i==n || i==j || i+j == n+1)
                              printf("*");
                        else
                              printf(" ");
                }
                printf("\n");
        }
	
	/**********************************************************/
        printf("\n");
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n-i; j++) {
                          printf(" ");
                }

                for (int j = 1; j <= 2*i-1; j++) {
                          if (j == 1 || j == 2*i-1 || i == n )
                               printf("*");
                          else
                               printf(" ");
                }

                printf("\n");
        }

	/**********************************************************/
        printf("\n");
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                        printf(" ");
                }
                for (int x = i; x <= 2*n-i; x++) {
                        if ( i == 1 || x == i || x == 2*n-i)
                               printf("*");
                          else
                               printf(" ");

                }
                printf("\n");
        }

	/*6 **********************************************************/
       
        printf("\n");
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                        if (j==1 || j==i || i == n )
                              printf("*");
                        else
                              printf(" ");
                }
                printf("\n");
        }

	/*7*********************************************************/

        printf("\n");
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n-i; j++) {
                          printf(" ");
                }

                for (int j = 1; j <= 2*i-1; j++) {
                          if (j == 1 || j == 2*i-1)
                               printf("*");
                          else
                               printf(" ");
                }

                printf("\n");
        }
        for (int i = 2; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                        printf(" ");
                }
                for (int x = i; x <= 2*n-i; x++) {
                        if ( i == 1 || x == i || x == 2*n-i)
                               printf("*");
                          else
                               printf(" ");

                }
                printf("\n");
        }


	/*8*********************************************************/

        printf("\n");
        for (int i = 1; i <=n; i++) {
                for (int j = 1; j <= n-i; j++) {
                        printf(" ");
                }
                for (int k = 1; k <= 2*i-1; k++ ){
                        printf("*");
                }
                printf("\n");
        }
        for (int i = 2; i <=n; i++) {
                for (int j = 1; j < i; j++) {
                        printf(" ");
                }
                for (int k = i; k <= 2*n-i; k++ ){
                        printf("*");
                }
                printf("\n");
        }

        printf("\n");


	/*9*********************************************************/

        for (int i = 1; i <=n; i++) {
                for (int j = 1; j <= n-i; j++) {
                        printf(" ");
                }
                for (int k = 1; k <= 2*i-1; k++ ){
                        printf("%d",i);
                }
                printf("\n");
        }
        for (int i = 2; i <=n; i++) {
                for (int j = 1; j < i; j++) {
                        printf(" ");
                }
                for (int k = i; k <= 2*n-i; k++ ){
                        printf("%d",n-i+1);
                }
                printf("\n");
        }

	/*10*********************************************************/

        printf("\n");
        
        for (int i = 1; i <=n; i++) {
                for (int j = 1; j <= n-i; j++) {
                        printf(" ");
                }
                for (int k = 1; k <= 2*i-1; k++ ){
			if (k == 1 || k == 2*i-1)
                               printf("%d",i);
			else 
			       printf(" ");
                }
                printf("\n");
        }
        for (int i = 2; i <=n; i++) {
                for (int j = 1; j < i; j++) {
                        printf(" ");
                }
                for (int k = i; k <= 2*n-i; k++ ){
			if (k == i || k == 2*n-i)
                              printf("%d",n-i+1);
			else
			      printf(" ");
                }
                printf("\n");
        }

        printf("\n");


	/*11*********************************************************/

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n-i; j++) {
			printf(" ");
		}
		for (int j = 1; j <= i ; j++) {
                        printf("%d", j);
                }
		for (int k = i - 1; k >= 1; k--) {
			printf("%d", k);
		}
		printf("\n");
	}

	for (int i = n-1; i >= 1; i--) {
		for (int j = 1; j <= n-i; j++) {
                        printf(" ");
                }
                for (int j = 1; j <= i ; j++) {
                        printf("%d", j);
                }
                for (int k = i - 1; k >= 1; k--) {
                        printf("%d", k);
                }
                printf("\n");
	}
	
	/*12*********************************************************/

       	for (int i = n; i >= 1; i--) {
       		for (int j = n; j > i; j--) {
           		printf(" ");
		}
       		for (int j = 1; j <= 2*i-1; j++) {
           		printf("*");
		}
       		for (int k = 1; k <= 3; k++) {
            		for (int j = 2*n-i; j > i; j--) {
                		printf(" ");
			}
            		for (int j = 1; j <= 2*i-1; j++) {
                		printf("*");
			}
		}
       		printf("\n");
       }
       for (int i = 2; i <= n; i++) {
       		for (int j = n; j > i; j--) {
           		printf(" ");
		}
       		for (int j = 1; j <= 2*i-1; j++) {
           		printf("*");
		}
       		for (int k = 1; k <= 3; k++) {
            		for (int j = 2*n-i; j > i; j--) {
                 		printf(" ");
			}
            		for (int j = 1; j <= 2*i-1; j++) {
                		printf("*");
			}
		}
       		printf("\n");
       }



        return 0;
}

