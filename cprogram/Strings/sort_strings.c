#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Name {
    char s[20];
    char **s2;
} N;

int compare(const void* a, const void *b) {
    return  (*(char*)a - *(char*)b);
}
int compare_string(const void* a, const void *b) {
    return   strcmp(*(char**)a, *(char**)b);
}
int main() {
    
    N n1;
    printf("Enter the string : ");
    scanf(" %[^\n]%*c", n1.s);
    
    qsort(n1.s, strlen(n1.s), sizeof(char), compare);
    printf("Sort string : %s\n", n1.s);
    
    n1.s2 = (char**) malloc(5 * sizeof(char*));
    for (int i = 0; i < 5; i++) {
        n1.s2[i] = (char*) malloc(10* sizeof(char));
        scanf("%s", n1.s2[i]);
    }
    
    qsort(n1.s2, 5, sizeof(char*), compare_string);
    for (int i = 0; i < 5; i++) {
        printf("%s ", n1.s2[i]);
	free(n1.s2[i]);
    }
    free(n1.s2);
    printf("\n");
    return 0;
}
   

