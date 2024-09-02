/*
 * Check if a string can be obtained by rotating another string 2 places
Last Updated : 18 Jul, 2024
Given two strings, str1 and str2, the task is to determine if str2 can be obtained by rotating str1 exactly 2 places in either a clockwise or anticlockwise direction.

Examples:

Input: str1 = “amazon”, str2 = “azonam”
Output: Yes
Explanation: Rotating string1 by 2 places in anti-clockwise gives the string2.

Input: str1 = “amazon”, str2 = “onamaz”
Output: Yes
Explanation: Rotating string1 by 2 places in clockwise gives the string2. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (char* a, char* b) {
	char ch = *a;
	*a = *b;
	*b = ch;
}

int string_swap (char* str1, char* str2, int* k ) {
	int t = 1;
	char s1[20], s2[20];

	strcpy(s1, str1);
	strcpy(s2, str2);

	int i, j;

	while (t <= *k) {
		i = 0, j = strlen(s1) - 1;
		while (i != j) {
			swap (&s1[i], &s1[j]);
			i++;
		}
		t++;
	}
	
	if ( strcmp (str2, s1) == 0) {
		*k = 0;
	        printf("s1 : %s, str1 : %s, str2 : %s, k : %d\n", s1, str1, str2, *k);
		return 1;
	}

	t = 1;
	strcpy(s1, str1);

	while (t <= *k) {
		i = 0, j = strlen(s1) - 1;
                while (i != j) {
                        swap (&s1[i], &s1[j]);
                        j--;
                }
                t++;
        }
        if ( strcmp (str2, s1) == 0) {
		*k = 1;
	        printf("s1 : %s, str1 : %s, str2 : %s, k : %d\n", s1, str1, str2, *k);
                return 1;
        }

	return 0;
}

int main () {
	char str1[] = "amazon", str2[] = "onamaz";
	int k = 2;

	int n = string_swap(str1, str2, &k);

	if ( n == 1 && k == 1 ) {
	      printf("Rotating %s by 2 places in clockwise gives the %s\n.", str1,str2);
	}
	else if (n == 1 && k == 0 ) { 
	      printf("Rotating %s by 2 places in anti-clockwise gives the %s\n.", str1,str2);
	}
	else {
	      printf("Can't get string2 by Rotating string1 by 2 places\n");
	}

	return 0;
}


