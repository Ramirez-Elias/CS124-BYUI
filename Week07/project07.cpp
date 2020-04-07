/***********************************************************************
* Program:
* Project 7, Calendar 
* Brother Helfrich, CS124
* Elias Ramirez
* Summary:
* Create a calendar for any month of any year from 1753 forward. This 
* is similar to the cal utility on the Linux system. Prompt the user 
* for the numeric month and year to be displayed as shown in the example
* below. Your calculations to determine the first day of the month shall
* start with January 1, 1753 as a Monday. The challenge here is to take
* into account leap years.
************************************************************************/
#include <iostream> 
#include <iomanip> 
#include <string>
using namespace std;
int getMonth();
bool validateMonth(int month); //for error handling
int getYear();
bool validateYear(int year);//for error handling
bool isLeapYear(int year);
int computeOffset(int month, int year);
int getNumDays(int month, int year);
string getMonthName(int month);
void displayHeader(int month, int year);
void displayTable(int numDays, int offset);
int getMonthDays(int month, int year);

/**********************************************************************
 * MAIN
 ***********************************************************************/
int main()
{
	//Month is declared and function call
	int month = getMonth();
	//Year is declared and function call
	int year = getYear();
	//Find number of days in a month
	int numDays = getMonthDays(month, year);
	//Display hearder function call
	displayHeader(month, year);
	//Find our offset	
	int offset = computeOffset(month, year);
	//Display Calendar	
	displayTable(numDays, offset);
	
	return 0;
}

/**********************************************************************
 * getMonth()
 ***********************************************************************/
int getMonth()
{
	//simple get function, use a while loop to keep asking questions
	int month(0);
	do
	{
		cout << "Enter a month number: ";
		cin >> month;
	}
	while (!validateMonth(month));

	return month;
}

/**********************************************************************
 * validateMonth(int month)
 ***********************************************************************/
bool validateMonth(int month)
{
	//boolean function to find out if data is within parameters
	if (month <= 0 || month > 12)
	{
		//error message
		cout << "Month must be between 1 and 12.\n";
		return 0;
	}
	//return true if within range
	return 1;
}

/**********************************************************************
 * getYear()
 ***********************************************************************/
int getYear()
{
	//simple get function, use a while loop to keep asking questions
	int year(0);
	do
	{
		cout << "Enter year: ";
		cin >> year;
	} while (!validateYear(year));

	return year;
}

/**********************************************************************
 * validateYear(int year)
 ***********************************************************************/
bool validateYear(int year)
{
	//boolean function to find out if data is within parameters
	if (year < 1753)
	{
		//error message
		cout << "Year must be 1753 or later.\n";
		return 0;
	}
	//return true if within range
	return 1;
}

/**********************************************************************
 * isLeapYear()
 * pseudocode from a wiki article:
 * if (year is not divisible by 4) then (it is a common year)
 * else if (year is not divisible by 100) then (it is a leap year)
 * else if (year is not divisible by 400) then (it is a common year)
 * else (it is a leap year)
 ***********************************************************************/
bool isLeapYear(int year)
{
	//if (year is not divisible by 4) then (it is a common year)
	if (year % 4 != 0)
		return 0;
	//else if (year is not divisible by 100) then (it is a leap year)
	else if (year % 100 != 0)
		return 1;
	//else if (year is not divisible by 400) then (it is a common year)
	else if (year % 400 != 0)
		return 0;
	//else (it is a leap year)
	else
		return 1;
}

/**********************************************************************
 * computeOffset()
 * This function will determine the day of the week of the first day of
 *  the month by counting how many days have passed since the 1st of 
 * January, 1753 (which is a Monday and offset == 0). That number 
 * (numDays) divided by 7 will tell us how many weeks have passed. The 
 * remainder will tell us the offset from Monday. For example, if the 
 * month begins on a Thursday, then offset == 3.
 ***********************************************************************/
int computeOffset(int month, int year)
{
	//Variable to contain days passed since 1753
	int days = getNumDays(month, year);

	//Let's calculate the offset
	int offset = days % 7;
	
	return offset;
}

