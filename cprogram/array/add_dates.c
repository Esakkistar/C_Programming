#include <stdio.h>
#include <stdlib.h>

typedef struct Date {
	int day;
	int month;
	int year;
} D;

int Isleapyear(int y) {

	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
		return 1;
	}
	return 0;
}

int daysInmonth(int m, int year) {
	int mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (m == 2 && Isleapyear(year)) {
		return 29;
	}

	return mon[m-1];
}

int NumberOfDays(D d1, D d2) { 

	int days1 = d1.day + (d1.month-1) * daysInmonth(d1.month, d1.year) + d1.year * 365;
	int days2 = d2.day + (d2.month-1) * daysInmonth(d2.month, d2.year) + d2.year * 365;

	int diff = abs (days1 - days2);
	//int diff = days2 - days1;

	return diff;
}

int main () {
	D date1, date2;

	printf("Enter Date 1 : (day month year) : ");
	scanf("%d%d%d", &date1.day, &date1.month, &date1.year);
	
	printf("Enter Date 2 : (day month year) : ");
	scanf("%d%d%d", &date2.day, &date2.month, &date2.year);

	int days = NumberOfDays(date1, date2);

	printf("No.of Days between %02d:%02d:%d - %02d:%02d:%d : %d\n", date1.day, date1.month, date1.year, date2.day, date2.month, date2.year, days);

	return 0;
}

	 


