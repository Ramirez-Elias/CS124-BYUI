/***********************************************************************
* Program:
* Project 6, Calendar Program
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
using namespace std;
int getMonth();
bool validateMonth(int month); //for error handling
int getYear();
bool validateYear(int year);//for error handling
bool isLeapYear(int year);
int computeOffset(int month, int year);
void displayHeader();
void displayTable();

/**********************************************************************
 * MAIN
 ***********************************************************************/
int main()
{

		int month = getMonth();
		int year = getYear();
		int offset = computeOffset(month, year);
		cout << "Offset: " << offset << endl;
	return 0;
}

int getMonth()
{
	int month(0);
	do
	{
		cout << "Enter a month number: ";
		cin >> month;
	}
	while (!validateMonth(month));

	return month;
}
bool validateMonth(int month)
{
	if (month <= 0 || month > 12)
	{
		cout << "Month must be between 1 and 12.\n";
		return 0;
	}
	return 1;
}

int getYear()
{
	int year(0);
	do
	{
		cout << "Enter year: ";
		cin >> year;
	} while (!validateYear(year));

	return year;
}
bool validateYear(int year)
{
	if (year < 1753)
	{
		cout << "Year must be 1753 or later.\n";
		return 0;
	}
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
	int offset(0);
	//Variable to contain days passed since 1753
	int days(0);
	
	//I'll divide the task into two, first count the days that have
	//passed each years, and then the amount of days for the selected year 

	//This for loop will take care of the years
	for (int i = 1753; i < year; i++)
	{
		//check if leap year, if so then adds 366 days
		if (isLeapYear(i))
		{
			days += 366;
		}
		//else it adds regular 365 days
		else
			days += 365;
	}

	//Now, let's add the days passed in each month
	//I added a switch statement to add each specific days on each month
	switch (month)
	{
	case 1:
		days += 0;
		break;
	case 2:
		days += 31;
		break;
	case 3:
		days += 59;
		break;
	case 4:
		days += 90;
		break;
	case 5:
		days += 120;
		break;
	case 6:
		days += 151;
		break;
	case 7:
		days += 181;
		break;
	case 8:
		days += 212;
		break;
	case 9:
		days += 243;
		break;
	case 10:
		days += 273;
		break;
	case 11:
		days += 304;
		break;
	default:
		days += 334;
		break;
	}
	
	//add an additional day if leap year
	if (isLeapYear(year) && month > 2)
		days += 1;

	//Let's calculate the offset
	offset = days % 7;
	
	return offset;
}
void displayHeader()
{

}

void displayTable()
{

}