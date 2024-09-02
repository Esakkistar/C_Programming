/*
* Find an equal point in a string of brackets

Given a string of brackets, the task is to find an index k which decides the number of opening brackets is equal to the number of closing brackets. 
The string must be consists of only opening and closing brackets i.e. ‘(‘ and ‘)’.

An equal point is an index such that the number of opening brackets before it is equal to the number of closing brackets from and after.

Examples:  

Input: str = “(())))(“
Output:   4
Explanation: After index 4, string splits into (()) and ))(. The number of opening brackets in the first part is equal to the number of closing brackets in the second part.

Input: str = “))”
Output: 2
Explanation: As after 2nd position i.e. )) and “empty” string will be split into these two parts. So, in this number of opening brackets i.e. 0 in the first part is equal to the number of closing brackets in the second part i.e. also 0. */


#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "(()))(()()())))";
    int n = strlen(s);
    
    int index = 0, count;
    
    for (int i = 0; i < n; i++) {
        int before_open = 0, after_close = 0;
        
        for (int j = i-1; j >=0; j--) {
            if (s[j] == '(') {
                before_open++;
            }
        }
        for (int j = i; j < n; j++) {
            if (s[j] == ')') {
                after_close++;
            }
        }
        printf("i : %d, before_open : %d, after_close : %d\n",i,before_open,after_close );
        if (before_open == after_close) {
            index = i;
            count = before_open;
        }
    }
    
    printf("Equal index : %d, open-close brackets : %d\n", index, count);
    
    return 0;
}
