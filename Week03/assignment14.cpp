/***********************************************************************
* Program:
* Assignment 13, Temperarture Conversion
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream> 
#include <iomanip> // we will use setw() in this example
using namespace std;

//Prototype each of the functions used in main
void questionPeter(); // As this function does not return any value
                      // I used a void type function
int responseLord(); // As this return an interger, I used an int

/********************************************************************** 
* Main will not do much here. First it will display Peter's question, 
* then it will display the Lord's answer 
***********************************************************************/
int main() { 
	// ask Peter's question 
	questionPeter(); 

	// the first part of the Lord's response 
	cout << "Jesus saith unto him, I say not unto thee, Until seven\n"; 
	cout << "times: but, Until " << responseLord() << ".\n"; 

	return 0; 
}

void questionPeter()
{
	// simple output function
	cout << "Lord, how oft shall my brother sin against me, and I forgive him?\n"
	     <<"Till seven times?\n";

}
int responseLord()
{
	// simple response. I declare the response as an int, and then return it to main
	int response = 7 * 70;
	return response;
}