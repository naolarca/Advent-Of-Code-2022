#include "Part1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PartOne::PartOne(std::string filename) {
	inputFilename = filename;
	
	letter1=' ';
	letter2=' ';
	letter3=' ';
	letter4=' ';

	position=0;

	openFile();
}


void PartOne::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	std::string inputText="";
	
	bool isChanged = false;


	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile,inputText)) {
		
		//longueur string line
		int lenghtLine = inputText.length();

		
		for (int i = 0; i < lenghtLine - 3; i++)
		{
			letter1 = inputText[i];
			letter2 = inputText[i+1];
			letter3 = inputText[i+2];
			letter4 = inputText[i+3];

			if (letter1 != letter2 && letter1 != letter3 && letter1 != letter4)
			{
				if (letter2 != letter3 && letter2 != letter4 && letter3 != letter4)
				{
					if (isChanged == false)
					{
						//+1 pcq position ne commence pas a zero comme i et +3 car on veut connaitre le nombre de lettre avant le marker
						position = i+4;
						isChanged = true;
						//std::cout << "THIS ONE!!!!!\n";
					}
					else isChanged = true;
				}
			}
	
		}


		
		
	}

	std::cout << position<<"\n";
	//std::cout << inputText[position-4] << inputText[position-3] << inputText[position-2] << inputText[position-1];

	// Close the file
	MyReadFile.close();
}

