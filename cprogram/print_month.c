#include <stdio.h>
#include <string.h>

int IsleapYear(int y) {
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
		return 1;

	return 0;
}

int getDaysInMonth(int m, int y) {
	int mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

	if (m == 2 && IsleapYear(y)) return 29;

	return mon[m-1];
}

int getStartingDay(int m, int year ) {
	int d = 1;
	if (m == 1 || m == 2) {
		m += 12;
		year--;
	}

	int k = year % 100;
	int j = year / 100;
	int h = (d + (13 * (m+1)) / 5 + k + (k/4) + (j/4) + 5*j) % 7;

	return (h+6) % 7;
}
void print_calender(int m, int year) {
	char* months[] = {"January", "February", "March", "April", "May", "June",
        		  "July", "August", "September", "October", "November", "December" };

	char *days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	int startingDay = getStartingDay(m,year);

	int DaysInMonth = getDaysInMonth(m, year);

	printf("---------- %s ---------\n", months[m-1]);
	for (int i = 0; i < 7; i++) {
		printf(" %s", days[i]);
	}
	printf("\n");

	for (int i = 0; i < startingDay; i++) {
		printf("    ");
	}
	for (int i = 1; i <= DaysInMonth; i++) {
		printf("%4d",i);
		if (++startingDay > 6) {
			startingDay = 0;
			printf("\n");
		}
	}

	if (startingDay != 0) {
		printf("\n");
	}
}


int main () {
	int year, mon;
	printf("Enter the year : ");
	scanf("%d", &year);
	printf("Enter the month : ");
	scanf("%d", &mon);

	print_calender(mon,year);

	return 0;
}
