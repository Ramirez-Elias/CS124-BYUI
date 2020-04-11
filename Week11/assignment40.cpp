/***********************************************************************
* Program:
* Assignment 40
* Brother Helfrich, CS124
* Author:
* Elias Ramirez
* Summary:
* Bla bla bla.
************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

//prototype
void getFile(char fileName[], int size);
void readFile(char board[][3], char fileName[256]);
void display(char board[][3]);
void writeFile(char board[][3], char fileName[256]);

/**********************************************************************
 * MAIN
 * Write a function to read a Tic-Tac-Toe board into an array. The file
 * format is:
 *   X O . 
 *   . . .
 *   . X .
 * The character ‘X’ means that the ‘X’ player has taken that square. 
 * The character ‘.’ means that the square is currently unclaimed. 
 * There is one space between each symbol.
 * Note: You will need to store the results in a 2D array. The function
 *  should take the filename as a parameter.
 * Write a function to display a Tic-Tac-Toe board on the screen. Given
 * the above board, the output is:
 *  X | O | 
 * ---+---+--- 
 *    |   | 
 * ---+---+--- 
 *    | X |
 * Write a function to write the board to a file. The file format is the
 * same as with the read function.
 ***********************************************************************/
int main()
{
	//get filename
	char filename[256];
	getFile(filename, 256);
	
	//You will need to store the results in a 2D array.
	//3x3 board char [row][column]
	char board[3][3];
	
	//read file
	readFile(board, filename);

	// display file
	display(board);

	//write file
	writeFile(board, filename);
	
	return 0;
}



/**********************************************************************
 * getFile
************************************************************************/
void getFile(char fileName[], int size)
{
	//simple function
	cout << "Enter source filename: ";
	cin >> fileName;
}

/**********************************************************************
 * readFile
************************************************************************/
void readFile(char board[][3], char fileName[256])
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

	//While loop to read through file with eof
	//This is how the board should look like
	//3x3 board char [row][column]
	//Col 0 1 2 3
	//    X     0 row 0
	//      X   0 row 1
	//        X 0 row 2
	//    0 0 0 0 row 3
	while (!fin.eof())
	{
		for (int row(0); row < 3; row++)
		{
			if (row % 4 == 0 && row != 0)
			{
				//skip row as we are at the end
				row++;
			}
			for (int col(0); col < 3; col++)
			{
				if (col % 4 == 0 && col != 0)
				{
					//skip row as we are at the end
					col++;
				}
				else
				fin >> board[row][col];
			}
		}
	}

	//close file
	fin.close();
}

/**********************************************************************
 * display
 * Function should display output as:
 *  X | O |
 * ---+---+---
 *    |   |
 * ---+---+---
 *    | X |
************************************************************************/
void display(char board[][3])
{
	//iterate through the grid
	for (int row(0); row < 3; row++)
	{
		//if middle row, then add the frame
		if (row == 1 || row == 2)
			cout << "---+---+--- \n";
		//skip row as we are at the end
		if (row % 4 == 0 && row != 0)
		{
			row++;
		}
		//read columns
		for (int col(0); col < 4; col++)
		{
			//if column 3, then start a new line
			if (col == 3)
			{
				cout << endl;
			}
			//if not, then read data
			else
			{
				//if a "." then, do not display it on the screen
				if (board[row][col] == '.')
					cout << "   ";
				//else display it
				else 
				{
					cout << " " << board[row][col] << " ";
				}
				//last, add the dividers for middle column	
				if (col == 0 || col == 1)
						cout << "|";
			}
		}
	}
}
/**********************************************************************
 * writeFile
************************************************************************/

void writeFile(char board[][3], char fileName[256])
{
	//simple function
	cout << "Enter destination filename: ";
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

	//Iterate through grid
	for (int row(0); row < 3; row++)
	{
		if (row % 4 == 0 && row != 0)
		{
			//skip row as we are at the end
			row++;
		}
		for (int col(0); col < 3; col++)
		{
			if (col % 4 == 0 && col != 0)
			{
				//skip row as we are at the end
				col++;
			}
			else
				fout << board[row][col] << " ";
		}
	}

	// close file
	fout.close();

	//Message
	cout << "File written\n";
}

