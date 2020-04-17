/***********************************************************************
* Program:
* Project 4 - Sudoku
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* The second part of the Sudoku Program project (the first part being 
* the design document due earlier) is to write the code necessary to make 
* the Sudoku appear on the screen
************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

#define SIZE 9

//prototype
void getFile(char fileName[], int size);
void interact(bool &play);
void readFile(int board[][SIZE], char fileName[]);
void displayBoard(int board[][SIZE]);
void displayOptions();
char getOption();
void getCoordinates(char coordinates[], int size, int grid[][SIZE], 
	int &col, int &row);
void editSquare(int &value, char coordinates[], int size, int grid[][SIZE], 
	int &col, int &row, int possibleValues[], int index, int board[][SIZE]);
int getCol(char coordinates[]);
int getRow(char coordinates[]);
void writeFile(int board[][SIZE], char fileName[]);
void displayPossible(int possibleValues[], int size, char coordinates[]);
void computeValues(int board[][SIZE], int col, int row, int size, 
	int grid[][SIZE], int possibleValues[], int &index);
void getHorizontalValues(int board[][SIZE], int rowContent[], int row);
void getVerticalValues(int board[][SIZE], int rowContent[], int row);
void createGrid(int board[][SIZE], int totalZeros[], int grid[][9]);
int getPossibleValues(int gridLine[], int possibleValues[]);
int mergeLines(int possibleValues[], int possibleValuesVer[], int verSize, 
	int possibleValuesHor[], int horSize, int gridHorizontal[], int gridVertical[]);
int getGridValue(int grid[][SIZE], int col, int row, int &gridNumber);
int removePossible(int possibleValues[], int mergeValues[], int possibleSize, 
	int grid[][SIZE], int gridNumber);
/**********************************************************************
 * MAIN
 * The program will prompt the user for the filename of the game he or 
 * she is currently working on and display the board on the screen. The
 * user will then be allowed to interact with the game by selecting 
 * which square he or she wishes to change. While the program will not 
 * solve the game for the user, it will ensure that the user has not 
 * selected an invalid number. If the user types ‘S’ in the prompt, then
 * the program will show the user the possible valid numbers for a given
 * square. When the user is finished, then the program will save the
 * board to a given filename and exit.
 ***********************************************************************/
int main()
{
	//bool play. If false, then no game is being play
	bool play(true);
	//interact function. It will control the game
	interact(play);
	return 0;
}

/**********************************************************************
 * getFile()
************************************************************************/
void getFile(char fileName[], int size)
{
	//simple function
	cout << "Where is your board located? ";
	cin >> fileName;
}


/**********************************************************************
 * readFile
************************************************************************/
void readFile(int board[][SIZE], char fileName[])
{
	//open file
	ifstream fin(fileName);

	//check errors
	if (fin.fail())
	{
		// inform user of the error
		cout << "Error reading file \""
			<< fileName << "\""
			<< endl;
		return;
	}
	//read through end of file
	while (!fin.eof())
	{
		for (int row(0); row < SIZE; row++)
		{
			for (int col(0); col < SIZE; col++)
			{
				//copy to board
				fin >> board[row][col];
			}
		}
	}

	//close file
	fin.close();
}

