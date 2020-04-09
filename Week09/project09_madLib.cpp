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
int readFile(char story[][256], int size, char fileName[256], int sizeFile, int words[]);
void askQuestion(char story[][256], int size, int words[],int questNum);
void display();
void playAgain();



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
	//getFileName
	char fileName[256];
	getFileName(fileName,256);

	//Read through filename
	char story[256][256]; //The file will be recoded here
	int words[256];//Questions and characters location will be here
	int questNum = readFile(story, 256, fileName, 256, words);
	
	//now that we have the story and questions, we can ask them
	askQuestion(story, 256, words, questNum);

	return 0;
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
int readFile(char story[][256], int size, char fileName[], int sizeFile, int words[])
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

	int counter(0);
	int  questions(0);
	int  characters(0);
	//While loop to read through file with eof
	while (!fin.eof())
	{
		fin >> story[counter];
		//let's get the location of the words in the string
		if (story[counter][0] == '<')
		{
			//if the next character is alphanumeric, then let's get the location
			//and send it to the array of int
			if (isalpha(story[counter][1]))
			{
				//Words array will contain each of the questions
				words[questions] = counter;
				questions++;
			}
		}
		counter++; 
	}
	//close file
	fin.close();

	//questions contain the number of question to ask for
	return questions;
}

/**********************************************************************
 * askQuestion()
************************************************************************/

void askQuestion(char story[][256], int size, int words[], int questNum)
{
	char answer[256];
	cin.ignore();
	//Iterate through array
	for (int j = 0; j < questNum; j++)
	{			
		//Ask questions
		//If a prompt is encountered, convert the text inside the prompt
		//to a more human-readable form. This means:
		for (int i(1); story[words[j]][i]; i++)
		{
			//If first character, then Capital Letter
			if (i == 1)
				//I have to parse to char as the result was the 
				//numerical character
				cout << "\t" << char (toupper (story[words[j]][i]));
			else if (story[words[j]][i] == '_')
				cout << " ";
			else if (story[words[j]][i] == '>')
				cout << "";
			else
				cout<< story[words[j]][i];
		}
		cout << ": ";
		//Record answer
		cin.getline(answer, 256);

		//copy answers to Story
		for (int k(0); story[words[j]][k]; k++)
		{
			story[words[j]][k] = answer[k];
		}
	}
}