/*
* Smallest window in a String containing all characters of other String
Last Updated : 09 Aug, 2024
Given two strings S (length m) and P (length n), the task is to find the smallest substring in S that contains all characters of P, including duplicates. If no such substring exists, return “-1”. If multiple substrings of the same length are found, return the one with the smallest starting index.

Examples: 

Input: S = “timetopractice”, P = “toc”
Output: toprac
Explanation: “toprac” is the smallest substring in which “toc” can be found.

Input: S = “zoomlazapzo”, P = “oza”
Output: apzo
Explanation: “apzo” is the smallest substring in which “oza” can be found. */

// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int findsubstring(char* s1, char* s2) {
    int count[256], cnt = 0;
    for (int i = 0; i < 256; i++) {
        count[i] = 0;
    }
    
    for (int i = 0; s1[i] != '\0'; i++) {
        count[(unsigned char)s1[i]]++;
    }
    
    for (int i = 0; s2[i] != '\0'; i++) {
        if (count[(unsigned char)s2[i]]  > 0) {
             count[(unsigned char)s2[i]]--;
             cnt++;
        }
    }
    
    if (cnt == strlen(s2)) {
        return 1;
    }
    
    return 0;
}

int main() {
    char* s1 = "zoomlazapzo";
    
    char* s2 = "oza";    

    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int min = n1;
    char temp[100];
    for (int i = 0; i < n1; i++) {
        for (int j = i; j < n1; j++) {
            char substr[50];
            strncpy(substr, s1 + i, j-i+1);
            substr[j-i+1] = '\0';
            if (findsubstring(substr, s2)) { 
                int len = strlen(substr);
                
                if (len < min ) {
                    min = len;
                    strcpy(temp, substr);
                }
            }
        }
    }
    
    printf("Sub : %s\n", temp);
    return 0;
}
