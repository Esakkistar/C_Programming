/*
 * How to replace a substring of a string
Given three strings S, S1, and S2 consisting of N, M, and K characters respectively, the task is to modify the string S by replacing all the substrings S1 with the string S2 in the string S.

Examples:

Input: S = “abababa”, S1 = “aba”, S2 = “a”
Output: aba
Explanation:
Change the substrings S[0, 2] and S[4, 6](= S1) to the string S2(= “a”) modifies the string S to “aba”. Therefore, print “aba”.

Input: S = “geeksforgeeks”, S1 = “eek”, S2 = “ok”
Output: goksforgoks */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int main() {
     char s[20] = "geeksforgeeks";
     char s1[] = "eek";
     char s2[] = "ok";
     char res[20];
     memset(res, 0, sizeof(res));
     
     int k = 0, cnt = 0;
     for (int i = 0; s[i] != '\0'; i++) {
         int t = i;
         for (int j = 0; s1[j] != '\0'; j++) {
             if (s[t] == s1[j]) {
                 t++;
                 cnt++;
                 continue;
             }
             else {
                 res[k++] = s[i];
                 break;
             }
         }
         if (strlen(s1) == cnt) {
             for (int j = 0; s2[j] != '\0'; j++) {
                 res[k++] = s2[j];
                 i = t-1;
             }
         }
         cnt = 0;
     }
     res[k] = '\0';
     printf("res : %s\n", res);
     return 0;
}

