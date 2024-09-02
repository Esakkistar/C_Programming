#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define SWAP(a, b, type) { \
        type t = a; \
        a = b; \
        b = t; 

void swap_int (signed long int * a, signed long int* b) {
    signed long int t = *a;
    *a = *b;
    *b = t;
}

void reverse_int(signed long int* s, int n) {
    //int n = sizeof(s) / sizeof(s[0]);
    int j = n-1;
    for (int i = 0; i < n/2; i++) {
        swap_int(&s[i], &s[j--]);
    }
}

void swap_char(char* a, char* b) {
    char ch = *a;
    *a = *b;
    *b = ch;
}

void reverse_char(char* s) {
    int n = strlen(s);
    int j = n-1;
    for (int i = 0; i < n/2; i++) {
        swap_char(&s[i], &s[j--]);
    }
}

char* addString_Integer(char* s1, char* s2) {
    char* A = (char*) malloc((strlen(s1) + 1) * sizeof(char));
    char* B = (char*) malloc((strlen(s2) + 1) * sizeof(char));
    
    int diff = strlen(s1) - strlen(s2);
    char padding[10];
    int i = 0;
    if (diff != 0) {
        for (i = 0; i < diff; i++) {
            padding[i] = '0';
        }
        padding[i] = '\0';
    }
    int new_size = strlen(s2) + diff;

    strcpy (A, s1);
    B = (char*) realloc(B, (new_size + 1) );
    strcpy (B, padding);
    strcat(B, s2);
    
    signed long int res[MAX];
    char res2[MAX];
    int carry = 0;
    int index = 0, index2 = 0;
    int val;
    for (int i = strlen(A)-1; i >= 0; i--) {
        val = carry + (A[i] - '0' + B[i] - '0');
        res[index++] = val % 10;
        res2[index2++] = val % 10 + '0';
        carry = val / 10;
    }
    
    if (carry) {
        res[index++] = carry;
        res2[index2++] = carry + '0';
    }
    res2[index2] = '\0';
    
    reverse_int(res, index);
    
    reverse_char(res2);
    
    char* result = (char*) malloc ((strlen(res2)+1) * sizeof(char));
    strcpy(result, res2);
    
    free(A);
    free(B);
    return result;
}

char* subString_Integer(char* s1, char* s2) {
    char* A = (char*) malloc((strlen(s1) + 1) * sizeof(char));
    char* B = (char*) malloc((strlen(s2) + 1) * sizeof(char));
    
    int diff = strlen(s1) - strlen(s2);
    char padding[10];
    int i = 0;
    if (diff != 0) {
        for (i = 0; i < diff; i++) {
            padding[i] = '0';
        }
        padding[i] = '\0';
    }
    int new_size = strlen(s2) + diff;

    strcpy (A, s1);
    B = (char*) realloc(B, (new_size + 1) * sizeof(char));
    strcpy (B, padding);
    strcat(B, s2);

    char res2[MAX];
    int borrow = 0;
    int index2 = 0;
    int val;
    for (int i = strlen(A)-1; i >= 0; i--) {
        val = (A[i] - '0') - (B[i] - '0') - borrow;
        if (val < 0) {
            val += 10;
            res2[index2++] = val + '0';
            borrow = 1;
        }
        else {
            res2[index2++] = val + '0';
            borrow = 0;
        }
    }
    
    res2[index2] = '\0';
    
    reverse_char(res2);

    for (int i = 0; res2[i] != 0; i++) {
        if (res2[i] != '0') {
            strncpy(res2, &res2[i], strlen(res2));
            //res2[strlen(res2)] = '\0';
            break;
        }
    }
    char* result = (char*) malloc ((strlen(res2)+1) * sizeof(char));
    strcpy(result, res2);
    
    free(A);
    free(B);
    return result;
}
int main() {
    char str1[MAX];
    char str2[MAX];
    printf("String1: ");
    scanf("%s", str1);
    printf("String2: ");
    scanf("%s", str2);
  
    char* res = (strlen(str1) > strlen(str2)) ? addString_Integer(str1, str2) : addString_Integer(str2, str1);
    
    printf("AddStrings : %s\n", res);
    
    char* res2 = (strlen(str1) > strlen(str2)) ? subString_Integer(str1, str2) : subString_Integer(str2, str1);
    
    printf("SubStrings : %s\n", res2);
    
    free(res);
    free(res2);
    
    return 0;
}
