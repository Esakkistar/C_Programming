#include <stdio.h>
#include <string.h>

void swap (char* a, char* b) {
    char ch = *a;
    *a = *b;
    *b = ch;
}

int main() {
    char s[] = "Esakki Babu";
    int n = strlen(s);
    printf("Reverse: ");
    int i = n-1;
    while (i >= 0) {
        printf("%c",s[i--]);
    }
    printf("\n");
    
    printf("Strlen : %d, sizeof : %ld\n",n, sizeof(s));
    int k = 0, l = n-1;
    while (k < n/2) {
        swap(&s[k++], &s[l--]);
    }
    s[n] = '\0';
    
    printf("Reverse: %s\n", s);
    return 0;
}
