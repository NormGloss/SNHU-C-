/*
Project Three
CS-210 SNHU
Norman Gloss
June 23, 2024
A program to track items sold using an input file.  The program will sort and display various item data
and backup that data to a save file.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include "FileProcess.h"

using namespace std;
using std::cout;


int main() {
	int choice = 0;
	string item;
	FileProcess file1; //Instantiates an object of class type FileProcess

	file1.BuildMap();

	//Loop to keep cycling until user enters 4 to quit
	while (choice != 4) {
		//Display menu
		cout << "*****************************" << endl;
		cout << "*Corner Grocer Item tracking*" << endl;
		cout << "*****************************" << endl;
		cout << endl;
		cout << "Please choose one of the following options." << endl;
		cout << "*******************************************" << endl;
		cout << "1. Get the total for a specific item." << endl;
		cout << "2. Get a list of all items purchased with individual totals." << endl;
		cout << "3. Get a histogram of purchases for all items." << endl;
		cout << "4. Exit the application" << endl;
		cout << endl;

		//Take user choice
		cout << "Please enter your selection: ";
		cin >> choice;
		cout << endl;

		//Handle user input and return selcted output
		switch (choice) {
		case 1:
			cout << "Please enter the item you're searching for: ";
			cin >> item;
			file1.GetIndividual(item);
			break;
		case 2:
			file1.GetAll();
			break;
		case 3:
			file1.GetHistogram();
			break;
		case 4:
			cout << "Goodbye";
			break;
		default:
			cout << " Invalid selction!";
			cin.clear();
			cin.ignore(1000, '\n');
			break;
		}
		cout << endl;
		cout << endl;
	}
	
	return 0;
}