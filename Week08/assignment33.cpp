/***********************************************************************
* Program:
* Assignment 33
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream>
#include <string>
using namespace std;

void date(float *pAccount);

/**********************************************************************
 * MAIN
 * Write a program to ask two people for their account balance. Then,
 * based on who has the most money, all subsequent purchases will be 
 * charged to his or her account.
 ***********************************************************************/
int main()
{
	//sam's balance declare
	float samBalance(0);
	//sue's balance declare
	float  sueBalance(0);
	//pointer for account
	float * pAccount;
	//ask balance
	cout << "What's Sam's balance? ";
	cin >> samBalance;
	cout << "What's Sue's balance? ";
	cin >> sueBalance;

	//check which balance is higher
	if (sueBalance > samBalance)
	{
		//copy address to pointer
		pAccount = &sueBalance;
		//send pointer to function
		date(pAccount);
	}
	else
	{
		//copy address to pointer
		pAccount = &samBalance;
		//send pointer to function
		date(pAccount);
	}

	//display Balance
	cout << "Sam's balance: " << samBalance << endl;
	cout << "Sue's balance: " << sueBalance << endl;
	
	return 0;
}

/**********************************************************************
 * MAIN
 * This function will contain the three prompts(Dinner, Movie, and Ice
 * Cream) and reduce the value of pAccount by that amount.
 ***********************************************************************/

void date(float *pAccount)
{
	//declare date variables
	float dinner(0);
	float movie(0);
	float iceCream(0);
	// prompt for cost of date
	cout << "Cost of the date:\n";
	//Note that there is a tab before “Dinner,” “Movie,” and 
	//“Ice cream.” There are spaces after the colons.
	cout << "\tDinner:     ";
	cin >> dinner;
	cout << "\tMovie:      ";
	cin >> movie;
	cout << "\tIce Cream:  ";
	cin >> iceCream;

	//add cost together
	float dateCost = dinner + movie + iceCream;

	//substract from account
	*pAccount -= dateCost;
}