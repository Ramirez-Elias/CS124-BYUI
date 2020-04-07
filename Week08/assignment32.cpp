/***********************************************************************
* Program:
* Assignment 32
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream>
#include <string>
using namespace std;

//prototype
int countLetters(char text[], int size, char letter);

/**********************************************************************
 * MAIN
 * Traversing a string (or any other type of array for that matter) is
 * a common programming task. This assignment is the first part in a 
 * two-part series (the other is Assignment 3.5) where we will learn 
 * different techniques for visiting every member of a string. Your 
 * assignment is to write the function countLetters() then a driver 
 * program to test it.
 ***********************************************************************/
int main()
{
	char text[256];
	char letter;
	//Create a main() that prompts the user for a line of input 
	//(using getline), 
	cout << "Enter a letter: ";
	cin >> letter; 
	cout << "Enter text: ";
	//Note that since the first cin will leave the stream pointer on the
	//newline character, you will need to use cin.ignore() before getline()
	//to properly fetch the section input.
	cin.ignore();
	cin.getline(text, 256);
	//calls countLetters() 
	int letterCount = countLetters(text, 256, letter);
	//and displays the number of letters.
	cout << "Number of \'" << letter << "\'s: " << letterCount << endl;

	return 0;
}

/**********************************************************************
 * countLetters()
 * Write a function to return the number of letters in a string. This
 * involves traversing the string using the array notation (with an 
 * index as we have been doing all semester). We will re-write this 
 * function in Assignment 3.5 to do the same thing using a pointer.
 ***********************************************************************/
int countLetters(char text[], int size, char letter)
{
	//letter count variable
	int letterCount(0);
	//for loop to iterate
	for (int i = 0; text[i]; i++)
	{
		//letter comparisson
		if (letter == text[i])
		{
			letterCount++;
		}
	}
	//return number of letters
	return letterCount;
}
