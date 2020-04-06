/***********************************************************************
* Program:
* Assignment 26
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
void getFileName(char fileName[]);
float readFile(char fileName[]);
void display(float average);

/**********************************************************************
 * MAIN
 * Please write a program to read 10 grades from a file and display 
 * the average. This will include the functions getFileName(), 
 * displayAverage() and readFile():
 ***********************************************************************/
int main()
{
	//filename declared
	char fileName[256];
	//get filename
	getFileName(fileName);
	//average declared. Readfile called
	float average = readFile(fileName);
	//display average
	display(average);
	
	return 0;
}


void getFileName(char fileName[])
{
	//simple function
	cout << "Please enter the filename: ";
	cin >> fileName;	
}

float readFile(char fileName[])
{
	//decalre average variable 
	float average(0);
	//declare counter (to see if more than 10 values)
	int counter(0);

	// open the file for reading
	ifstream fin(fileName);
	// check for errors
	if (fin.fail())                      
	{
		// inform user of the error
		cout << "Error reading file \""  
			<< fileName << "\""
			<< endl;
		return false;                     
	}

	//While loop to read through file with eof
	while (!fin.eof())
	{
		//local variable that will hold information from file
		float holder(0);
		//read each value
		fin >> holder;
		//add each value to average
		average += holder;
		//increase counter
		counter++;
		//check if values are higher than 10
		if (counter > 10)
		{
			// inform user of the error
			cout << "Error: more than 10 values found in file \""  
				<< fileName << "\""
				<< endl;
			return false;
		}
	} 
	//close file
	fin.close();

	//return average
	return average /counter;
}

void display(float average)
{
	cout.setf(ios::fixed); // no scientific notation
	cout.precision(0); // no decimals
	cout << "Average Grade: " << average << "%\n";
}