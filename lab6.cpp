/******************************************************************************
* Program Filename: lab6.cpp
* Author: Kelvin Watson (OSU ID 932540242)
* Date: 7 February, 2015
* Description: (lab6 - Searching & Sorting Algorithms, CS 162). Driver program.
* Input: Accepts user's commands and performs linear search, selection sort,
*			or a binary search.
* Output: Performs linear search, selection sort, or a binary search on four
* 		input files.
******************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include "functions.h"

int main()
{
 showIntro();
 string command;

 do
 {
 		command.clear();
 		showMenu();
 		command = getCommand();

 		if(command=="L")
 				searchForZero();

 		else if(command=="S")
 				prepSort();

 		else if(command=="B")
 				binarySearch();

 		else if(command=="Q")
 		{
 				cout << "Exiting program. Goodbye." << endl;
     exit(EXIT_SUCCESS);
 		}
 }while(command != "Q");
 return 0;
}
