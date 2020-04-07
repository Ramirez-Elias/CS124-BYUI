/***********************************************************************
* Program:
* Assignment 31
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
void getGrades(int grades[], int numGPAs);
int averageGrades(int grades[], int numGPAs);
void display(int average);

/**********************************************************************
 * MAIN
 * Start with Assignment 3.0 and modify the function averageGrades() so
 * that it does not take into account grades with the value -1. In this
 * case, -1 indicates the assignment was not completed yet so it should 
 * not factor in the average.
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
		//Check New Condition
		if (grades[i] < 0)
		{
			//increase counter
			i++;
			//decrease numGPAs
			numGPAs--;
		}
		else
		{
			//Add all grades together
			average += grades[i];
			i++;
		}
	} while (i < 10); // condition

	//before returning, let's check if numGPAs is == 0
	//if so, let's send a negative number to main
	if (numGPAs == 0)
		return average = -1 ;
	else
		//return average
		return average / numGPAs;
}

/**********************************************************************
 * display()
 ***********************************************************************/
void display(int average)
{
	//let's check for average that is negative. if so, then all input
	// was negative and error should be displayed as requested
	if (average < 0)
		cout << "Average Grade: " << "---%\n";
	else
		cout << "Average Grade: " << average << "%\n";
}