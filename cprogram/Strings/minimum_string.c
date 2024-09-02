/*
 *Minimum number of times A has to be repeated such that B is a substring of it
Given two strings A and B. The task is to find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution exists, print -1.

Examples: 

Input : A = “abcd”, B = “cdabcdab” 
Output : 3 
Explanation: After repeating A three times, A will become “abcdabcdabcd”. Now, B is now a substring of A = “abcdabcdabcd”. B is not a substring of A when it is repeated less than 3 times.

Input : A = “ab”, B = “cab” 
Output : -1
Explanation: B will not become a substring of A after any repetition of A. */
 
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
    char str1[MAX] = "abcd";
    char str2[MAX] = "cdabcdab";
    int flag, t = 0;
    for (int i = 0; str2[i] != '\0'; i++ ) {
        flag = 0;
        for (int j = 0; str1[j] != '\0'; j++ ) {
            if (str2[i] == str1[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("t : %d\n", -1);
            return 0;
        }
    }
    
    char A[MAX];
    strcpy(A, str1);
    printf("A : %s\n", A);
    for (int i = 1; i < MAX; i++) {
        char* str = strstr(A, str2);
        printf("str : %s\n", str);
        if (str) {
            t = i;
            break;
        }
        strcat(A,str1);
        printf("A : %s\n", A);
    }
    printf("t : %d\n", t);
    return 0;
}
