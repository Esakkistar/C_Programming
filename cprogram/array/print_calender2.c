#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    }
    return 0; // Not a leap year
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31; // January
        case 2: return isLeapYear(year) ? 29 : 28; // February
        case 3: return 31; // March
        case 4: return 30; // April
        case 5: return 31; // May
        case 6: return 30; // June
        case 7: return 31; // July
        case 8: return 31; // August
        case 9: return 30; // September
        case 10: return 31; // October
        case 11: return 30; // November
        case 12: return 31; // December
    }
    return 0; // Default case (shouldn't happen)
}

// Function to get the starting day of the year
int getStartingDay(int year) {
    // Using Zeller's Congruence to find the day of the week for January 1st
    int d = 1; // Day
    int m = 1; // Month (January)
    /*if (m == 1 || m == 2) {
        m += 12;
        year--;
    }*/
    int K = year % 100; // Year of the century
    int J = year / 100; // Zero-based century
    int h = (d + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) + 5 * J) % 7;
    return (h + 5) % 7; // Converting Zeller's day (0=Saturday) to (0=Sunday)
}

// Function to print the calendar for a given year
void printCalendar(int year) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    const char *days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    int startingDay = getStartingDay(year);
    
    for (int month = 1; month <= 12; month++) {
        int daysInMonth = getDaysInMonth(month, year);
        
        printf("\n  ------------%s-------------\n", months[month - 1]);
        for (int i = 0; i < 7; i++) {
            printf("%s ", days[i]);
        }
        printf("\n");
        
        for (int i = 0; i < startingDay; i++) {
            printf("    ");
        }
        
        for (int day = 1; day <= daysInMonth; day++) {
            printf("%4d", day);
            if (++startingDay > 6) {
                startingDay = 0;
                printf("\n");
            }
        }
        if (startingDay != 0) {
            printf("\n");
        }
    }
}

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    
    printf("\nCalendar for the year %d:\n", year);
    printCalendar(year);
    
    return 0;
}

