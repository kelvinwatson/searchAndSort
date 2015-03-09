/******************************************************************************
* Program Filename: functions.cpp
* Author: Kelvin Watson (OSU ID 932540242)
* Date: 9 February, 2015
* Description: (lab6, CS 162) Implementation for functions.h.
* Input:  See individual member functions.
* Output: See individual member functions.
******************************************************************************/
#include "functions.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::left;
using std::setw;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <cstdlib>
#include <string>
using std::string;
#include <vector>
using std::vector;

/******************************************************************************
* Function: void showIntro()
* Description: Clears the screen and displays the title.
* Parameters:  No parameters.
* Pre-Conditions: Called by main() function.
* Post-Conditions: Displays the title to the console.
******************************************************************************/
void showIntro()
{
  system("clear");
  cout << "*******************" << endl;
  cout << "* SEARCH AND SORT *" << endl;
  cout << "*******************" << endl;
}


/******************************************************************************
* Function: void showMenu()
* Description: Displays menu of options.
* Parameters:  No parameters.
* Pre-Conditions: Called by main() function.
* Post-Conditions: Displays the menu to the console.
******************************************************************************/
void showMenu()
{
  cout << endl << "Please enter a command: " << endl << endl;
  cout << left << setw(9) << "COMMAND" << left << "DESCRIPTION"
  << endl;
  cout << left << setw(9) << "L" << left << "Linear search for the integer 5" 
  " in four input files" << endl;
  cout << left << setw(9) << "S" << left << "Selection sort integers from four"
  " input files" << endl;
  cout << left << setw(9) << "B" << left << "Binary search for the integer 5"
  " in a sorted text file" << endl;
  cout << left << setw(9) << "Q" << left << "Exit program" << endl;
  cout << "--------------------------------------------------------------" << endl;
}


/******************************************************************************
* Function: string getCommand()
* Description: Gets and validates user command choice.
* Parameters:  No parameters.
* Pre-Conditions: Called by main() function. Takes string input from keyboard.
* Post-Conditions: Returns the user's command choice.
******************************************************************************/
string getCommand()
{
  string choice;
  cout << endl << "Please enter a command from the menu above: ";
  getline(cin,choice);
  while (choice != "L" && choice != "S"
  && choice != "B" && choice != "Q")
  {
    if (choice.empty())
      cout << "Empty command. Please re-enter: ";
    else
      cout << "Invalid command. Please re-enter: ";
    choice.clear();
    getline(cin,choice);
  }
  return choice;
}


/******************************************************************************
* Function: void searchForZero()
* Description: Uses a linear search algorithm to search for the integer 0 in
*   four input files.
* Parameters:  No parameters.
* Pre-Conditions: Called by main() function.
* Post-Conditions: Performs a linear search to find the integer 0 in four
*   input files.
******************************************************************************/
void searchForZero()
{
  cout << endl << "Searching for the integer 5 in early.txt" << endl;
  ifstream early("early.txt");
  ifstream middle("middle.txt");
  ifstream end("end.txt");
  ifstream nofive("nofive.txt");  
  
  if (!early || !middle || !end || !nofive)
  {
    cout << "Error opening file(s) or file(s) does not exist.";
    exit(EXIT_FAILURE);
  }

  int input = 0;
  vector<int> integers; 
  
  while(early>>input) //read values into vector
  {
    integers.push_back(input);
  }
  early.clear();
  bool found = false;
  for(unsigned int i=0; i<integers.size(); i++)
  {
    if (integers[i] == 0)
      found = true;
    else continue;
  }
  if(found==true)
    cout << "  0 found in early.txt" << endl;
  else if(found==false)
    cout << "  0 not found in early.txt" << endl;
  integers.clear(); //clear the vector

  cout << endl << "Searching for the integer 5 in middle.txt" << endl;
  while(middle>>input) //read values into vector
  {
    integers.push_back(input);
  }
  middle.clear();
  found = false;
  for(unsigned int i=0; i<integers.size(); i++)
  {
    if (integers[i] == 0)
      found = true;
    else continue;
  }
  if(found==true)
    cout << "  0 found in middle.txt" << endl;
  else if(found==false)
    cout << "  0 not found in middle.txt" << endl;
  integers.clear(); //clear the vector

  cout << endl << "Searching for the integer 5 in end.txt" << endl;
  while(end>>input) //read values into vector
  {
    integers.push_back(input);
  }
  end.clear();
  found = false;
  for(unsigned int i=0; i<integers.size(); i++)
  {
    if (integers[i] == 0)
      found = true;
    else continue;
  }
  if(found==true)
    cout << "  0 found in end.txt" << endl;
  else if(found==false)
    cout << "  0 not found in end.txt" << endl;
  integers.clear(); //clear the vector

  cout << endl << "Searching for the integer 5 in nofive.txt" << endl;
  while(nofive>>input) //read values into vector
  {
    integers.push_back(input);
  }
  nofive.clear();
  found = false;
  for(unsigned int i=0; i<integers.size(); i++)
  {
    if (integers[i] == 0) 
      found = true;
    else continue;
  }
  if(found==true)
    cout << "  0 found in nofive.txt" << endl;
  else if(found==false)
    cout << "  0 not found in nofive.txt" << endl;
  integers.clear(); //clear the vector

  
  early.clear();
  middle.clear();
  end.clear();
  nofive.clear();

  early.close();
  middle.close();
  end.close();
  nofive.close();
}


