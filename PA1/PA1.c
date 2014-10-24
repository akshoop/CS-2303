/*
*	Project Assignment 1 - Calendar
*	By Alex Shoop
*	For CS2303 due 9/6/13
*
*	Sources so far: Lukas friend, Loop Invariants prof lauer slide, leap year example from text p.41
*					Zeller's Algorithm code from Wikipedia
*/

#include <stdio.h>
#include <stdlib.h>

int inputYear;
int monthNumber, dateNumber;
int startingDay;
int dayOfWeek;

// finds the number of days in a given month
int findDaysInMonth(int m) {
	
	// switch to return number of days from given month number
	switch (m) {
		case 0 : return 31;
					break;
		case 1 :  {
		// checks if inputYear is leap year or not. 
		// If yes then February has 29 days, if not then 28 days
			if (inputYear % 400 == 0 || (inputYear % 4 == 0 && inputYear % 100 != 0)) {
				return 29;
				break;
			}
			else {
				return 28;
				break;
			}
		} // if inputYear 
		case 2 : return 31;
					break;
		case 3 : return 30;
					break;
		case 4 : return 31;
					break;
		case 5 : return 30;
					break;
		case 6 : return 31;
					break;
		case 7 : return 31;
					break;
		case 8 : return 30;
					break;
		case 9 : return 31;
					break;
		case 10 : return 30;
					break;
		case 11 : return 31;
					break;
	} // switch m
	return m;
} // int findDaysInMonth

// finds the starting day (ie. January 1) of a given year. the algorithm is based off of Zeller's Algorithm.
int findStartingDay(int y) {
	int K = (y - 1) % 100;
	int J = (y - 1)/100;
	int R = (13*(13+1))/5 + K + K/4 + J/4 - 2*J + 1;
	int z = R % 7;
	int d = ((z + 6) % 7);
	return d;
} // int findStartingDay

int main(void) 
{
	// prints the program header
	printf("\t\t\tMONTHLY CALENDAR\n\n");
	
	// asks user for non-negative year number
	printf("Please enter a non-negative year: ");
	scanf("%d", &inputYear);
	printf("\n\n");
	
	// if inputYear is a negative number or is 0, then program exits
	if (inputYear <= 0) {
		exit(0);
	} // if inputYear
	
	// prints inputYear 3 tabs towards the right
	printf("  ***    CALENDAR for %d    ***  \n\n", inputYear);
	
	// finds startingDay from inputYear
	startingDay = findStartingDay(inputYear);
	
	// primary for loop to execute month loop
	for (monthNumber = 0; monthNumber < 12; ++monthNumber) {
		// a determined number of days for a month
		const int daysInMonth = findDaysInMonth(monthNumber);
		
		// switch to print month name from the month number
		switch (monthNumber) {
			case 0 : 	printf("January %d\n\n", inputYear);
						break;
			case 1 : 	printf("February %d\n\n", inputYear);
						break;
			case 2 : 	printf("March %d\n\n", inputYear);
						break;
			case 3 : 	printf("April %d\n\n", inputYear);
						break;
			case 4 : 	printf("May %d\n\n", inputYear);
						break;
			case 5 : 	printf("June %d\n\n", inputYear);
						break;
			case 6 : 	printf("July %d\n\n", inputYear);
						break;
			case 7 : 	printf("August %d\n\n", inputYear);
						break;
			case 8 : 	printf("September %d\n\n", inputYear);
						break;
			case 9 : 	printf("October %d\n\n", inputYear);
						break;
			case 10 : 	printf("November %d\n\n", inputYear);
						break;
			case 11 : 	printf("December %d\n\n", inputYear);
						break;
		} // switch month
		
		// prints the days of the week
		printf("%5s%5s%5s%5s%5s%5s%6s", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat\n");
		
		// for loop that prints a blank space if dayOfWeek number is less than startingDay number
		for (dayOfWeek = 0; dayOfWeek < startingDay; dayOfWeek++) {
			printf("%5s", "");
		} // for dayOfWeek
		
		// for loop that prints the date number
		for (dateNumber = 1; dateNumber <= daysInMonth; ++dateNumber) {
			printf("%5d", dateNumber);
			// checks if ++dayOfWeek is less than 6 (ie. either a day before Sat or Sat) 
			// and also checks if the date number does not equal daysInMonth.
			// If these conditions are met, then print a new line and set dayOfWeek to 0 (ie. Sun)
			if (++dayOfWeek > 6 && dateNumber != daysInMonth) {
				printf("\n");
				dayOfWeek = 0;
			} // if ++dayOfWeek
		} // for date
		
		// sets startingDay of next month to the previous month's dayOfWeek + 1 and makes sure
		// it doesn't fall on a invalid day
		startingDay = dayOfWeek++ % 7;
		
		printf("\n\n");
	} // for month
	return 0;
}	//int main(void)
