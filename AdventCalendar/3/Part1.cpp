#include "Part1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const std::string LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
const std::string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

using namespace std;

PartOne::PartOne(std::string filename) {
	inputFilename = filename;
	lenghtLine = 0;
	linePrioritieValue = 0;
	totalsum = 0;

	openFile();
}


void PartOne::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	std::string inputText="";
	

	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile,inputText)) {
		
		//longueur string line
		lenghtLine = inputText.length();

		//boucle compartiment 1 line
		for (int i = 0; i < lenghtLine / 2; i++)
		{
			//cout << inputText[i];
			//boucle compartiment 2 line
			for (int j = lenghtLine/2; j<=lenghtLine; j++)
			{

				//std::cout << inputText[j];
				//si common in both
				if (inputText[i] == inputText[j])
				{
					commonC = inputText[i];
					std::cout << commonC;
				}
				
			}

		}

		std::cout << "\n";

		//calculer priorite
		linePrioritieValue = getPriorite();


		

		totalsum += linePrioritieValue;
		lenghtLine = 0;
		
		
	}

	
	std::cout << totalsum;

	// Close the file
	MyReadFile.close();
}

int PartOne::getPriorite()
{
	int tempCompteur = 1;
	//boucle lowercase
	for (int i = 0; i <= LOWERCASE.length(); i++)
	{
		//check if letter is same
		if (commonC == LOWERCASE[i])
		{
			return tempCompteur;
		}
		
		tempCompteur++;
	}
	
	//boucle uppercase
	for (int j = 0; j <= UPPERCASE.length(); j++)
	{
		//check if letter is same
		if (commonC == UPPERCASE[j])
		{
			return tempCompteur;
		}

		tempCompteur++;

	}

	return -1;
}
