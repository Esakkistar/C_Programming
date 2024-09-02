/*
 * Isomorphic Strings
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.

If the characters in str1 can be changed to get str2, then two strings, str1 and str2, are isomorphic. A character must be completely swapped out for another character while maintaining the order of the characters. A character may map to itself, but no two characters may map to the same character.

Example 1:

Input:
str1 = aab
str2 = xxy
Output: 
1
Explanation: 
There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output: 
0
Explanation: 
There are two different characters in aab but there are three different charactersin xyz. So there won't be one to one mapping between str1 and str2. */ 

// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int isomorphic_string(char* s1, char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    
    if (n1 != n2) {
        return 0;
    }
    int f[n1];
    memset(f, 1, sizeof(f));
    int k = 0;
    char map[n1];
    for (int i = 0; i < n1; i++) {
        if (f[i]) {
            for (int j = i+1; j < n1; j++) {
                if (s1[i] == s1[j]) {
                    //map[i] = s2[k];
                    map[j] = s2[k];
                    f[j] = 0;
                }
            }
            if (f[i]) {
                map[i] = s2[k];
            }
        }
        k++;
    }
    map[k] = '\0';
    printf("s1 : %s, s2 = %s, map : %s\n", s1,s2,map);
    
    if (strcmp (s2, map) == 0) {
        return 1;
    }
    
    return 0;
}
int main() {
    char s1[] = "aabc";
    char s2[] = "xxzy";
    if (isomorphic_string(s1, s2)) {
        printf("Both Strings are Isomorphics\n");
    }
    else {
        printf("Both Strings are Not Isomorphics\n");
    }
    return 0;
}
