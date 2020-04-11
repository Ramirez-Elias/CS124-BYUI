/***********************************************************************
* Program:
* Assignment 41
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream>
#include <cassert>

using namespace std;

//prototype
void getNumber(int &number);
void getText(char text[], int number);
void displayText(char text[], int number);

/**********************************************************************
 * MAIN
 * Write a program to:
 * Prompt the user for the number of characters in a string
 * - Allocate a string of sufficient length (one more than # of 
 *   characters!)
 * - Prompt the user for the string using getline
 * - Display the string back to the user
 * - Don’t forget to release the memory and check for allocation failures!
 * Note that since the first cin will leave the stream pointer on the 
 * newline character, you will need to use cin.ignore() before getline()
 * to properly fetch the section input.
 ***********************************************************************/
int main()
{
	//prompt for the number of characters in a string
	int number(0);
	getNumber(number);
	
	//Allocate a string of sufficient length (one more than # of 
	//characters!)
	number++;
	
	//check for allocation Failures
		//Nothrow constant
		//This is from cplusplus.com about nothrow: 
		//is used as an argument for operator new and operator new[] to indicate
		//that these functions shall not throw an exception on failure, but return
		//a null pointer instead.
	char * text = new(nothrow) char[number]; 
	if (!text)
	{
		cout << "Allocation failure!\n";
		return 0; // otherwise it will throw an exception on failure
	}

	//Prompt the user for the string using getline
	getText(text, number);
	
	//Display the string back to the user
	displayText(text, number);

	//delete
	delete[] text;

	return 0;
}

/**********************************************************************
 * getNumber(int &number)
************************************************************************/
void getNumber(int &number)
{
	cout << "Number of characters: ";
	cin >> number;
}

/**********************************************************************
 * getText(char text[], int number)
************************************************************************/
void getText(char text[], int number)
{
	cout << "Enter Text: ";
	cin.ignore();
	cin.getline(text, number);
}

/**********************************************************************
 *  displayText(char text[], int number)
************************************************************************/
void displayText(char text[], int number)
{
	cout << "Text: ";
	for (int i(0); i < number; i++)
		cout << text[i];

}