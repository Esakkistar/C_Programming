/*
 *
  Find Excel column name from a given column number
Last Updated : 17 Aug, 2022
MS Excel columns have a pattern like A, B, C, …, Z, AA, AB, AC, …., AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named “A”, column 2 as “B”, and column 27 as “AA”.
Given a column number, find its corresponding Excel column name. The following are more examples.

Input          Output
 26             Z
 51             AY
 52             AZ
 80             CB
 676            YZ
 702            ZZ
 705            AAC
Thanks to Mrigank Dembla for suggesting the below solution in a comment.
Suppose we have a number n, let’s say 28. so corresponding to it we need to print the column name. We need to take the remainder with 26. 

If the remainder with 26 comes out to be 0 (meaning 26, 52, and so on) then we put ‘Z’ in the output string and new n becomes n/26 -1 because here we are considering 26 to be ‘Z’ while in actuality it’s 25th with respect to ‘A’.

Similarly, if the remainder comes out to be non-zero. (like 1, 2, 3, and so on) then we need to just insert the char accordingly in the string and do n = n/26.

Finally, we reverse the string and print.  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    char* alpha = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
    int n;
    printf("Enter Number : ");
    scanf("%d", &n);
    
    char res[10];
    int k = 0;
    int t = n;
    int rem;
    while (t != 0) {
        rem = t % 26;
        res[k++] = alpha[rem];
        t = (rem == 0 ) ? t/26 - 1 : t/26;
    }
    res[k] = '\0';
	
	/* while (t != 0) {
        rem = t % 26;
        if (rem == 0) {
            res[k++] = 'Z';
            t = t/26 - 1; 
        }
        else {
            res[k++] = (rem - 1) + 'A';
            t = t/26;
        }
    }
    res[k] = '\0'; */
    
    reverse(res);
    
    printf("%d - %s\n", n, res);
    
    return 0;
}
