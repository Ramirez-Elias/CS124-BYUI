/***********************************************************************
* Program:
* Assignment 15
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream>
using namespace std;

// prototypes
bool isFullTithePayer(float income, float tithe);

/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
	float income;
	float tithe;

	// prompt user for income
	cout << "Income: ";
	cin >> income;

	// prompt user for tithe
	cout << "Tithe: ";
	cin >> tithe;

	// give the user his tithing report
	if (isFullTithePayer(income, tithe))
		cout << "You are a full tithe payer.\n";
	else
		cout << "Will a man rob God?  Yet ye have robbed me.\n"
		<< "But ye say, Wherein have we robbed thee?\n"
		<< "In tithes and offerings.  Malachi 3:8\n";

	return 0;
}

/*****************************************************
 * CALCULATE THE PERCENTAGE PAID IN TITHES
 * As I was looking for the content of this assignment
 * I came accross this result, which makes sense.
 * here the bool variable is evaluating the statement
 * is the value in tithe larger than the value of 
 * Income divided by 10. If it is, then the result
 * would be true. If not, then the result would be false
 *****************************************************/
bool isFullTithePayer(float income, float tithe)
{

	bool percentTithe((float)(tithe >= income / 10));

	return percentTithe;

}