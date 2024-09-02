
/*
 * Longest Common Prefix using Sorting
Last Updated : 24 May, 2024
Problem Statement: Given a set of strings, find the longest common prefix.
Examples:

Input: {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output: “gee”

Input: {“apple”, “ape”, “april”}
Output: “ap”  */

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (char* a, char* b) {
	return ( strlen(a) > strlen(b));
}

void sort_by_length (char** str, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (compare (str[i], str[j]) > 0) {
				char *t;
				t = str[i];
                                str[i] = str[j];
                                str[j] = t;
			}
		}
	}
}

int main () {
	// char* str[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
	char* str[] = {"apple", "ape", "april"};
	int n = sizeof(str) / sizeof(str[0]);

	printf("Strings : ");
	for (int i = 0; i < n; i++) {
		printf("%s ", str[i]);
	}
	printf("\n");

	sort_by_length(str, n);
	
	printf("Sort strings : ");
	for (int i = 0; i < n; i++) {
		printf("%s ", str[i]);
	}
	printf("\n");

	char* t = str[0];

	int cnt = 0, i = 0;
	while (t[i] != '\0') {
		int flag = 0;
                for (int j = 1; j < n; j++) {
			if (t[i] != str[j][i]) 
			     flag = 1;
		}
		if (flag == 0) {
			i++;
			cnt++;
		}
		else
		   break;
	}
	printf("cnt : %d\n", cnt);
	printf("Longest Prefix : ");
        for (int i = 0; i < cnt; i++) {
                printf("%c", t[i]);
        }			
	printf("\n");

	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* commonPrefixUtil(char* str1, char* str2)
{
    char* result = (char*)malloc(100 * sizeof(char));
    int len = strlen(str1) < strlen(str2) ? strlen(str1)
                                          : strlen(str2);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str1[i] != str2[i])
            break;
        result[j++] = str1[i];
    }

    result[j] = '\0';
    return result;
}

char* commonPrefix(char* arr[], int n)
{
    char* prefix = arr[0];

    for (int i = 1; i < n; i++) {
        prefix = commonPrefixUtil(prefix, arr[i]);
    }

    return prefix;
}

int main()
{
    char* arr[]
        = { "geeksforgeeks", "geeks", "geek", "geezer" };
    int n = sizeof(arr) / sizeof(arr[0]);

    char* ans = commonPrefix(arr, n);

    if (strlen(ans))
        printf("The longest common prefix is - %s\n", ans);
    else
        printf("There is no common prefix\n");

    free(ans);

    return 0;
}

