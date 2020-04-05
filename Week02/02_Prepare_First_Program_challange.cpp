/*********************************************************************** 
* Program: 
* Assignment 10, Hello World
* Brother Helfrich, CS124 
* Author: 
* Sam Student 
* Summary: 
* This program is designed to be the first C++ program you have ever 
* written. While not particularly complex, it is often the most difficult 
* to write because the tools are so unfamiliar. 
************************************************************************/
#include <iostream> 
using namespace std; 

/********************************************************************** 
* Hello world on the screen 
***********************************************************************/
int main() 
{ 
	// Challenge: modify this program to display a paragraph including
	// your name and a short introduction.
	cout << "Hello, I am Br. Helfrich.\n" // \n is used to add a new line
		<<"\n"
		<< "My favorite thing about teaching is interacting with interesting students every\n"
		<< "day. Some days, however, students have no questions and dont bother to come by\n"
		<< "my office. Those are long and lonely days...\n"; 
	
	return 0; 
}