/*
* Author: Alex Lancaster
*
* What I go by: Anything but she/her, he/him, it/its, and just solely my name.
*
* Purpose: Demo of ItemTracker
* ItemTracker allows users to search for items, display item frequency and print it into another file,
* display item frequency in the form of a histogram and print it into another file,
* change the input file containing the items to another file,
* and change the name of the output file containing the results.
* This class is designed to work with files only, but may be expanded in further updates to increase flexibility.
*
* Date last updated: 12/10/2025
*/

#include <iostream>
#include <fstream>

#include "ItemTracker.h"

using namespace std;

int main() {
	auto searchObj = make_unique<ItemTracker>("InputData.txt", "output.txt"); // C++14
	
	//Demo menu showcasing ItemTracker class
	searchObj->Menu();

	return 0;
}

