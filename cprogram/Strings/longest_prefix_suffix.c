/*
 * Longest prefix which is also suffix
Last Updated : 29 Mar, 2024
Given a string s, find the length of the longest prefix, which is also a suffix. The prefix and suffix should not overlap.

Examples: 

Input : S = aabcdaabc
Output : 4
Explanation: The string “aabc” is the longest prefix which is also suffix.

Input : S = abcab
Output : 2

Input : S = aaaa
Output : 3 */

#include <stdio.h>
#include <string.h>

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
int prefix_suffix (char* s) {
    int n = strlen(s);
    
    if (n < 2) {
        return 0;
    }
    int i = 0, j = n/2;
    int cnt = 0;
    
    char s2[20];
    strcpy(s2,s);
    reverse(s2);
    if (strcmp(s, s2) == 0) {
         return n-1;
    }
    while (i != n/2 && j != n) {
        if (s[i] == s[j]) {
            cnt++;
            i++;
            j++;
        }
        else {
            j++;
            i = 0;
            cnt = 0;
        }
    } 
    return cnt;
}
int main() {
    char* s = "aabcdaabc";
    int cnt =prefix_suffix(s);
    printf("cnt : %d\n", cnt);
    return 0;
}
