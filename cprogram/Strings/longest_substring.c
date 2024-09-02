/*
 *
  Length of the longest substring without repeating characters
Last Updated : 15 Apr, 2024
Given a string str, find the length of the longest substring without repeating characters. 

Example:

Example 1:
Input: “ABCDEFGABEF”
Output: 7
Explanation: The longest substring without repeating characters are “ABCDEFG”, “BCDEFGA”, and “CDEFGAB” with lengths of 7

Example 2:
Input: “GEEKSFORGEEKS”
Output: 7
Explanation: The longest substrings without repeating characters are “EKSFORG” and “KSFORGE”, with lengths of 7 */

#include <stdio.h>
#include <string.h>

int findsubstring(char* s1) {
    int count[256], cnt = 0;
    for (int i = 0; i < 256; i++) {
        count[i] = 0;
    }
    
    for (int i = 0; s1[i] != '\0'; i++) {
        count[(unsigned char)s1[i]]++;
    }
    
    for (int i = 0; s1[i] != '\0'; i++) {
        if (count[(unsigned char)s1[i]] > 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* s1 = "GEEKSFORGEEKS";

    int n1 = strlen(s1);
    int max = 0;
    char temp[100];
    for (int i = 0; i < n1; i++) {
        for (int j = i; j < n1; j++) {
            char substr[50] = "";
            strncpy(substr, s1 + i, j-i+1);
            //substr[j-i+1] = '\0';
            if (findsubstring(substr)) { 
                int len = strlen(substr);
                //printf("sub : %s\n", substr);
                if (len > max ) {
                    max = len;
                    strcpy(temp, substr);
                }
            }
        }
    }
    
    printf("The length of the longest non-repeating character substring : %s - %ld\n", temp, strlen(temp));
    return 0;
}

