/***********************************************************************
* Program:
* Assignment 16
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream>
using namespace std;

// prototype
int computeTax(int income);

/**********************************************************************
 * Write a function (computeTax()) to determine which tax bracket a 
 * user is in. 
 ***********************************************************************/
int main()
{
	// income declare as int
	int income(0);

	//ask for income
	cout << " Income: ";
	
	//assign value to income
	cin >> income;

	//declare taxBrake varible and assign value from computeTax function
	int taxBrake = computeTax(income);

	//display tax bracket
	cout << "Your tax bracket is: " << taxBrake << "%\n";
	   	
	return 0;
}

/**********************************************************************
 *computeTax()
 * The yearly income is passed as a parameter to the function.
 * The function returns the percentage bracket that the user's income 
 * falls in. The return value from the function will be an integer (10,
 * 15, 25, 28, 33, or 35).
 ***********************************************************************/
 
int computeTax(int income)
{
	//variable declare
	int tax(0);

	//As this class is to learn about if statement, below is the rationale
	//behind finding the right tax brake
	
	//for the first tax bracket, anything below 15100 is taxed at 10, thus 
	//returning a 10 to main
	if (income <= 15100)
		return tax = 10;
	else if (income >15100 && income <= 61300) //anything above 15100 and 
											   //below or equal to 61300
		return tax = 15;                       //is taxed at 15% and so on
	else if (income > 61300 && income <= 123700)
		return tax = 25;
	else if (income > 123700 && income <= 188450)
		return tax = 28;
	else if (income > 188450 && income <= 336550)
		return tax = 33;
	else // if anything is above any of these, then is taxed at 35%
	return tax = 35;
}