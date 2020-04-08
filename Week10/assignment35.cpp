/***********************************************************************
* Program:
* Assignment 35
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
char computeLetterGrade(int gradeNum);
char computeGradeSign(int gradeNum);
/**********************************************************************
 * MAIN
 * The purpose of this assignment is to demonstrate switch statements 
 * and conditional operators. Though of course it is possible to 
 * complete this assignment without using either, it will defeat its 
 * purpose. Your assignment is to write two functions 
 * (computeLetterGrade() and computeGradeSign()) and a single driver 
 * program to test them.
 ***********************************************************************/
int main()
{
	//Create a main() that prompts the user for a number graded 
	int gradeNum(0);
	cout << "Enter number grade: ";
	cin >> gradeNum;
	char gradeLetter = computeLetterGrade(gradeNum);
	//then displays the letter grade.
	char gradeSign = computeGradeSign(gradeNum);
	gradeSign == '*' ? cout << gradeNum << "% is " << gradeLetter 
		<< endl : cout << gradeNum << "% is " << gradeLetter 
		<< gradeSign << endl;
	
	return 0;
}

/**********************************************************************
 * computeLetterGrade();
 * Write a function to return the letter grade from a number grade. The
 * input will be an integer, the number grade. The output will be a 
 * character, the letter grade. You must use a switch statement for 
 * this function. Please see the syllabus for the meaning behind the 
 * various letter grades.
 ***********************************************************************/
char computeLetterGrade(int gradeNum)
{
	//A	100 % -90 % Demonstrated mastery of the class
	//B	89.9% -80 % All of the key concepts and skills have been learned
	//C	79.9% -70 % Acceptable, but might not be ready or CS 165
	//D	69.9% -60 % Developing; the class has yet to be mastered
	//F	59.9% -0 % Failed to understand or complete the course

	//get the first digit
	int firstDigit = int(gradeNum / 10);
	//variable to be return declared
	char gradeLetter('0');

	//I use the first digit to find out which letter correspond the grade
	switch (firstDigit)
	{
	case (10)://100%
		gradeLetter = 'A';
		break;
	case (9)://90%
			gradeLetter = 'A';
			break;
	case (8)://80%
		gradeLetter = 'B';
		break;
	case (7)://70%
		gradeLetter = 'C';
		break;
	case (6)://60%
		gradeLetter = 'D';
		break;
	default:
		gradeLetter = 'F';
		break;
	}

	return gradeLetter;
}
 /**********************************************************************
  * computeGradeSign();
  * Write another function to return the grade sign (+ or -) from a 
  * number grade. The input will be the same as with computeLetterGrade()
  * and the output will be a character. If there is no grade sign for a 
  * number grade like 85%=B, then return the symbol ‘*’. You must use at 
  * least one conditional expression. Please see the syllabus for the 
  * exact rules for applying the grade sign.
  ***********************************************************************/
char computeGradeSign(int gradeNum)
{
	//Additionally, a minus (-) will be added when the last digit 
	//is a 0, 1, or 2 for all grades except F's
	// A plus (+) will be added when the last digit is a 7, 8, or 
	//9 for all grades except A's and F's
	
	//declare variable to return. 
	char gradeSign('0');

	//check for F's and A+'s
	if (gradeNum < 60 || gradeNum > 96)
		return gradeSign = '*';

	//get last digit
	int lastDigit = gradeNum % 10;

	//conditional expression
	gradeSign = (lastDigit < 4 ? '-' : (lastDigit > 6 ? '+': '*' ));

	return gradeSign;
}