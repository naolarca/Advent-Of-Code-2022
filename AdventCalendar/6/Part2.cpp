#include "Part2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

PartTwo::PartTwo(std::string filename) {
	inputFilename = filename;

	packet14 = "";

	position = 0;

	openFile();
}


void PartTwo::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	std::string inputText = "";

	bool isChanged = false;


	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile, inputText)) {

		//longueur string line
		int lenghtLine = inputText.length();


		for (int i = 0; i < lenghtLine - 13; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				packet14 += inputText[i+j];
			}

			//check if every character is unique
			if (isUnique(packet14))
			{

				if (isChanged == false)
				{
					//+1 pcq position ne commence pas a zero comme i et +13 car on veut connaitre le nombre de lettre AVANT le marker
					position = i + 14;
					isChanged = true;
					//std::cout << "THIS ONE!!!!!\n";
				}
				else isChanged = true;
			}
				
			
			packet14 = "";

		}

		


	}

	std::cout << position << "\n";
	//std::cout << inputText[position-4] << inputText[position-3] << inputText[position-2] << inputText[position-1];

	// Close the file
	MyReadFile.close();
}

bool PartTwo::isUnique(std::string packet)
{
	//on regarde un character par character
	for (int k = 0; k < packet.length(); k++) {
		//on verifie avec tous les autres char du string
		for (int l = k + 1; l < packet.length(); l++) {
			if (packet14[k] == packet14[l]) return false;
		}
	}
	return true;
}