/**********************************************************************
 * interact()
************************************************************************/
void interact(bool &play)
{
	//variables
	char filename[256];
	int board[SIZE][SIZE];
	bool firstRun(true);
	char option('D');
	int value(0);
	char coordinates[3];
	int possibleValues[SIZE];
	int index(0);
	int col(0);
	int row(0);
	//get File function call
	getFile(filename, 256);
	//read file function call
	readFile(board, filename);


	// 1- look for less 0's (if zero == 1) is perfect

	//This variable will contain the number of 0's per Grid
	//      0 | 1 | 2
	//	   ---+---+---
	//	    3 | 4 | 5
	//	   ---+---+---
	//	    6 | 7 | 8

	//Total zeros per grid
	int totalZeros[9] = {};

	//board organized by grid instead of rows and columns
	int grid[9][9] = {};
	createGrid(board, totalZeros, grid);


	//game. It will continue while play is true
	do
	{
		//With the filename specified, the program will display a menu:
		//Display function call only if first run
		if (firstRun)
		{
			displayOptions();
			cout << endl;
			displayBoard(board);
			firstRun = false;
		}
		  //The next action of the program will depend on the user’s command.
			switch (getOption())
			{
			case 'D':
				//If the user types ‘D’, then the board will be redrawn.
				displayBoard(board);
				break;
			case 'E':
				//If the user types ‘E’, then the program will prompt him 
				//for the coordinates and the value for the square to be
			    //edited:
				getCoordinates(coordinates, 3, grid, col, row);
				computeValues(board, col, row, 3, grid, possibleValues, index);
				editSquare(value, coordinates, 3, grid, col, row, possibleValues,
					index, board);
				break;
			case 'S':
				//If the user types ‘S’, then the program will prompt him 
				//for the coordinates and display the possible values:
				getCoordinates(coordinates, 3, grid, col, row);
				computeValues(board, col, row, 3, grid, possibleValues, index);
				displayPossible(possibleValues, index, coordinates);
				break;
			case 'Q':
				//If the user types ‘Q’, then he or she will be prompted 
				//for the filename:
				play = false; // play == false. Game is over
				writeFile(board, filename); // write file
				break;
			case '?':
				//If the user types ‘?’, then the menu of options will be 
				//displayed again.
				displayOptions();
				break;
			default:
				//If the user types an invalid command, then the following 
				//message will be displayed: ERROR: Invalid command
				cout << "ERROR: Invalid command\n";
				break;
			}
	} while (play);
}

/**********************************************************************
 * displayOptions()
************************************************************************/
void displayOptions()
{
    //Display options
	cout << "Options:\n"
		<< "   ?   Show these instructions\n"
		<< "   D   Display the board\n"
		<< "   E   Edit one square\n"
		<< "   S   Show the possible values for a square\n"
		<< "   Q   Save and quit\n";
}

/**********************************************************************
 *getOptions()
************************************************************************/
char getOption()
{
	//declare option variable
	char option('?');
	bool isSingleDigit(false);
	//Here, the user will be prompted for a command (the main prompt).
	//Please note that you will need a newline, a carat('>'), and a 
	//space before the prompt.
	do
	{
		cout << endl;
		cout << "> ";
		cin >> option;
		option = toupper(option);
		//check Option
		if (option == '?' || option == 'D' || option == 'E' || option == 'S' || option == 'Q')
			isSingleDigit = true;
		else
			cout << "ERROR: Invalid command" << endl;

	} while (!isSingleDigit);

	//in case user types in lowercase
	
	//function returns option selected
	return option;
}

/**********************************************************************
 * getCoordinates()
************************************************************************/
void getCoordinates(char coordinates[], int size, int grid[][SIZE], int &col, int &row)
{
	//get coordinate
	cin.ignore();
	bool checked(false);
	int gridNumber(0);
	int gridValue(0);
	do
	{
		//get coordinate
		cout << "What are the coordinates of the square: ";
		cin.getline(coordinates, size);
		//evaluate input (TODO)
		//First character is upper case
		coordinates[0] = toupper(coordinates[0]);
		if (int(coordinates[0]) >= 65 && int(coordinates[0]) <= 73)
		{
			//check if empty
			col = getCol(coordinates);
			row = getRow(coordinates);
			if (getGridValue(grid, col, row, gridNumber))
				cout << "ERROR: Square \'" << coordinates[0] << coordinates[1] << "\' is filled\n";
			else
				checked = true;
		}
		else
		{
			cout << "ERROR: Square \'" << coordinates[0] << coordinates[1] << "\' is invalid\n";
		}
	} while (!checked);
}

/**********************************************************************
 * editSquare()
************************************************************************/
void editSquare(int &value, char coordinates[], int size, int grid[][SIZE],
	int &col, int &row, int possibleValues[], int index, int board[][SIZE])
{
	//display input and request value
	cout << "What is the value at \'" << coordinates[0] << coordinates[1] << "\': ";
	cin >> value;
	//compare against possible values
	bool isMatch(false);
	for (int i(0); i < index; i++)
	{
		if (value == possibleValues[i])
			isMatch = true;
	}
	//check if there is a match
	if (isMatch)
		board[row][col] = value;
	else
		cout << "ERROR: Value \'" << value << "\' in square \'"
		<< coordinates[0] << coordinates[1] << "\' is invalid\n";
}

