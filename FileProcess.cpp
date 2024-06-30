/*
Project Three
CS-210 SNHU
Norman Gloss
June 23, 2024
A program to track items sold using an input file.  The program will sort and display various item data
and backup that data to a save file.
*/

#include "FileProcess.h"

void FileProcess::BuildMap() {	//Reads input file, creates map, and writes output file
	//Open the input file
	inFS.open("CS210_Project_Three_Input_File.txt");

	if (!inFS.is_open()) {	//verify file opened
		cout << "File not open!" << endl;
	}	

	//Iterate through file and construct the ItemFrequency map
	while (inFS >> item) {
		ItemFrequency[item]++;
	}

	//Open (or create) output file
	outFS.open("frequency.dat");

	if (!outFS.is_open()) {	//Verifiy output file is open
		cout << "File not open!" << endl;
	}
	for (auto e : ItemFrequency) {	//Write the map to the output file
		outFS << e.first << " " << e.second << endl;

	}
	//Close the file streams
	inFS.close();
	outFS.close();
}

void FileProcess::GetIndividual(string userItem) {	//Prints information for individual items
	item = userItem;
	item[0] = toupper(item[0]);
	cout << endl;
	if (ItemFrequency.find(item) != ItemFrequency.end()) {	//Verifies input is a key
		cout << "The total amount of " << item << " sold is: " << ItemFrequency.at(item);
	}
	else {
		cout << "Item not found!";
	}
}

void FileProcess::GetAll() {	//Prints all items and totals
	for (auto e : ItemFrequency) {
		cout << e.first << " " << e.second << endl;
	}
}

void FileProcess::GetHistogram() {//Prints all items and histogram
	for (auto e : ItemFrequency) {
		cout << e.first << " ";
		for (int i = 0; i < ItemFrequency.at(e.first); i++) {
			cout << "*";
		}
		cout << endl;
	}
}