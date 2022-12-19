#include "Part1.h"
#include <iostream>
#include <ios>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PartOne::PartOne(std::string filename) {
	inputFilename = filename;
	outputFilename = "treeOutput.txt";

	openFile();
}


void PartOne::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	//clear the output before doing anything
	std::ofstream log(outputFilename);
	log.clear();
	log.close();

	std::string inputText="";

	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile,inputText)) {
		
		//longueur string line
		int lenghtLine = inputText.length();

		std::string dir = "";

		int where = 0;

		//COMMANDS
		if (inputText[0] == '$')
		{
			//CD
			if (inputText[2] == 'c' && inputText[3] == 'd')
			{
				

				//OUTERMOST DIRECTORY
				if (inputText[5] == '/')
				{
					writeFile("/\n");
				}

				//GO BACK
				else if (inputText[5] == '.' && inputText[6] == '.') {
					if (where != 0) {
						
						for (int i = 0; i <= where-1; i++)
						{
							dir += "	";
						}
						dir += "\n";
						writeFile(dir);
					}
					else writeFile("\n");
					where--;
				}

				//GO INTO DIRECTORY
				else
				{
					//if is already listed^^ oops
					
					for (int i = 5; i < lenghtLine; i++)
					{
						dir += inputText[i];

					}
					for (int i = 0; i <= where + 1; i++)
					{
						dir += "	";
					}

					dir += "\n	";

					writeFile(dir);
					where++;
				}
			}

			//LS
			else if (inputText[2]=='l' && inputText[3] == 's') {
				//DIR
				if (inputText[5] == 'd' && inputText[6] == 'i' && inputText[7] == 'r')
				{

				}
				//SIZE
				else {
					for (int j = 5; j < lenghtLine; j++)
					{
						dir += inputText[j];
					}
					dir += "\n";

					writeFile(dir);

				}
			}
		}
		

		
		
	}

	//std::cout << position<<"\n";
	//std::cout << inputText[position-4] << inputText[position-3] << inputText[position-2] << inputText[position-1];

	// Close the file
	MyReadFile.close();
}

void PartOne::writeFile(std::string line)
{
	std::ofstream log(outputFilename, std::ios_base::app );

	log << line;

	//log.close();
}

bool PartOne::isNode(std::string dir)
{
	return false;
}