/**********************************************************************
 * getCol()
************************************************************************/
int getCol(char coordinates[])
{
	int col(0);

	switch (coordinates[0])
	{
	case 'A':
		col = 0;
		break;
	case 'B':
		col = 1;
		break;
	case 'C':
		col = 2;
		break;
	case 'D':
		col = 3;
		break;
	case 'E':
		col = 4;
		break;
	case 'F':
		col = 5;
		break;
	case 'G':
		col = 6;
		break;
	case 'H':
		col = 7;
		break;
	case 'I':
		col = 7;
		break;
	default:
		break;
	}
	return col;
}

/**********************************************************************
 * getRow()
************************************************************************/
int getRow(char coordinates[])
{
	int row = ((int)coordinates[1]) - 49;
	return row; 
}

/**********************************************************************
 * displayPossible()
************************************************************************/
void displayPossible(int possibleValues[], int size, char coordinates[])
{
	//display input and request value
	if(size <= 1)
		cout << "The possible value for \'" << coordinates[0] << coordinates[1] << "\' is: ";
	else
		cout << "The possible values for \'" << coordinates[0] << coordinates[1] << "\' are: ";

	//display value
	for (int i(0); i < size; i++)
	{
		//no , at the end.
		if (i == (size - 1))
			cout << possibleValues[i] << endl;
		else 
		//Additional values with comma
			cout << possibleValues[i] << ", ";
	}
	
}

/**********************************************************************
 * displayBoard()
************************************************************************/
void displayBoard(int board[][SIZE])
{
	//this variable will help with the Number Column
	int counter(1);
	//iterate through the grid
	for (int row(0); row < SIZE; row++)
	{	
		//Display Header if first row
		if (row == 0)
			cout << "   A B C D E f G H I \n";

		//if middle row, then add the frame
		if (row == 3 || row == 6)
			cout << "   -----+-----+----- \n";

		//read columns
		for (int col(0); col < 10; col++)
		{
			//if column 9, then start a new line
			if (col == 9)
			{
				cout << endl;
			}
			//if not, then read data
			else
			{
				//if a "." then, do not display it on the screen
				//steps below will take care of 0's
				if (board[row][col] == 0)
				{
					if (col == 0)
					{
						//Counter display what number
						cout << counter << "  " << "  ";
						//Counter gets ready for next line
						counter++;
					}
					//add divisors and do not show 0's
					else if (col == 2 || col == 5)
						cout <<  " |";
					//do not show 0's
					else
						cout << "  ";
				}
				//else display numbers on the grid
				else
				{
					//if column is 0, then row line should be added first
					if (col == 0)
					{
						cout << counter << "  " << board[row][col] << " ";
						counter++;
					}
					//add divisors
					else if (col == 2 || col == 5)
						cout << board[row][col] << "|";
					//add additional numbers
					else
						cout << board[row][col] << " ";
				}
			}
		}
	}
	cout << endl;
}

/**********************************************************************
 * writeFile()
************************************************************************/
void writeFile(int board[][SIZE], char fileName[])
{
	//simple function
	cout << "What file would you like to write your board to: ";
	cin >> fileName;

	// declare an output file stream variable.
	ofstream fout(fileName);

	// check for error with fail() 
	if (fout.fail())
	{
		cout << "Error reading file \""
			<< fileName << "\""
			<< endl;
		return;
	}
	//iterate through the grid
	for (int row(0); row < SIZE; row++)
	{
		//read columns
		for (int col(0); col < 10; col++)
		{
			//if column 3, then start a new line
			if (col == 9)
				fout << endl;
			//if not, copy data
			else
				fout << board[row][col] << " ";
		}
	}
	// close file
	fout.close();

	//Message
	cout << "Board written successfully\n";
}

