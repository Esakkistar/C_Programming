#include <stdio.h>
#include <string.h>

void intToRoman(int num, char *result) {
    // Define arrays for Roman numeral symbols and their corresponding num
    const char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int len = sizeof(roman) / sizeof(roman[0]);
    const int integers[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    result[0] = '\0'; 

    for (int i = 0; i < len; i++) {
        while (num >= integers[i]) {
            strcat(result, roman[i]); 
            num -= integers[i]; 
        }
    }
}

int main() {
    char result[100];
    
    int N;
    printf("Enter the Number : ");
    scanf("%d", &N);  

    intToRoman(N, result);
    printf("Integer to Roman : %d - %s\n", N, result);

    return 0;
}

