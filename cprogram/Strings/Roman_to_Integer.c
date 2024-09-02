#include <stdio.h>
#include <string.h>
#include <ctype.h>

int roman_to_integer (char ch) {
	char symbol[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int sym_count = sizeof(symbol) / sizeof(symbol[0]);
	int num[] = {1, 5, 10, 50, 100, 500, 1000};

	ch = toupper(ch);
	int i;
	for (i = 0; i < sym_count; i++) {
		if (ch == symbol[i])
			return num[i];
	}
	return -1;
}


int main () {
	char roman[10];
	printf("Enter the Romam Number : ");
	scanf(" %[^\n]%*c", roman);

	int len = strlen(roman);

	if (len == 1) {
		printf("Roman to Integer %s : %d\n", roman, roman_to_integer(roman[0]));
		return 0;
	}

	int total = 0;
	int value = 0, prev_value = 0;

	for (int i = len-1; i >= 0; i--) {
		int value = roman_to_integer(roman[i]);
		if ( value >= prev_value)
		       total += value;
		else
		       total -= value;

		/* if ( value < prev_value)
                       total -= value;
                else
                       total += value; */
		
		prev_value = value;
	}

	printf("Roman to Integer %s : %d\n", roman, total);
        
	return 0;
}





