/*
 * Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.' */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* reverse (char* string) {
    int n = strlen(string);
    char s[n];
    strcpy(s,string);

    char *str = strtok(s,".");
    char **str2 = (char**) malloc ((n+1) * sizeof(char*));

    int i = 0;
    while (str) {
        str2[i] = (char*) malloc ((strlen(str)+1) * sizeof(char));
        strcpy(str2[i], str);
        i++;
        str = strtok(NULL,".");
    }

    char* reversed = (char*) malloc ((n+1) * sizeof(char));

    for (int j = i-1; j >= 0; j--) {
        strcat(reversed,str2[j]);
        if (j > 0)
            strcat(reversed,".");
    }

    free(str2);

    return reversed;
}

int main() {
    char string[] = "i.like.this.program.very.much";
    
    printf ("String : %s\n",string);
    char* reversed = reverse(string);
    printf ("Reverse String : %s\n",reversed);
    
    return 0;
}
