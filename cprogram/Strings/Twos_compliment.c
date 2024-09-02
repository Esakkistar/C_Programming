#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

char* twos_compliment_shortcut(char* x) { 
    char* y = (char*) malloc(MAX * sizeof(char));
    int len = strlen(x);
    
    int flag = 0;
    for (int i = len-1; i >= 0; i--) {
        if (flag == 1) {
            if (x[i] == '1') {
                 y[i] = '0';
            }
            else {
                y[i] = '1';
            }
        }
        else if (x[i] == '1'){
            y[i] = x[i];
            flag = 1;
        }
        else {
            y[i] = x[i];
        }
    }
    y[len] = '\0';
   
    char z[MAX];
    if (flag == 0) {
        strcpy(z,"1");
        strcat(z,y);
        strcpy(y,z);
        return y;
    }
    return y;
}

void swap (char* a, char* b) {
    char ch = *a;
    *a = *b;
    *b = ch;
}

void reverse (char* s) {
    int n = strlen(s);
    int j = n-1;
    int i = 0;
    while(i < n/2) {
        swap (&s[i++], &s[j--]);
    }
}

void ones_complement(char* x) {
    for (int i = 0; x[i] != '\0'; i++) {
        x[i] = x[i] == '1' ? '0' : '1';
    }
}
char* twos_compliment_method(char* s) {
    char* one = "00000001";
    char x[MAX];
    strcpy(x, s);
    ones_complement(x);
    int len = strlen(x);
    int carry = 0;
    char res[MAX];
    int index = 0;
    for (int i = len-1; i >= 0; i--) {
        if (x[i] == '1' && one[i] == '1') {
            if (carry == 1) {
                res[index++] = '1';
                carry = 1;
            }
            else {
                res[index++] = '0';
                carry = 1;
            }
        }
        else if (x[i] == '0' && one[i] == '0') {
            if (carry == 1) {
                res[index++] = '1';
                carry = 0;
            }
            else {
                res[index++] = '0';
                carry = 0;
            }
        }
        else if (x[i] != one[i]) {
            if (carry == 1) {
                res[index++] = '0';
                carry = 1;
            }
            else {
                res[index++] = '1';
                carry = 0;
            }
        }
    }
    
    if (carry == 1) {
        res[index++] = '1';
    } 
    res[index] = '\0';
    reverse(res);
    
    char* y = (char*) malloc((strlen(res)+1) * sizeof(char));
    strcpy(y, res);
    return y;
}

char* deci_to_binary(int n) {
    int total_bits = 8;
    char* y = (char*) malloc((total_bits+1) * sizeof(char));
    memset(y,'0',sizeof(y));
    int i = total_bits - 1;
    
    while(n != 0) {
        y[i--] = n % 2 + '0';
        n /= 2;
    }
    y[total_bits] = '\0';
    
    return y;
}

int main() {
    int N;
    printf("Enter the Number : ");
    scanf("%d", &N);
    char* x = deci_to_binary(N);
    printf("Binary of %d : %s\n",N,x);
    char* y = twos_compliment_shortcut(x);
    printf("Twos_Compliment_shortcut : %s\n",y);
    
    char* z = twos_compliment_method(x);
    printf("Twos_Compliment_method: %s\n",z);
    
    free(y);
    free(z);
    return 0;
}
