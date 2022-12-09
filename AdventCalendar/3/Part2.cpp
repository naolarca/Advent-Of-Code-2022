#include "Part2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PartTwo::PartTwo(std::string filename) {
	inputFilename = filename;
	rockValue = 1;
	paperValue = 2;
	scissorValue = 3;

	lost = 0;
	draw = 3;
	win = 6;

	lineScore = 0;
	totalScore = 0;

	openFile();
}


void PartTwo::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	std::string inputText = "";
	std::string column1 = "";
	std::string column2 = "";

	std::stringstream ss;

	int sommeCalories = 0;
	int intCalorie;


	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile, inputText)) {

		//si ligne contient A (ROCK)
		if (inputText.find('A') != string::npos) {

			//si ligne contient egalement X (LOST)
			if (inputText.find('X') != string::npos) {
				lineScore += scissorValue;
				lineScore += lost;
			}
			//si ligne contient egalement Y (DRAW)
			if (inputText.find('Y') != string::npos) {
				lineScore += rockValue;
				lineScore += draw;
			}
			//si ligne contient egalement Z (WIN)
			if (inputText.find('Z') != string::npos) {
				lineScore += paperValue;
				lineScore += win;
			}
		}
		//si ligne contient B (PAPER)
		else if (inputText.find('B') != string::npos) {

			//si ligne contient egalement X (LOST)
			if (inputText.find('X') != string::npos) {
				lineScore += rockValue;
				lineScore += lost;
			}
			//si ligne contient egalement Y (DRAW)
			if (inputText.find('Y') != string::npos) {
				lineScore += paperValue;
				lineScore += draw;
			}
			//si ligne contient egalement Z (WIN)
			if (inputText.find('Z') != string::npos) {
				lineScore += scissorValue;
				lineScore += win;
			}
		}
		//si ligne contient C (SCISSOR)
		else if (inputText.find('C') != string::npos) {

			//si ligne contient egalement X (LOST)
			if (inputText.find('X') != string::npos) {
				lineScore += paperValue;
				lineScore += lost;
			}
			//si ligne contient egalement Y (DRAW)
			if (inputText.find('Y') != string::npos) {
				lineScore += scissorValue;
				lineScore += draw;
			}
			//si ligne contient egalement Z (WIN)
			if (inputText.find('Z') != string::npos) {
				lineScore += rockValue;
				lineScore += win;
			}
		}
		//sinon error
		else cout << "error";

		totalScore += lineScore;
		lineScore = 0;


	}


	cout << totalScore;

	// Close the file
	MyReadFile.close();
}