/**********************************************************************
 * getNumDays
 ***********************************************************************/
int getNumDays(int month, int year)
{
	int numDays(0);
	//I'll divide the task into two, first count the days that have
    //passed each years, and then the amount of days for the selected year 
	//This for loop will take care of the years
	for (int i = 1753; i < year; i++)
	{
		//check if leap year, if so then adds 366 days
		if (isLeapYear(i))
		{
			numDays += 366;
		}
		//else it adds regular 365 days
		else
			numDays += 365;
	}

	//Now, let's add the days passed in each month
	//I added a switch statement to add each specific days on each month
	switch (month)
	{
	case 1:
		numDays += 0;
		break;
	case 2:
		numDays += 31;
		break;
	case 3:
		numDays += 59;
		break;
	case 4:
		numDays += 90;
		break;
	case 5:
		numDays += 120;
		break;
	case 6:
		numDays += 151;
		break;
	case 7:
		numDays += 181;
		break;
	case 8:
		numDays += 212;
		break;
	case 9:
		numDays += 243;
		break;
	case 10:
		numDays += 273;
		break;
	case 11:
		numDays += 304;
		break;
	default:
		numDays += 334;
		break;
	}

	//add an additional day if leap year
	if (isLeapYear(year) && month > 2)
		numDays += 1;
	return numDays;
}

/**********************************************************************
 * displayHeader(int month, int year)
 ***********************************************************************/
void displayHeader(int month, int year)
{
	//space
	cout << endl;
	//string declared and Function to get month name is called
	string monthName = getMonthName(month);
	//Display Header
	cout << monthName << ", " << year << endl;
	cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
}

/**********************************************************************
 * getMonthName(int month)
 ***********************************************************************/
string getMonthName(int month)
{
	//Variable declared
	string monthName = "";
	//get Month Name
	switch (month)
	{
	case 1:
		monthName = "January";
		break;
	case 2:
		monthName = "February";
		break;
	case 3:
		monthName = "March";
		break;
	case 4:
		monthName = "April";
		break;
	case 5:
		monthName = "May";
		break;
	case 6:
		monthName = "June";
		break;
	case 7:
		monthName = "July";
		break;
	case 8:
		monthName = "August";
		break;
	case 9:
		monthName = "September";
		break;
	case 10:
		monthName = "October";
		break;
	case 11:
		monthName = "November";
		break;
	default:
		monthName = "December";
		break;
	}
	return monthName;
}

/**********************************************************************
 * displayTable(int numDays, int offset)
 ***********************************************************************/
void displayTable(int numDays, int offset)
{
	//This variable will contain the number of spaces needed to start
	//placing the days
	int spaces(0);
	
	//An if statement will help find out where to start
	//if 6, then start under Sunday and so on
	if (offset == 6)
		spaces = 4;
	else if (offset == 0)
		spaces = 8;
	else if (offset == 1)
		spaces = 12;
	else if (offset == 2)
		spaces = 16;
	else if (offset == 3)
		spaces = 20;
	else if (offset == 4)
		spaces = 24;
	else 
		spaces = 28;
	//this limit variable will help with the limit for each line
	//as the lines are 28 spaces long, if anything is longer than
	//28, then a new line will be needed
	int limit = spaces;
	
	for (int i = 1; i <= numDays; i++)
	{
		//This is pretty much what puts data on the screen
		cout << setw(spaces) << i;
		//After printing data, I add the amount of space to limit
		limit += spaces = 4;
		//If limit is above 28, is out of range, then it should be 
		//"reset" to 4
		if (limit > 28)
		{
			cout << endl;
			limit = 4;
		}
	}
	//I added this to make it more readable
	cout << endl;
}

/**********************************************************************
 * getMonthDays(int month, int year)
 ***********************************************************************/
int getMonthDays(int month, int year)
{
	//if month is february, then check if leap year
	if (month == 2) 
	{
		//if leap, return 29
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	//if any of the months with 30 days, then return 30
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	//everything else
	else
		return 31;		
}