/**********************************************************************
 * computeValues()
 * Write the pseudocode for the function computeValues().This function 
 * will take as parameters coordinates(row and column) for a given square
 * on the board and calculate the possible values for the square.To do 
 * this, computeValues() must be aware of all the rules of Sudoku.Make
 * sure to include both the logic for the rules of the game(only one of
 * each number on a row, column, and inside square), but also to display
 * the values.

1 - look for less 0's (if zero == 1) is perfect
2 - solve
getNumber of existing numbers in grid
getPossibleValues
Start with1stGrid = Elimiante any repeated number
Check 1st square, can any number be eliminated
Check 2nd square, can any number be eliminated
Cont.with 2Grid = Elimiante any repeated number
Check 3rd square, can any number be eliminated
Check 4th sq., can any number be eliminated
Check remaining possible numbers
Check 1st square
Check 2nd square
Check 3rd square
Skip 4th Sq.
check 1st Sq
check 4th sq
Break.
if tie, brake an go look for another one

************************************************************************/
void computeValues(int board[][SIZE], int col, int row, int size, 
	int grid[][SIZE], int possibleValues[], int &index)
{	
	//This value will contain the values per specific column
	int gridVertical[9] = {};
	getVerticalValues(board, gridVertical, col);

	//This value will contain the values per specific row
	int gridHorizontal[9] = {};
	getHorizontalValues(board, gridHorizontal, row);

	//get possible value per col
	int possibleValuesCol[9];
	int colCount = getPossibleValues(gridVertical, possibleValuesCol);
	
	//get possible value per row
	int possibleValuesRow[9];
	int rowCount = getPossibleValues(gridHorizontal, possibleValuesRow);

	//merge both possible values
	int mergeValues[9];
	int possibleMax = mergeLines(mergeValues, possibleValuesCol, colCount,
		possibleValuesRow, rowCount, gridHorizontal, gridVertical);
	
	//get grid values
	int gridNumber(0);
	getGridValue(grid, col, row, gridNumber);

	//get index value
	index = removePossible(possibleValues, mergeValues, possibleMax, 
		grid, gridNumber);

}

/**********************************************************************
 * getHorizontalValues()
************************************************************************/

void getHorizontalValues(int board[][SIZE], int rowContent[], int row)
{
	int rMax = row + 1;
	for (int Row(row); Row < rMax; Row++)
	{
		for (int Col(0); Col < 9; Col++)
		{
			rowContent[Col] = board[Row][Col];

		}
	}
}

/**********************************************************************
 * getVerticalValues()
************************************************************************/
void getVerticalValues(int board[][SIZE], int columnContent[], int col)
{
	int cMax = col + 1;
	for (int Row(0); Row < 9; Row++)
	{
		for (int Col(col); Col < cMax; Col++)
		{
			columnContent[Row] = board[Row][Col];
		}
	}
}

/**********************************************************************
 * createGrid()
* Grid will look as follow:
*   grid # 0 = [0][0] to [2][2]
*   grid # 1 = [0][3] to [2][5]
*   grid # 2 = [0][6] to [2][8]
*   grid # 3 = [3][0] to [5][2]
*   grid # 4 = [3][3] to [5][5]
*   grid # 5 = [3][6] to [5][8]
*   grid # 6 = [6][0] to [8][2]
*   grid # 7 = [6][3] to [8][5]
*   grid # 8 = [6][6] to [8][8]
*
* Or like this:
*  0 | 1 | 2
* ---+---+---
*  3 | 4 | 5
* ---+---+---
*  6 | 7 | 8

************************************************************************/
void createGrid(int board[][SIZE], int totalZeros[], int grid[][9])
{
	//Index will keep track of array/grid
	int index(0);
	//This will help with the content of each grid
	int element(0);

	//iterate through board
	for (int gridRow(0); gridRow < 3; gridRow++)
	{
		for (int gridCol(0); gridCol < 3; gridCol++)
		{
			for (int r(0); r < 9; r++)
			{
				if (r / 3 == gridRow)
				{
					for (int c(0); c < 9; c++)
					{
						if (c / 3 == gridCol)
						{
							//This will keep track of total of 0's inside 
							//each grid
							if (board[r][c] == 0)
								totalZeros[index] += 1;
							//this will create a 3x3 grid
							grid[index][element] = board[r][c];
							element++;
							//if element = 9, then it got to the end of 
							//the row and it gets resetted
							if (element == 9)
							{
								element = 0;
								index++;
							}
						}
					}
				}
			}
		}
	}

}

