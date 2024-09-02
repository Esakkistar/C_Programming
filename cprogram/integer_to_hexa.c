#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char h[] = "0123456789ABCDEF";
    int N;
    printf("Enter the Number : ");
    scanf("%d", &N);
    char hexa[10] = "";
    int t = N;
    int rem = 0;
    int i = 0;
    
    while (t > 0) {
        rem = t % 16;
        hexa[i] = h[rem];
        t = t/16;
        i++;
    }
    hexa[i] = '\0';
    for (int i = strlen(hexa) - 1; i >= 0; i--) {
        printf("%c", hexa[i]);
    }
    printf("\n");
    return 0;
}

