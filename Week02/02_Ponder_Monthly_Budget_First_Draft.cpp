/***********************************************************************
* Program:
* Assignment 1.1, Monthly Budget Draft
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
* Hello world on the screen
***********************************************************************/
int main()
{
	// configure the output to display money 
	cout.setf(ios::fixed); // no scientific notation except for the deficit 
	cout.setf(ios::showpoint); // always show the decimal point 
	cout.precision(2); // two decimals for cents; this is not a gas station!
	
	// Display Budget
	cout << "\tItem\t       Projected\n";
	cout << "\t=============  ==========\n";
	cout << "\tIncome\t       $" << setw(9) << 1000.00 << endl;
	cout << "\tTaxes\t       $" << setw(9) << 100.00 << endl;
	cout << "\tTithing\t       $" << setw(9) << 100.00 << endl;
	cout << "\tLiving\t       $" << setw(9) << 650.00 << endl;
	cout << "\tOther\t       $" << setw(9) << 90.00 << endl;
	cout << "\t=============  ==========\n";
	cout << "\tDelta\t       $" << setw(9) << 60.00 << endl;

	return 0;
}