/**********************************************************************
 * getPossibleValues()
************************************************************************/
int getPossibleValues(int gridLine[], int possibleValues[])
{
	int index(0);
	bool isMatch(false);
	for (int i = 1; i < 10; i++)
	{
		for (int j(0); j < 9; j++)
		{
			if (i == gridLine[j])
			{
				isMatch = true;
			}
		}
		if (!isMatch)
		{
			possibleValues[index] = i;
			index++;
		}
		else
			isMatch = false;
	}
	return index;
}

/**********************************************************************
 * mergeLines()
************************************************************************/
int mergeLines(int possibleValues[], int possibleValuesVer[], int verSize,
	int possibleValuesHor[], int horSize, int gridHorizontal[], 
	int gridVertical[])
{
	int index(0);
	bool isMatch(false);
		for (int i = 0; i < verSize; i++)
		{
			for (int j(0); j < horSize; j++)
			{
				if (possibleValuesVer[i] == possibleValuesHor[j])
				{
					isMatch = true;
					possibleValues[index] = possibleValuesVer[i];
					index++;
				}
			}
			if (!isMatch)
			{
				possibleValues[index] = possibleValuesVer[i];
				index++;
			}
			else
				isMatch = false;
		}
		int max = index;

		//second part
		for (int i = 0; i < horSize; i++)
		{
			for (int j(0); j < max; j++)
			{
				if (possibleValuesHor[i] == possibleValuesVer[j])
				{
					isMatch = true;
					//nothing as it was already added
				}
			}
			if (!isMatch)
			{
				possibleValues[index] = possibleValuesHor[i];
				index++;

			}
			else
				isMatch = false;
		}

		int combinedValues[18];
		for (int i = 0; i < 9 ;i++)
		{
		
			combinedValues[i]  = gridHorizontal[i];

		}
		int j(0);
		for (int i = 9; i < 18; i++)
		{
			combinedValues[i] = gridVertical[j];
			j++;
		}

		//third part  remove duplicate 
		int placeholder[9];
		int temp (0);
		for (int i = 0; i < index; i++)
		{
			for (int j(0); j < 18; j++)
			{
				if (possibleValues[i] == combinedValues[j])
				{
					isMatch = true;
					//nothing as it's duplicate
				}
			}
			if (!isMatch)
			{
				placeholder[temp] = possibleValues[i];
				temp++;

			}
			else
				isMatch = false;
		}

		for (int i = 0; i < temp; i++)
		{
			possibleValues[i] = placeholder[i];
		
		}

		index = temp;

	return index;
}

/**********************************************************************
 * removePossible()
************************************************************************/
int removePossible(int possibleValues[], int mergeValues[], 
	int possibleSize, int grid[][SIZE], int gridNumber)
{
	int index(0);
	bool isMatch(false);
	for (int i = 0; i <possibleSize; i++)
	{
		for (int j(0); j < 9; j++)
		{
			if (mergeValues[i] == grid[gridNumber][j])
			{
				isMatch = true;
				
			}
		}
		if (!isMatch)
		{
			possibleValues[index] = mergeValues[i];
			index++;
		}
		else
			isMatch = false;
	}

	return index;
}

/**********************************************************************
 * getGridValue()
************************************************************************/
int getGridValue(int grid[][SIZE], int col, int row, int &gridNumber)
{
	//return value
	int gridValue(0);

	//Index will keep track of array/grid
	int index(0);
	//This will help with the content of each grid
	int element(0);

	//iterate through board
	for (int gridRow(0); gridRow < 3; gridRow++)
	{
		for (int gridCol(0); gridCol < 3; gridCol++)
		{
			for (int r(0); r < 9; r++)
			{
				if (r / 3 == gridRow)
				{
					for (int c(0); c < 9; c++)
					{
						if (c / 3 == gridCol)
						{
							if (r == row && c == col)
							{
								gridNumber = index;
								gridValue = grid[index][element];
							}
							element++;
							if (element == 9)
							{
								element = 0;
								index++;
							}
						}
					}
				}
			}
		}
	}
	return gridValue;
}
