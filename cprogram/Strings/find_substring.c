#include <stdio.h>
#include <string.h>

int main() {
    char txt[] = "GEEKSFORGEEKS";
    char pat[] = "GEEKS";
    int n1 = strlen(txt);
    int n2 = strlen(pat);
    
    for (int i = 0; txt[i] != '\0'; i++) {
        int k = 0;
        for (int j = i; j < i+n2; j++) {
            if (txt[j] == pat[k]) {
                k++;
            }
        }
        if (k == n2) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    for (int i = 0; i <= n1-n2; i++) {
        char t[20];
        strncpy(t, txt+i, n2);
	printf("%s\n", t);
        if (strcmp(t, pat) == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    for (int i = 0; i < n1; i++) {
	    for (int j = i; j < n1; j++) {
		char t[20];
        	strncpy(t, txt+i, j-i+1);
		t[j-i+1] = '\0';
		printf("%s\n", t);
	    }
    }

    return 0;
}