/******************************************************************************
* Function: void prepSort()
* Description: Opens four input files and inputs their integers into a vector,
*   which is passed to the selectionSort() function for sorting. 
* Parameters:  No parameters.
* Pre-Conditions: Called by main() function.
* Post-Conditions: Four input files are opened and passed to the 
*   selectionSort() function for sorting.
******************************************************************************/
void prepSort()
{
  ifstream early("early.txt");
  ifstream middle("middle.txt");
  ifstream end("end.txt");
  ifstream nofive("nofive.txt");  
  
  if (!early || !middle || !end || !nofive)
  {
    cout << "Error opening file(s) or file(s) does not exist.";
    exit(EXIT_FAILURE);
  }

  int input = 0;
  vector<int> integers; 
  string filename;

  while(early>>input) //read values into vector
  {
    integers.push_back(input);
  }
  early.clear();
  selectionSort(integers);  
  cout << endl << "Please enter a filename (format abc.txt) to save the sorted"
  " integers from early.txt: ";
  filename.clear();
  getline(cin,filename);
  ofstream outFile1(filename.c_str());
  for(unsigned int i=0; i<integers.size(); i++)
    outFile1 << integers[i] << " ";
  integers.clear();
  outFile1.close();
  cout << "  Integers from early.txt successfully sorted and written to " 
  << filename << endl;
  
  while(middle>>input) //read values into vector
  {
    integers.push_back(input);
  }
  middle.clear();
  selectionSort(integers);
  cout << endl << "Please enter a filename (format abc.txt) to save the sorted"
  " integers from middle.txt: ";
  filename.clear();
  getline(cin,filename);
  ofstream outFile2(filename.c_str());
  for(unsigned int i=0; i<integers.size(); i++)
    outFile2 << integers[i] << " ";
  integers.clear();
  outFile2.close();
  cout << "  Integers from middle.txt successfully sorted and written to " 
  << filename << endl;
  
  while(end>>input) //read values into vector
  {
    integers.push_back(input);
  }
  end.clear();  
  selectionSort(integers);
  cout << endl << "Please enter a filename (format abc.txt) to save the sorted"
  " integers from end.txt: ";
  filename.clear();
  getline(cin,filename);
  ofstream outFile3(filename.c_str());
  for(unsigned int i=0; i<integers.size(); i++)
    outFile3 << integers[i] << " ";
  integers.clear();
  outFile3.close();
  cout << "  Integers from end.txt successfully sorted and written to " 
  << filename << endl;  

  while(nofive>>input) //read values into vector
  {
    integers.push_back(input);
  }
  nofive.clear();
  selectionSort(integers);
  cout << endl << "Please enter a filename (format abc.txt) to save the sorted"
  " integers from nofive.txt: ";
  filename.clear();
  getline(cin,filename);
  ofstream outFile4(filename.c_str());
  for(unsigned int i=0; i<integers.size(); i++)
    outFile4 << integers[i] << " ";
  integers.clear();
  outFile4.close();
  cout << "  Integers from nofive.txt successfully sorted and written to " 
  << filename << endl;
}


/******************************************************************************
* Function: void selectionSort(vector<int>& ints)
* Description: Performs a selection sort on a vector of integers
* Parameters: Takes of vector of integers by reference.
* Pre-Conditions: Called by the prepSort() function.
* Post-Conditions: Sorts a vector's integers in ascending order.
******************************************************************************/
void selectionSort(vector<int>& ints)
{
  unsigned int startScan;
  int minIndex, minValue;
  for(startScan = 0; startScan < (ints.size()-1); startScan++)
  {
    minIndex = startScan;
    minValue = ints[startScan];
    for(unsigned int index = startScan+1; index < ints.size(); index++)
    {
      if(ints[index] < minValue)
      {
        minValue = ints[index];
        minIndex = index;
      }
    }
    ints[minIndex] = ints[startScan];
    ints[startScan] = minValue;
  }
}


/******************************************************************************
* Function: void binarySearch()
* Description: Opens a text file containing integers in ascending order, inputs
*   integers into a vector and performs a binary search for the integer 5.
* Parameters: No parameters.
* Pre-Conditions: Called by the main() function.
* Post-Conditions: Performs a binary search for the integer 5 in a vector of
*   integers. No values returned.
******************************************************************************/
void binarySearch()
{
  ifstream sorted("sorted.txt");
  if (!sorted)
  {
    cout << "Error opening file sorted.txt";
    exit(EXIT_FAILURE);
  }
  int input = 0;
  vector<int> integers;
  integers.clear(); 
  string filename;

  while(sorted >> input) //read values into vector
  {
    integers.push_back(input);
  }
  sorted.clear();

  int low = 0;
  int high = integers.size()-1;
  bool found = false;
  while(low <= high)
  {
    int middle = (low+high)/2;
    int difference = integers[middle] - 5;
    if(difference==0)
    {  
      found = true;
      break;
    }
    else if (difference < 0)
    {
      low = middle + 1;
      found = false;
    }
    else
    {
      high = middle - 1;
      found = false;
    }
  }
  if(found==false)
    cout << endl << "  The integer 5 was not found via binary search." << endl;
  else if(found==true)
    cout << endl << "  The integer 5 was found via binary search." << endl;
  sorted.close();  
}
