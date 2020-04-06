/***********************************************************************
* Program:
* Assignment 23
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream>
using namespace std;

//prototype
int computeValue(int mult);

/**********************************************************************
 * Write a function (computeTax()) to determine which tax bracket a 
 * user is in. 
 ***********************************************************************/
int main()
{
	// Declare variable
	int multiple(0);
	cout << "What multiples are we adding? ";
	cin >> multiple;
	//call function to compute the multiple and assign value to result
	int result = computeValue(multiple);
	//display result
	cout << "The sum of multiples of " << multiple << " less than 100 are: " << result;
	return 0;
}

int computeValue(int multiple)
{
	int result(0);
	//I use 99 instead of 100 as the number should be less than 100
	for(int i = 0; i <= 99 / multiple; i++)
	{	
		//add each multiple to the result
		result += multiple * i;
	} 
	//send result to main
	return result;
}