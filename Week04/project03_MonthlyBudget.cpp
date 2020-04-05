/***********************************************************************
* Program:
* Project 2, Monthly Budget
* Brother Helfrich, CS124
* Elias Ramirez
* Summary:
* Notice how many of the values that were previously 0.00 now are 
* computed. You will also need to calculate the values for Tithing,
* Budget Other, and Actual Difference. You can find the formula for 
* these calculations earlier in the project description.
************************************************************************/
#include <iostream> 
#include <iomanip> 
using namespace std;

//prototype functions
void header(); // I created this function for the header
float getIncome(); //income
float computeTithing(float income);// New function for Bugeted Tithes
float getBudgetLiving(); //budgetLiving 
float getActualLiving(); //actualLiving 
float getActualTax(); //actualTax 
float getActualTithing(); //actualTithing 
float computeOther(float income, float budgetLiving, float budgetTithing);// New function for Budgeted Other. It needs Budget Tax
float getActualOther(); //actualOther 
float computeBudgetedDiff(float income, float budgetLiving,
	float budgetTithing, float budgetOther); //New function for Budgeted Difference
float computeActualDiff(float income, float actualTax,
	float actualTithing, float actualLiving, float actualOther); //New function for Actual Difference
void display(float income, float budgetLiving, float actualTax, 
	float actualTithing, float actualLiving, float actualOther, 
	float budgetTithing, float budgetOther, float budgetDiff, 
	float actualDiff);

/**********************************************************************
* MAIN
* For this program, main() will call the get functions, call the 
* display() function, and hold the values that the user has input
***********************************************************************/
int main()
{
	//header
	header();
	//Following the instructions found in page 102, below are the functions
	float income = getIncome();
	float budgetLiving = getBudgetLiving();
	float actualLiving = getActualLiving();
	float actualTax = getActualTax();
	float budgetTithing = computeTithing(income); //New
	float actualTithing = getActualTithing();
	float budgetOther = computeOther(income, budgetLiving, 
		budgetTithing);//New - Missing Budget Tax
	float actualOther = getActualOther();
	float budgetDiff = computeBudgetedDiff(income, budgetLiving, 
		budgetTithing, budgetOther);//New
	float actualDiff = computeActualDiff(income, actualTax, actualTithing,
		actualLiving, actualOther); //New


	// Display Budget
	display(income, budgetLiving, actualTax, actualTithing, actualLiving,
		actualOther, budgetTithing, budgetOther, budgetDiff, actualDiff);


	return 0;
}

/**********************************************************************
* header()
* I just added it to display the header info
***********************************************************************/
void header()
{
	cout << "This program keeps track of your monthly budget\n"
		<< "Please enter the following:\n";
}

/**********************************************************************
* getIncome
* Pseudocode: PROMPT for income GET income RETURN income
***********************************************************************/
float getIncome()
{
	//declare income variable
	float income(0);
	//prompt for income
	cout << "\tYour monthly income : ";
	//Get income
	cin >> income;
	//return income
	return income;
}

/**********************************************************************
* getBudgetLiving()
* Pseudocode: PROMPT, GET and RETURN Budget Living
***********************************************************************/
float getBudgetLiving()
{
	//declare variable
	float budgetLiving(0);
	//prompt
	cout << "\tYour budgeted monthly living expenses: ";
	//Get 
	cin >> budgetLiving;
	//return
	return budgetLiving;
}

/**********************************************************************
* getActualLiving()
* Pseudocode: PROMPT, GET and RETURN Actual Living
***********************************************************************/
float getActualLiving()
{
	//declare variable
	float actualLiving(0);
	//prompt
	cout << "\tYour actual living expenses: ";
	//Get 
	cin >> actualLiving;
	//return
	return actualLiving;
}

/**********************************************************************
* getActualTax()
* Pseudocode: PROMPT, GET and RETURN Budget Living
***********************************************************************/
float getActualTax()
{
	//declare variable
	float actualTax(0);
	//prompt
	cout << "\tYour actual taxes withheld : ";
	//Get 
	cin >> actualTax;
	//return
	return actualTax;
}

/**********************************************************************
* getActualTithing()
* Pseudocode: PROMPT, GET and RETURN Budget Living
***********************************************************************/
float getActualTithing()
{
	//declare variable
	float actualTithing(0);
	//prompt
	cout << "\tYour actual tithe offerings : ";
	//Get 
	cin >> actualTithing;
	//return
	return actualTithing;
}

/**********************************************************************
* getActualOther()
* Pseudocode: PROMPT, GET and RETURN Budget Living
***********************************************************************/
float getActualOther()
{
	//declare variable
	float actualOther(0);
	//prompt
	cout << "\tYour actual actual other expenses : ";
	//Get 
	cin >> actualOther;
	//return
	return actualOther;
}

/**********************************************************************
* Display
* It takes all variables and display result on screen
***********************************************************************/
void display(float income, float budgetLiving, float actualTax,
	float actualTithing, float actualLiving, float actualOther,
	float budgetTithing, float budgetOther, float budgetDiff,
	float actualDiff)
{
	// configure the output to display money 
	cout.setf(ios::fixed); // no scientific notation except for the deficit 
	cout.setf(ios::showpoint); // always show the decimal point 
	cout.precision(2); // two decimals for cents; this is not a gas station!
	cout << endl;
	cout << "The following is a report on your monthly expenses\n";
	cout << "\tItem\t               Budget\t       Actual\n";
	cout << "\t===============  =============== ===============\n";
	cout << "\tIncome\t         $" << setw(11) << income << "\t $" << setw(11) << income << endl;
	cout << "\tTaxes\t         $" << setw(11) << 0.00 << "\t $" << setw(11) << actualTax << endl;
	cout << "\tTithing\t         $" << setw(11) << budgetTithing << "\t $" << setw(11) << actualTithing << endl;
	cout << "\tLiving\t         $" << setw(11) << budgetLiving << "\t $" << setw(11) << actualLiving << endl;
	cout << "\tOther\t         $" << setw(11) << budgetOther << "\t $" << setw(11) << actualOther << endl;
	cout << "\t===============  =============== ===============\n";
	cout << "\tDifference\t $" << setw(11) << budgetDiff << "\t $" << setw(11) << actualDiff << endl;

}

/**********************************************************************
* computeTithing()
***********************************************************************/
float computeTithing(float income)
{
	float tithing = income * 0.10;
	return tithing;
}

/**********************************************************************
* computeOther()
***********************************************************************/
float computeOther(float income, float budgetLiving, float budgetTithing)
{
	float other = income - budgetLiving - budgetTithing;
	return other;
}

/**********************************************************************
* computeBudgetedDiff()
***********************************************************************/
float computeBudgetedDiff(float income, float budgetLiving, 
	float budgetTithing, float budgetOther)
{
	float budgetDiff = income - budgetLiving - budgetTithing - budgetOther;
	return budgetDiff;
}

/**********************************************************************
* computeActualDiff()
***********************************************************************/
float computeActualDiff(float income, float actualTax,
	float actualTithing, float actualLiving, float actualOther)
{
	float actualDiff = income - actualTax - actualTithing - actualLiving - actualOther;
	return actualDiff;
}
