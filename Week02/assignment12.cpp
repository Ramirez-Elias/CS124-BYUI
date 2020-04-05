/***********************************************************************
* Program:
* Assignment 12, Input / output?
* Brother Helfrich, CS124
* Author:
* Sam Student
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream> 
#include <iomanip> // we will use setw() in this example
using namespace std;

/**********************************************************************
* Write a program that prompts the user for his or her income and 
* displays the result on the screen. There will be two parts:
***********************************************************************/
int main()
{
	// configure the output to display money 
	cout.setf(ios::fixed); // no scientific notation except for the deficit 
	cout.setf(ios::showpoint); // always show the decimal point 
	cout.precision(2); // two decimals for cents; this is not a gas station!
	
	//income variable declare. As income contains decimals, a float is needed
	float income(0); //This is one way to initialize a variable (giving 
	                 //it a value). You can also do float income = 0;
	
	// Ask for income
	cout << "\tYour monthly income: ";

	//cin will assign the value inputed by user to income
	cin >> income;

	//Cout will display the income. setw(9) is used to fullfill this portion
	//of the assignemnt: The money is right aligned to 9 spaces from the dollar sign.
	cout << "Your income is: $" << setw(9) << income << endl;

	return 0;
}