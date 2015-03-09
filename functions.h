/******************************************************************************
* Program Filename: functions.h
* Author: Kelvin Watson (OSU ID 932540242)
* Date: 9 February, 2015
* Description: (lab6, CS 162) Interface for functions.cpp. Attributes
*     and behaviors (prototypes) are listed.
* Input: See implementation (functions.cpp) file.
* Output: See implementation (functions.cpp) file.
******************************************************************************/
#ifndef WATSOKEL_FUNCTIONS_H
#define WATSOKEL_FUNCTIONS_H

#include <string>
using std::string;
#include <vector>
using std::vector;

void showIntro();
void showMenu();
string getCommand();
void searchForZero();
void prepSort();
void selectionSort(vector<int>&);
void binarySearch();

#endif
