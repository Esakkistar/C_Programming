/*
 * Program to add two binary strings
   Given two binary strings, return their sum (also a binary string).

Example: 

Input:  a = "11", b = "1"
Output: "100"  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void swap (char* a, char* b) {
    char ch = *a;
    *a = *b;
    *b = ch;
}

void reverse (char* s) {
    int n = strlen(s);
    int j = n-1;
    for (int i = 0; i < n/2; i++) {
        swap (&s[i], &s[j--]);
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
    
    
    char res[20];
    char carry = '0';
    int index = 0;
    for (int i = strlen(A)-1; i >= 0; i--) {
        if (A[i] == '1' && B[i] == '1') {
            if (carry == '1') {
                res[index++] = '1';
                carry = '1';
            }
            else {
                res[index++] = '0';
                carry = '1';
            }
        }
        else  if (A[i] == '0' && B[i] == '0') {
            if (carry == '1') {
                res[index++] = '1';
                carry = '0';
            }
            else {
                res[index++] = '0';
                carry = '0';
            }
        }
        else  if (A[i] != B[i]) {
            if (carry == '1') {
                res[index++] = '0';
                carry = '1';
            }
            else {
                res[index++] = '1';
                carry = '0';
            }
        }
    }
    if (carry == '1') {
        res[index++] = carry;
    }
    res[index] = '\0';

    reverse(res);
    
    char* str = strstr(res, "1");
   
    char* result = (char*) malloc ((strlen(str)+1) * sizeof(char));
    strcpy(result, str);
    
    free(A);
    free(B);
    return result;
}
int main() {
    char str1[MAX];
    char str2[MAX];
    printf("Binary String1: ");
    scanf("%s", str1);
    printf("Binary String2: ");
    scanf("%s", str2);
    
    char* res = (strlen(str1) > strlen(str2)) ? addBinary(str1, str2) : addBinary(str2, str1);
    
    printf("AddBinary : %s\n", res);
    
    free(res);
    return 0;
}
