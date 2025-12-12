/*
* Author: Alex Lancaster
*
* What I go by: Anything but she/her, he/him, it/its, and just solely my name.
*
* Purpose: Contains the structure of the ItemTracker class.
* ItemTracker allows users to search for items, display item frequency and print it into another file,
* display item frequency in the form of a histogram and print it into another file,
* change the input file containing the items to another file,
* and change the name of the output file containing the results.
* This class is designed to work with files only, but may be expanded in further updates.
*
* Date last updated: 12/11/2025
*/

#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class ItemTracker {
public:
	ItemTracker();
	ItemTracker(string const& fileInputName = "", string const& fileOutputName = "");
	int ItemSearch(const string& itemName);
	void PrintItemFrequency();
	void PrintItemHistogram();
	void ExitProgram();
	void Menu();

	//Getters and setters
	void SetItemName(const string& itemName);
	string GetItemName() const;

	void SetFileInputName(const string& fileInputName);
	string GetFileInputName() const;

	void SetFileOutputName(const string& fileOutputName);
	string GetFileOutputName() const;

private:
	string fileInputName;
	string fileOutputName;
	string itemName;
};

#endif
