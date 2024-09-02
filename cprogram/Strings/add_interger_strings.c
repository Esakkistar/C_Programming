/*
 * Sum of two large numbers
Last Updated : 26 Dec, 2023
Given two numbers as strings. The numbers may be very large (may not fit in long long int), the task is to find sum of these two numbers.

Examples: 

Input  : str1 = "3333311111111111", 
         str2 =   "44422222221111"
Output : 3377733333332222

Input  : str1 = "7777555511111111", 
         str2 =    "3332222221111"
Output : 7780887733332222 */
 

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

char* addBinary(char* s1, char* s2) {
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
    
    signed long int res[MAX];
    char res2[MAX];
    int carry = 0;
    int index = 0, index2 = 0;
    int val;
    for (int i = strlen(A)-1; i >= 0; i--) {
        val = carry + A[i] - '0' + B[i] - '0';
        if (val > 9) {
            res[index++] = val % 10;
            res2[index2++] = val % 10 + '0';
            carry = val / 10;
        }
        else {
            res[index++] = val;
            res2[index2++] = val + '0';
            carry = 0;
        }
    }
    
    if (carry) {
        res[index++] = carry;
        res2[index2++] = carry + '0';
    }
    res2[index2] = '\0';
    
    reverse_int(res, index);
    
    printf("rev : ");
    for (int i = 0; i < index; i++) {
        printf("%ld",res[i]);
    }
    printf("\n");
    
    reverse_char(res2);
    
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
  
    char* res = (strlen(str1) > strlen(str2)) ? addBinary(str1, str2) : addBinary(str2, str1);
    
    printf("AddStrings : %s\n", res);
    
    free(res);
    
    return 0;
}
