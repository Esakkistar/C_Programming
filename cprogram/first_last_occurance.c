#include <stdio.h>
#include <string.h>

void findFirstAndLastOccurrence(char* str, char ch, int* first, int* last) {
    *first = -1;
    *last = -1;

    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == ch) {
            if (*first == -1) {
                *first = i; // Record the first occurrence
            }
            *last = i; // Update the last occurrence
        }
    }
}

void removespaces (char* str){
	int c = 0;

	for (int i = 0; i < strlen(str); i++){
		if (str[i] != ' ' ){
			str[c++] = str[i];
		}
	}
	str[c] = '\0';
}

int main() {
    char str[256];
    char ch;
    int first, last;

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the trailing newline character

    printf("Enter the character to find: ");
    scanf("%c", &ch);

    findFirstAndLastOccurrence(str, ch, &first, &last);

    if (first != -1) {
        printf("First occurrence of '%c': %d\n", ch, first);
        printf("Last occurrence of '%c': %d\n", ch, last);
    } else {
        printf("Character '%c' not found in the string.\n", ch);
    }

    removespaces(str);
    printf("String without spaces: %s\n",str);

    return 0;
}

