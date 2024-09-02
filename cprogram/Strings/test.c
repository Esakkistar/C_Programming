#include <stdio.h>
#include <string.h>

int main() {
    char s[20];
    memset(s,'0', sizeof(char)*7);
    printf("%s\n", s);

    int n = 6;
    for (int i = 0; i < n; i++) {
	    if (i != n-1) {
		    printf("-");
	    }
	    printf("%d", i);
    }
    printf("\n");

    return 0;
}
