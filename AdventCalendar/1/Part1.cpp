#include "Part1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PartOne::PartOne(std::string filename) {
	inputFilename = filename;
	mostCalories = 0;
	openFile();
}


void PartOne::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	std::string inputText="";
	std::string calorie = "";
	std::stringstream ss;

	int sommeCalories=0;
	int intCalorie;
	

	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile,inputText)) {
		inputText += '\n';
		
		//si ligne est vide
		if(inputText == "\n")
		{
		

			//regarde si somme plus grande que biggest Calories
			//si oui remplace biggest Calories par la somme
			if (isBigger(sommeCalories))
			{
				mostCalories = sommeCalories;
			}

			//on remet valeur de calorie a null et somme a zero
			calorie = "";
			sommeCalories = 0;
			intCalorie = 0;
			

		}

		//si ligne nest pas vide
		else
		{
			//on rajoute calorie
			calorie += inputText;
			//met dans stringstram
			ss << calorie;
			//change en int
			ss >> intCalorie;
			

			//clear everything
			ss.clear();
			calorie = "";

			//on ajoute le int a la somme
			sommeCalories += intCalorie;
			intCalorie = 0;

		}
		
	}

	cout << mostCalories;


	// Close the file
	MyReadFile.close();
}

bool PartOne::isBigger(int inputNumber) {
	return inputNumber >= mostCalories;
}
