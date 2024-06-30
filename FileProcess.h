/*
Project Three
CS-210 SNHU
Norman Gloss
June 23, 2024
A program to track items sold using an input file.  The program will sort and display various item data
and backup that data to a save file.
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class FileProcess
{
public:
	void BuildMap();	//Reads input file, creates map, and writes output file
	void GetIndividual(string userItem);	//Prints information for individual items
	void GetAll();	//Prints all items and totals
	void GetHistogram();	 //Prints all items and histogram

private:
	ifstream inFS;
	ofstream outFS;
	string item;
	map<string, int> ItemFrequency;



};

