#include "Part2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PartTwo::PartTwo(std::string filename) {
	inputFilename = filename;
	lenghtLine = 0;
	totalsum = 0;

	openFile();
}


void PartTwo::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	std::string inputText = "";

	std::string temp2, tempR1, tempR2;

	std::stringstream ss;

	int un, deux, trois, quatre = 0;


	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile, inputText)) {
		inputText += "\n";


		//longueur string line
		lenghtLine = inputText.length();

		//separe line en deux sections
		for (int i = 0; i < lenghtLine; i++)
		{
			if (inputText[i] == ',')
			{
				first = temp2;
				temp2 = "";
			}
			else if (inputText[i] == '\n')
			{
				second = temp2;
				temp2 = "";
			}
			else temp2 += inputText[i];

		}



		//first range
		for (int j = 0; j < first.length(); j++)
		{
			if (first[j] == '-')
			{
				frangeI = tempR1;
				tempR1 = "";
			}
			else if (j == first.length() - 1)
			{
				frangeF = tempR1 + first[j];
				tempR1 = "";
			}
			else tempR1 += first[j];
		}



		//second range
		for (int k = 0; k < second.length(); k++)
		{
			if (second[k] == '-')
			{
				srangeI = tempR2;
				tempR2 = "";
			}
			else if (k == second.length() - 1)
			{
				srangeF = tempR2 + second[k];
				tempR2 = "";
			}
			else tempR2 += second[k];
		}


		//on sassure que un deux trois quatre sont a zero
		un = 0;
		deux = 0;
		trois = 0;
		quatre = 0;

		//conversion en int
		//1
		ss << frangeI;
		ss >> un;
		ss.clear();

		//2
		ss << frangeF;
		ss >> deux;
		ss.clear();

		//3
		ss << srangeI;
		ss >> trois;
		ss.clear();

		//4
		ss << srangeF;
		ss >> quatre;
		ss.clear();

		//std::cout << un << " " << deux <<" "<<trois<<" "<<quatre<< "\n";

		if (isOverlap(un, deux, trois, quatre))
		{
			totalsum += 1;
		}

		//on remet a zero
		temp2 = "";
		tempR1 = "";
		tempR2 = "";

		frangeI = "";
		frangeF = "";
		srangeI = "";
		srangeF = "";

		lenghtLine = 0;


	}


	std::cout << totalsum;

	// Close the file
	MyReadFile.close();
}

bool PartTwo::isOverlap(int one, int two, int three, int four)
{
	//si premier range overlap pas deuxieme range (one est plus petit que three et two est plus petit que four)
	//OU
	//si deuxieme range overlap pas premier range (one est plus grand que three et two est plus grand que four)
	//alors is overlappas
	if (((one < three) && (one < four) && (two<three) && (two<four)) || ((one > three) && (one > four) && (two > three) && (two>four))) return false;


	return true;
}
