/*
 * Check if two strings are k-anagrams or not
Last Updated : 04 Sep, 2023
Given two strings of lowercase alphabets and a value k, the task is to find if two strings are K-anagrams of each other or not.
Two strings are called k-anagrams if following two conditions are true.

Both have same number of characters.
Two strings can become anagram by changing at most k characters in a string.
Examples :

Input:  str1 = "anagram" , str2 = "grammar" , k = 3
Output:  Yes
Explanation: We can update maximum 3 values and
it can be done in changing only 'r' to 'n'
and 'm' to 'a' in str2.
Input:  str1 = "geeks", str2 = "eggkf", k = 1
Output:  No
Explanation: We can update or modify only 1
value but there is a need of modifying 2 characters.
i.e. g and f in str 2. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k_anagrams(char* s1, char* s2, int k) {
	int n1 = strlen(s1);
    	int n2 = strlen(s2);

    	if (n1 != n2) {
        	return 0;
	}

	int freq1[256];
	memset(freq1, 0, sizeof(freq1));
	
	int freq2[256];
	memset(freq2, 0, sizeof(freq2));

	int f[n1];
	memset(f, 1, sizeof(f));

	char s3[n1];
	int l = 0;
	int req = 0;

	for (int i = 0; i < n1; i++) {
		freq1[s1[i]]++;
		freq2[s2[i]]++;
	}

	/* for (int i = 0; i < n1; i++) {
		for (int j = i+1; j < n1; j++) {
			if (s1[i] == s1[j]) {
				f[j] = 0;
			}
		}
		if (f[i]) {
			s3[l++] = s1[i];
		}
	}
	s3[l] = '\0';

	printf("s3 : %s\n", s3);

	for (int i = 0; i < l; i++) {
		if (freq1[s3[i]] > freq2[s3[i]]) {
			req++;
		}
	} */

	/*for (int i = 0; i < 256; i++) {
		if (freq1[i] && (freq1[i] > freq2[i]) ) {
			req++;
		}
	} */

	for (int i = 0; i < n1; i++) {
                if ( freq1[s1[i]] && (freq1[s1[i]] > freq2[s1[i]])) {
                        req++;
			freq1[s1[i]] = 0;
                }
        }
	printf("req : %d\n", req);

	if (req <= k)
	       return 1;
	else
	       return 0;
}



int main () {
	char *s1 = "anagram";
	char *s2 = "grammar";

        //char* s1 = "geeks";
	//char* s2 = "eggkf";
	
	//char* s1 = "fodr";
	//char* s2 = "gork";

	int k = 3;

	if (k_anagrams(s1, s2, k)) {
	       printf("Both strings are anagrams\n");
	}
	else {
	       printf("Both strings are not anagrams\n");
	}

	return 0;
}


