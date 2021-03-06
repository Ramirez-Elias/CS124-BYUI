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
void readFile(char board[][SIZE], char fileName[]);
void displayBoard(char board[][SIZE]);
void displayOptions();
char getOption();
void editSquare(int &value, char coordinates[], int size);
void writeFile(char board[][SIZE], char fileName[]);
//void displayPossible();
//void writeBoard(char board[][3], char fileName[256]);
//void computeValues();

/**********************************************************************
 * MAIN
 * The program will prompt the user for the filename of the game he or 
 * she is currently working on and display the board on the screen. The
 * user will then be allowed to interact with the game by selecting 
 * which square he or she wishes to change. While the program will not 
 * solve the game for the user, it will ensure that the user has not 
 * selected an invalid number. If the user types S in the prompt, then
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
void readFile(char board[][SIZE], char fileName[])
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
	char board[SIZE][SIZE];
	bool firstRun(true);
	char option('D');
	int value(0);
	char coordinates[3];
	//get File function call
	getFile(filename, 256);
	//read file function call
	readFile(board, filename);

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
		  //The next action of the program will depend on the users command.
			switch (getOption())
			{
			case 'D':
				//If the user types D, then the board will be redrawn.
				displayBoard(board);
				break;
			case 'E':
				//If the user types E, then the program will prompt him 
				//for the coordinates and the value for the square to be
			    //edited:
				editSquare(value, coordinates, 3);
				break;
			case 'S':
				//If the user types S, then the program will prompt him 
				//for the coordinates and display the possible values:
				break;
			case 'Q':
				//If the user types Q, then he or she will be prompted 
				//for the filename:
				play = false; // play == false. Game is over
				writeFile(board, filename); // write file
				break;
			case '?':
				//If the user types ?, then the menu of options will be 
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
	//Here, the user will be prompted for a command (the main prompt).
	//Please note that you will need a newline, a carat('>'), and a 
	//space before the prompt.
	cout << endl;
	cout << "> ";
	cin >> option;
	//in case user types in lowercase
	option = toupper(option);
	//function returns option selected
	return option;
}

/**********************************************************************
 * getInput()
************************************************************************/
void editSquare(int &value, char coordinates[], int size)
{
	//get coordinate
	cin.ignore();
	cout << "What are the coordinates of the square: ";
	cin.getline(coordinates, size);
	//evaluate input (TODO)

	//First character is upper case
	coordinates[0]= toupper(coordinates[0]);
	
	//display input and request value
	cout << "What is the value at \'" << coordinates[0] << coordinates[1] << "\': ";
	cin >> value;
}

/**********************************************************************
 * displayBoard()
************************************************************************/
void displayBoard(char board[][SIZE])
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
				if (board[row][col] == '0')
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
void writeFile(char board[][SIZE], char fileName[])
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