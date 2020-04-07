/***********************************************************************
* Program:
* Assignment 30
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//prototype
void getGrades(int grades[], int numGPAs);
int averageGrades(int grades[], int numGPAs);
void display(int average);

/**********************************************************************
 * MAIN
 * This program will consist of three parts: getGrades(), 
 * averageGrades(), and a driver program.
 * Please note that for this assignment, integers should be used 
 * throughout.
 ***********************************************************************/
int main()
{
	int grades[10];
	getGrades(grades, 10);
	int average = averageGrades(grades, 10);
	display(average);

	return 0;
}

/**********************************************************************
 * getGrades()
 * Write a function to prompt the user for ten grades and return the 
 * result back to main(). Note that any variables declared in 
 * getGrades() will be destroyed when the function returns. This means
 * that main() will need to declare the array and pass it as a 
 * parameter to getGrades().
 ***********************************************************************/
void getGrades(int grades[], int numGPAs)
{
	//counter
	int i(0);
	//While loop to get info
	do
	{
		//Ask for grades
		cout << "Grade " << i + 1 << ": ";
		cin >> grades[i]; // assign value to array
		i++;
	} while (i < 10); // condition
}

 /**********************************************************************
  * averageGrades()
  * Write another function to find the average of the grades and return
  * the answer. Of course, the grades array will need to be passed as a
  * parameter. The return value should be the average.
  ***********************************************************************/
int  averageGrades(int grades[], int numGPAs)
{
	//Average Variable
	int average(0);
	//counter
	int i(0);
	//While loop to add values together
	do
	{
		//Add all grades together
		average += grades[i]; 
		i++;
	} while (i < 10); // condition

	//return average
	return average / numGPAs;
}

/**********************************************************************
 * display()
 ***********************************************************************/
void display(int average)
{
	cout << "Average Grade: " << average << "%\n";
}