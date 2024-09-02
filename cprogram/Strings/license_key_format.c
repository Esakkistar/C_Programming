/*
 * License Key Formatting
Last Updated : 26 Apr, 2023
Given a string S that consists of only alphanumeric characters and dashes. The string is separated into N + 1 groups by N dashes. Also given an integer K.

We want to reformat the string S, such that each group contains exactly K characters, except for the first group, which could be shorter than K but still must contain at least one character. Furthermore, a dash must be inserted between two groups, and you should convert all lowercase letters to uppercase.

Return the reformatted string.

Examples:

Input: S = “5F3Z-2e-9-w”, K = 4
Output: “5F3Z-2E9W”
Explanation: The string S has been split into two parts,
each part has 4 characters.
Note that two extra dashes are not needed and can be removed.

Input: S = “2-5g-3-J”, K = 2
Output: “2-5G-3J”
Explanation: The string s has been split into three parts,
each part has 2 characters except the first part
as it could be shorter as mentioned above */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void format(char* s,int k) {
	int n = strlen(s);
	char* ch = (char*)malloc((n+1) * sizeof(char));

	int j = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != '-') 
			ch[j++] = s[i];
	}
	ch[j] = '\0';
	ch = (char*) realloc(ch, j+1);
	
	int rem = j % k;
        int grp = j / k;

	if (rem > 0) 
		grp += 1;

	char* res = (char*) malloc(50 * sizeof(char));

	if (rem > 0) {
		strncpy(res, ch+0, rem);
		strcat(res, "-");
	}
	printf("grp : %d\n", grp);
	int t = rem;
	for (int i = 0; i < grp-1; i++) {
		char te[10];
		strncpy(te, ch+t, k);
		strcat(res, te);
		if (i+1 != grp) {
			printf("%d - %s\n",i, res);
			strcat(res, "-");
		}
		t = t+k;
	}

	printf("ch : %s, res : %s\n", ch, res);

	free(ch);
	free(res);
}

int main() {
    
    char* s = (char*) malloc (MAX * sizeof(char));
    printf("Enter the String : ");
    scanf("%s", s);
    
    int k;
    printf("Enter No.of chars in each group : ");
    scanf("%d", &k);
   
    format(s, k);

    int dash = 0;
    int character = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
	    if (s[i] == '-') dash++;
            else character++;
    }
    
    int grp = character / k;
    
    int rem = character % k;
    
    if (rem > 0 && rem <= k) grp += 1;
    
    printf("Dash : %d, chars : %d, rem : %d, grp : %d\n", dash, character, rem, grp);
    
    int t = 0;
    int j = 0;
    char key[50];
    for (int i = 0; s[i] != '\0'; i++) {
        if (rem > 0 && s[i] != '-') {
             printf("%c", s[i]);
	     key[j++] = s[i];
             rem--;
            
	     if (rem == 0) {
		     printf("-");
		     key[j++] = '-';
	     }
            
	     continue;
        }

	if (s[i] == '-') 
             continue;

        if (t == k) {
             printf("-");
	     key[j++] = '-';
             t = 0;
        }
        
	printf("%c", s[i]);
	key[j++] = s[i];
        t++;
     }
     printf("\n");

     key[j] = '\0';

     printf("%s\n", key);
    
     free(s); 
     return 0;
}

