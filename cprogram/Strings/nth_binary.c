/*
 *
 Find i’th index character in a binary string obtained after n iterations | Set 2
Last Updated : 29 Nov, 2023
Given a decimal number m, convert it into a binary string and apply n iterations, in each iteration 0 becomes “01” and 1 becomes “10”. Find ith(based indexing) index character in the string after nth iteration.
Examples: 
 

Input: m = 5 i = 5 n = 3
Output: 1
Explanation
In the first case m = 5, i = 5, n = 3. 
Initially, the string is  101  ( binary equivalent of 5 )
After 1st iteration -   100110
After 2nd iteration - 100101101001
After 3rd iteration -   100101100110100110010110 
The character at index 5 is 1, so 1 is the answer
Input: m = 11 i = 6 n = 4
Output: 1 */

#include <stdio.h> 
#include <limits.h> 
#include <string.h> 
#include <stdlib.h>

#define MAX 100

void swap_char(char* a, char* b) {
    char ch = *a;
    *a = *b;
    *b = ch;
}
void reverse(char* s) {
    int n = strlen(s);
    int j = n-1;
    for (int i = 0; i < n/2; i++) {
        swap_char(&s[i], &s[j--]);
    }
}
char* DeciToBinary_string(int n) {
    char* bin = (char*) malloc(MAX * sizeof(char));
    int k = 0;
    while (n != 0) {
        bin[k++] = (n % 2) + '0';
        n = n / 2;
    }
   
    bin =(char*) realloc (bin, (strlen(bin)+1)*sizeof(char));
    bin[k] = '\0';
    reverse(bin);
    
    return bin;
}
char nthCharacter(int num, int n, int index) {
    char temp[MAX] = "";
    char res[MAX] = "";
    char* bin = DeciToBinary_string(num);
    strcpy(temp, bin);
    while (n > 0) {
        for ( int i = 0; temp[i] != '\0'; i++) {
            if (temp[i] == '0') {
                (res[0] == '\0') ? strcpy(res,"01") : strcat(res, "01");
            }
            else {
                (res[0] == '\0') ? strcpy(res,"10") : strcat(res, "10");
            }
        }
        strcpy(temp, res);
        res[0] = '\0';
        n--;
    }
    free(bin);
    
    return temp[index];
} 
int main () {
    int num, n, it;
    printf("Enter Number : ");
    scanf("%d", &num);
    printf("Iteration : ");
    scanf("%d", &n);
    printf("Index : ");
    scanf("%d", &it);
   
    char ch = nthCharacter(num, n, it);
    printf("%dth index : %c\n",it, ch);

    return 0;
}
