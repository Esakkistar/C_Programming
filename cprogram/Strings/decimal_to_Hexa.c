#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(char* a, char* b) {
    char ch = *a;
    *a = *b;
    *b = ch;
}

void reverse(char* h) {
    int n = strlen(h);
    int i = 0;
    int j = n-1;
    if (n == 2) {
        swap(&h[i], &h[j]);
        return;
    }
    while (i < n/2) {
        swap(&h[i], &h[j--]);
        i++;
    }
}
char* deci_to_hex(int n) {
    char *h = "0123456789ABCDEF";
    char* hex = (char*) malloc (5*sizeof(char));
    
    if (n <= 15) {
        hex[0] = h[n];
        hex[1] = '\0';
        hex = realloc(hex, 2);
        return hex;
    }
    
    int i = 0;
    while (n != 0) {
        int rem = n % 16;
        hex[i++] = h[rem];
        n /= 16;
    }
    hex[i] = '\0';
    hex = realloc(hex, strlen(hex) + 1);
    reverse (hex);
    return hex;
}
int main() {
    char *s = "aaaabbbcbbbdbbdbbbbbbaaaaaaaadddddddddbbb";
    int c[256];
    memset(c, 0, sizeof(c));
    
    for (int i = 0; s[i] != '\0'; i++) {
        c[(unsigned char) s[i]]++;
    }
    char res[20];
    int j = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        int n = c[s[i]];
        if (n) {
            res[j] = s[i];
            char* s = deci_to_hex(n);
            res[j+1] = '\0';
            strcat(res, s);
            j = strlen(res);
        }
        c[s[i]] = 0;
    }
        
    printf("Res : %s\n", res);
    reverse(res);
    printf("Res : %s\n", res);
    
    return 0;
}

