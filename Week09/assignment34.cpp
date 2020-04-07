/***********************************************************************
* Program:
* Assignment 34
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
int countLetters(char * text, char letter);

/**********************************************************************
 * MAIN
 * Start with Assignment 3.2. Modify countLetters() so that it walks
 * through the string using pointers instead of array indexes. The
 * output should be exactly the same as with Assignment 3.2.
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
	int letterCount = countLetters(text, letter);
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
int countLetters(char * text, char letter)
{
	//letter count variable
	int letterCount(0);
	//for loop to iterate
	for ( char * p = text; *p; p++)
	{
		//letter comparisson
		if (letter == * p)
		{
			letterCount++;
		}
	}
	//return number of letters
	return letterCount;
}
