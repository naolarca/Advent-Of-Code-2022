#include "Part2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const std::string LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
const std::string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

using namespace std;

PartTwo::PartTwo(std::string filename) {
	inputFilename = filename;

	FirstElf = "";
	SecondElf = "";
	ThirdElf = "";

	tempCommon = "";

	linePrioritieValue = 0;
	totalsum = 0;

	openFile();
}


void PartTwo::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	std::string inputText = "";
	//std::string tempCommon = "";

	std::string pack;

	int compteurElves=0;

	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile, inputText)) {

		inputText += "\n";

		pack+= inputText;
		
		compteurElves++;
		
		std::string tempElf = "";

		//regarde si peut etre separee en nouveau paquet de 3
		if (compteurElves%3==0) {
			

			int dumbcmpt = 0;
			
			//separer par paquet de trois elfs
			for (int l = 0; l < pack.length(); l++)
			{
				tempElf += pack[l];

				if (pack[l] == '\n')
				{
					if (dumbcmpt == 0)
					{
						FirstElf = tempElf;
						tempElf = "";
						dumbcmpt++;
					}
					else if (dumbcmpt == 1)
					{
						SecondElf = tempElf;
						tempElf = "";
						dumbcmpt++;
					}
					else if (dumbcmpt == 2)
					{
						ThirdElf = tempElf;
						tempElf = "";
						dumbcmpt = 0;
					}
				}
			}


			//boucle elfe 1
			for (int i = 0; i <= FirstElf.length(); i++)
			{
				//cout << inputText[i];
				//boucle elfe 2
				for (int j = 0; j <= SecondElf.length(); j++)
				{

					//std::cout << inputText[j];
					//boucle elfe 3
					for (int k = 0; k <= ThirdElf.length(); k++)
					{
						//si common in both
						if (FirstElf[i] == SecondElf[j] && FirstElf[i] == ThirdElf[k])
						{
							//tempCommon.clear();
							tempCommon += FirstElf[i];
							
							
						}
					}	
				}
			}
			

			
			//on remet string elves a zero
			FirstElf = "";
			SecondElf = "";
			ThirdElf = "";
			pack = "";

			
		}

		commonC = tempCommon[0];

		//calculer priorite
		linePrioritieValue = getPriorite(commonC);
		
		
		if (linePrioritieValue!=27) totalsum += linePrioritieValue;
		
		tempCommon = "";
		linePrioritieValue = 0;
		


	}


	std::cout << totalsum;

	// Close the file
	MyReadFile.close();
}

int PartTwo::getPriorite(char c)
{
	int tempCompteur = 1;
	//boucle lowercase
	for (int i = 0; i <= LOWERCASE.length(); i++)
	{
		//check if letter is same
		if (c == LOWERCASE[i])
		{
			return tempCompteur;
		}

		tempCompteur++;
	}

	tempCompteur = 27;
	//boucle uppercase
	for (int j = 0; j <= UPPERCASE.length(); j++)
	{
		//check if letter is same
		if (c == UPPERCASE[j])
		{
			return tempCompteur;
		}

		tempCompteur++;

	}

	return -1;
}
