#include "Part2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PartTwo::PartTwo(std::string filename) {
	inputFilename = filename;
	mostCalories = 0;
	secondMostCalories = 0;
	thirdMostCalories = 0;
	openFile();
}


void PartTwo::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	std::string inputText="";
	std::string calorie = "";
	std::stringstream ss;

	int sommeCalories=0;
	int sommeThirdBests = 0;
	int intCalorie;
	

	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile,inputText)) {
		inputText += '\n';
		
		//si ligne est vide
		if(inputText == "\n")
		{
		

			//regarde si somme plus grande que biggest Calories
			//si oui remplace biggest Calories par la somme
			//decalage ajouter pour trois premieres positions
			if (isBiggerFirst(sommeCalories))
			{
				thirdMostCalories = secondMostCalories;
				secondMostCalories = mostCalories;
				mostCalories = sommeCalories;
			}
			else if (isBiggerSecond(sommeCalories))
			{
				thirdMostCalories = secondMostCalories;
				secondMostCalories = sommeCalories;
			}
			else if (isBiggerThird(sommeCalories))
			{
				thirdMostCalories = sommeCalories;
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

	sommeThirdBests = mostCalories + secondMostCalories + thirdMostCalories;
	cout << sommeThirdBests;


	// Close the file
	MyReadFile.close();
}

bool PartTwo::isBiggerFirst(int inputNumber) {
	return inputNumber >= mostCalories;
}

bool PartTwo::isBiggerSecond(int inputNumber) {
	return inputNumber >= secondMostCalories;
}

bool PartTwo::isBiggerThird(int inputNumber) {
	return inputNumber >= thirdMostCalories;
}
