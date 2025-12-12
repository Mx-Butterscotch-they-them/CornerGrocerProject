/*
* Author: Alex Lancaster
*
* What I go by: Anything but she/her, he/him, it/its, and just solely my name.
*
* Purpose: Contains the body of the ItemTracker class.
* ItemTracker allows users to search for items, display item frequency and print it into another file,
* display item frequency in the form of a histogram and print it into another file,
* change the input file containing the items to another file,
* and change the name of the output file containing the results.
* This class is designed to work with files only, but may be expanded in further updates.
*
* Date last updated: 12/11/2025
*/

#include "ItemTracker.h"

using namespace std;

ItemTracker::ItemTracker() {
	cout << "Default constructor activated" << endl;
	this->itemName = "";
	this->fileInputName = "";
	this->fileOutputName = "";
}

ItemTracker::ItemTracker(string const& fileInputName, string const& fileOutputName) {
	cout << "Constructor 2 param activated" << endl;
	this->fileInputName = fileInputName;
	this->fileOutputName = fileOutputName;
	this->itemName = "";
}

int ItemTracker::ItemSearch(const string& itemName) {
	cout << "ItemSearch() opened!" << endl;
	string word = "";
	int wordFrequency = 0;

	//Open input and output files and check if files are opened
	ifstream inputFile(this->fileInputName);
	ofstream outputFile(this->fileOutputName, ios::app);

	//Check if files are opened 
	if (!inputFile.is_open()) {
		cerr << "Error opening input file stream!" << endl;
		return -1;
	}

	if (!outputFile.is_open()) {
		cerr << "Error opening output file stream!" << endl;
		return -1;
	}

	//Analyze file data
	while (getline(inputFile, word)) {
		if (!word.compare(itemName)) {
			wordFrequency++;
		}
	}

	//Output into another file
	outputFile << word << " " << wordFrequency << endl;

	//Close files
	inputFile.close();
	outputFile.close();

	return wordFrequency;
}

void ItemTracker::PrintItemFrequency() {
	cout << "PrintItemFrequency() opened!" << endl;

}

void ItemTracker::PrintItemHistogram() {
	cout << "PrintItemHistogram() opened!" << endl;
}

void ItemTracker::ExitProgram() {
	cout << endl << endl << "Exiting program!" << endl << endl;


}

//Menu demo for the class ItemTracker; Menu() may be deleted without any consequence since it is an independent component
void ItemTracker::Menu() {
	string usersOption = "-1";
	string word = "";
	int itemTotal = -1;
	
	//Allows exception handling of cin input stream
	cin.exceptions(std::istream::failbit | std::istream::badbit);

	//Menu loop with options 1 to 7 to select
	do {
		try {
			//FIXME: Add way for users to input their choice, sanitize their input, and throw exceptions when relevant
			//FIXME: 

			cout << endl << endl << "******************************Item Tracker******************************" << endl
				<< "Current input file: " << GetFileInputName() << endl << endl
				<< "Current output file: " << GetFileOutputName() << endl << endl
				<< "Options:" << endl << endl
				<< "Enter [1] to search for a specific item based on specified item name and print out the frequency of that item" << endl << endl
				<< "Enter [2] to set the item name" << endl << endl
				<< "Enter [3] to print item frequency of each unique type of item" << endl << endl
				<< "Enter [4] to print item frequency of each unique type of item in the form of a histogram" << endl << endl
				<< "Enter [5] to enter the file name with its file extension you'd like to pull item info from" << endl << endl
				<< "Enter [6] to enter the file name with its file extension you'd like to place the results into" << endl << endl
				<< "Enter [7] to exit the program" << endl
				<< "*************************************************************************" << endl
				<< "Enter input here: ";

			getline(cin, usersOption);

			//Check if users inputted options 1 to 7, otherwise loops until they enter 7
			if (usersOption.compare("1") == 0) {
				itemTotal = ItemSearch(word);
				if (itemTotal == -1) {
					cout << endl << "Item" << GetItemName() << " not found" << endl << endl;
				}
				else {
					cout << endl << endl << "Total frequency for item " << GetItemName() << ": " << itemTotal << endl << endl;
				}
				itemTotal = -1;
			}
			else if (usersOption.compare("2") == 0) {
				cout << endl << "Set item name: ";
				getline(cin, word);
				SetItemName(word);
			}
			else if (usersOption.compare("3") == 0) {
				PrintItemFrequency();
			}
			else if (usersOption.compare("4") == 0) {
				PrintItemHistogram();
			}
			else if (usersOption.compare("5") == 0) {
				cout << endl << "Set input file name: ";
				getline(cin, this->fileInputName);
				SetFileInputName(fileInputName);
			}
			else if (usersOption.compare("6") == 0) {
				cout << endl << "Set output file name: ";
				getline(cin, this->fileOutputName);
				SetFileOutputName(fileOutputName);
			}
			else if (usersOption.compare("7") == 0) {
				ExitProgram();
			}
			else {
				cout << endl << endl << "Error! Input is not valid!" << endl << endl;
			}
		}
		catch (const ios_base::failure& e) {
			cout << endl << endl << "Input failed: " << e.what() << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch (const exception& e) {
			cout << endl << endl << e.what() << endl << endl;
		}
		catch (...) {
			cout << endl << endl << "Unknown exception caught" << endl << endl;
		}
	} while (!(usersOption.compare("7") == 0));
}

//Getters and Setters

/** Sets the item name
* @param itemName: The item name
* @return void
*/
void ItemTracker::SetItemName(const string& itemName) {
	this->itemName = itemName;
}

/** Gets the item name
* @param None
* @return itemName
*/
string ItemTracker::GetItemName() const {
	return this->itemName;
}

/** Sets the input file name; closes file input stream, sets new input file name, opens file input stream
* @param fileInputName: The input file name
* @return void
*/
void ItemTracker::SetFileInputName(const string& fileInputName) {
	this->fileInputName = fileInputName;
}

/** Gets the input file name
* @param None
* @return fileInputName
*/
string ItemTracker::GetFileInputName() const {
	return this->fileInputName;
}

/** Sets the output file name; closes file output stream, sets new output file name, opens file output stream
* @param fileOutputName: the output file name
* @return void
*/
void ItemTracker::SetFileOutputName(const string& fileOutputName) {
	this->fileOutputName = fileOutputName;
}

/** Gets the output file name
* @param None
* @return fileOutputName
*/
string ItemTracker::GetFileOutputName() const {
	return this->fileOutputName;
}
