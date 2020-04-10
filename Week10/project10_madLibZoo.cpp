/***********************************************************************
* Program:
* Project 9, Calendar 
* Brother Helfrich, CS124
* Elias Ramirez
* Summary:
* Write a program to implement Mad Lib®. According to Wikipedia,
* Mad Libs is a word game where one player prompts another for a list 
* of words to substitute for blanks in a story; these word substitutions
* have a humorous effect when the resulting story is then read aloud.
* The program will prompt the user for the file that describes the Mad 
* Lib®, and then prompt him for all the substitute words. When all the 
* prompts are complete, the program will display the completed story 
* on the screen.
************************************************************************/
#include <iostream> 
#include <iomanip> 
#include <fstream>
using namespace std;

void getFileName(char fileName[], int size);
int readFile(char story[][256],char fileName[256]);
void askQuestion(char story[][256], int words);
void display(char story[][256], int size);
void play();


/**********************************************************************
 * MAIN
 * Perhaps the easiest way to do this is in a four-step process:
 * 1. Create the framework for the program using stub functions based on
 * the structure chart from your design document.
 * 2. Write each function. Test them individually before "hooking them
 * up" to the rest of the program. You are not allowed to use the String
 * Class for this problem; only c-strings!
 * 3. Verify your solution with testBed:
************************************************************************/
int main()
{
	//main calls play function and it does the rest
	play();
	return 0;
}

void play()
{
	//bool for playing
	bool play(true);
	//variable for response
	char answer = 'y';
	
	//While loop. As long as play is true, it will play
	while (play)
	{
		//getFileName
		char fileName[256];
		getFileName(fileName, 256);

		char story[256][256]; //The file will be recoded here
		//Read through filename
		int words = readFile(story, fileName);

		//now that we have the story and questions, we can ask them
		askQuestion(story, words);
		display(story, words);

		//ask if user wants to play further
		cout << "Do you want to play again (y/n)? ";
		cin >> answer;
		//check answer
		if (answer == 'n' || answer == 'N')
			play = 0;
	}
	// Last message
	cout << "Thank you for playing.\n";
}


/**********************************************************************
 * getFileName
************************************************************************/
void getFileName(char fileName[], int size)
{
	//simple function
	cout << "Please enter the filename of the Mad Lib: ";
	cin >> fileName;
}

/**********************************************************************
 * readFile
************************************************************************/
int readFile(char story[][256], char fileName[])
{
	// open the file for reading
	ifstream fin(fileName);
	// check for errors
	if (fin.fail())
	{
		// inform user of the error
		cout << "Error reading file \""
			<< fileName << "\""
			<< endl;
		return 0;
	}
	//number of words will be stored here
	int counter(0);
	//While loop to read through file with eof
	while (!fin.eof())
	{
		fin >> story[counter];
		counter++; 
	}
	//close file
	fin.close();

	//questions contain the number of question to ask for
	return counter;
}

/**********************************************************************
 * askQuestion()
************************************************************************/

void askQuestion(char story[][256],  int words)
{

	cin.ignore();
	char answer[256];
	//Iterate through array
	for (int i = 0; i < words; i++)
	{
		//iterate through array
		for (int j = 0; story[i][j]; j++)
		{
			if (story[i][j] == '<')
			{
				//if the next character is alphanumeric, then it's a 
				//question
				if (isalpha(story[i][j + 1]))
				{
					//Ask Question:
					for (int k = 1; story[i][k]; k++)
					{
						//If first character, then Capital Letter
						if (k == 1)
							//I have to parse to char as the result was the 
							//numerical character
							cout << "\t" << char(toupper(story[i][k]));
						//if _ then remove it
						else if (story[i][k] == '_')
							cout << " ";
						//if > then, do not add space
						else if (story[i][k] == '>')
							cout << "";
						//else, read content
						else
							cout << story[i][k];
					}
					//continuation of question
					cout << ": ";
					//Record answer
					cin.getline(answer, 256);

					//copy answers to Story
					for (int l(0); story[i][l]; l++)
					{
						story[i][l] = answer[l];
					}
				}
			}
		}
	}
}



/**********************************************************************
 * display()
************************************************************************/
void display(char story[][256], int size)
{
	//Iterate through array
	for (int i = 0; i < size; i++)
	{	
		//Let's iterate through array
		for (int j = 0; story[i][j]; j++)
		{
			//check if there is a prompt
			if (story[i][j] == '<')
			{
				//if there's a prompt, then let's check the next symbol
				switch (story[i][1])
				{
				// if # then next line
				case '#':
					cout << endl;
					j+=2;
					break;
				// if { then add "
				case '{':
					cout << "\"";
					j += 2;
					break;
				// if } then add "
				case '}':
					cout << "\"";
					j += 2;
					break;
				// if { then add '
				case '[':
					cout << "\'";
					j += 2;
					break;
				// if } then add '
				case ']':
					cout << "\'";
					j += 2;
					break;
				// if none of then, then break the switch
				default:
					break;
				}
			}
			//If not a prompt, then read each word
			else
			cout << story[i][j];
		}
		//formatting

		//if . or , do not add space
		if (story[i][256] == '.' || story[i][256] == ',')
			cout << "";
		//else if a prompt, do not add space
		else if (story[(i)][1] == '#' || story[(i)][1] == '{' || story[(i)][1] == '[')
			cout << "";
		//else if the next word is a " or ', then do not add space
		else if (story[(i + 1)][1] == ']' || story[(i + 1)][1] == '}')
			cout << "";
		//else add space
		else
			cout << " ";		
	}
	//spacing at the end
	cout << endl;
}
