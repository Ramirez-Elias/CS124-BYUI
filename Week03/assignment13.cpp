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

/**********************************************************************
* Write a program to convert Fahrenheit to Celsius. This program will 
* prompt the user for the Fahrenheit number and convert it to Celsius.
* The equation is: C = 5/9(F – 32)
***********************************************************************/
int main()
{
	//temperature variable declare. As Expressions (division and 
	// multiplication) will results in decimals, a float is used
	float temp(0); //This is one way to initialize a variable (giving 
	                 //it a value). You can also do float temp = 0;
	
	// Ask for temp in Fahrenheit
	cout << "Please enter Fahrenheit  degrees: ";

	//cin will assign the value inputed by user to income
	cin >> temp;

	//The expression to be evaluated is this C = 5/9(F – 32)
	//Instead of an int, I'll use a float and "cast" the result
	float cTemp(0);

	//this portion gave me a 0 at first, but it was because instead
	//of dividing 5.0/9.0 -float divisio- I was dividing 5/9 -int 
	//division- which results in 0
	cTemp = (temp - 32) * (5.0/9.0);
	
	//Display converted temperature. Cast result from float to int
	cout << "Celsius: " << (int)cTemp << endl;

	return 0;
}