#include "Part2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PartTwo::PartTwo(std::string filename) {
	inputFilename = filename;

	stack1 = "";
	stack2 = "";
	stack3 = "";
	stack4 = "";
	stack5 = "";
	stack6 = "";
	stack7 = "";
	stack8 = "";
	stack9 = "";
	finalCrates = "";

	openFile();
}


void PartTwo::openFile() {
	// Read from the text file
	ifstream MyReadFile(inputFilename);

	std::string inputText = "";
	std::string hm = "";
	std::string f = "";
	std::string t = "";

	std::stringstream ss;

	int howMany = 0;
	int from = 0;
	int to = 0;


	// read the file line by line (takes the file input and put it into a string)
	while (getline(MyReadFile, inputText)) {
		inputText += "\n";



		//longueur string line
		int lenghtLine = inputText.length();


		for (int i = 0; i < lenghtLine; i++)
		{
			//on create stack depart
			if (inputText[i] == '[')
			{
				if (i == 0) stack1 += inputText[i + 1];
				if (i == 4) stack2 += inputText[i + 1];
				if (i == 8) stack3 += inputText[i + 1];
				if (i == 12) stack4 += inputText[i + 1];
				if (i == 16) stack5 += inputText[i + 1];
				if (i == 20) stack6 += inputText[i + 1];
				if (i == 24) stack7 += inputText[i + 1];
				if (i == 28) stack8 += inputText[i + 1];
				if (i == 32) stack9 += inputText[i + 1];
			}

			//on analyse les mouvements demandes
			if (inputText[i] == 'm')
			{
				hm = inputText[5];
				hm += inputText[6];

				for (int j = 5; j < lenghtLine; j++)
				{

					if (inputText[j] == 'f')
					{
						f = inputText[j + 5];
					}
					else if (inputText[j] == 't')
					{
						t = inputText[j + 3];
					}

				}
			}

			//std::cout << hm<< " " << f << " " << t << "\n";
		}

		//on change les string en int
		ss << hm;
		ss >> howMany;
		ss.clear();

		ss << t;
		ss >> to;
		ss.clear();

		ss << f;
		ss >> from;
		ss.clear();

		//std::cout << howMany << " " << from << " " << to << "\n";

		if (howMany != 0)
		{
			
			//on retrieve
			if (from == 1) stack1 = retrieve(stack1, howMany);
			if (from == 2) stack2 = retrieve(stack2, howMany);
			if (from == 3) stack3 = retrieve(stack3, howMany);
			if (from == 4) stack4 = retrieve(stack4, howMany);
			if (from == 5) stack5 = retrieve(stack5, howMany);
			if (from == 6) stack6 = retrieve(stack6, howMany);
			if (from == 7) stack7 = retrieve(stack7, howMany);
			if (from == 8) stack8 = retrieve(stack8, howMany);
			if (from == 9) stack9 = retrieve(stack9, howMany);

			//std::cout << movedLetter << "\n";

			//on add
			if (to == 1) stack1 = add(stack1, movedLetter);
			if (to == 2) stack2 = add(stack2, movedLetter);
			if (to == 3) stack3 = add(stack3, movedLetter);
			if (to == 4) stack4 = add(stack4, movedLetter);
			if (to == 5) stack5 = add(stack5, movedLetter);
			if (to == 6) stack6 = add(stack6, movedLetter);
			if (to == 7) stack7 = add(stack7, movedLetter);
			if (to == 8) stack8 = add(stack8, movedLetter);
			if (to == 9) stack9 = add(stack9, movedLetter);
		}

		f = "";
		t = "";
		hm = "";

		from = 0;
		to = 0;
		howMany = 0;

		movedLetter = "";


	}

	finalCrates += stack1[0];
	finalCrates += stack2[0];
	finalCrates += stack3[0];
	finalCrates += stack4[0];
	finalCrates += stack5[0];
	finalCrates += stack6[0];
	finalCrates += stack7[0];
	finalCrates += stack8[0];
	finalCrates += stack9[0];

	std::cout << finalCrates;

	// Close the file
	MyReadFile.close();
}

std::string PartTwo::retrieve(std::string stack, int howmany) {
	int lenghtInput = stack.length();
	std::string temp = "";


	for (int i = 0; i < howmany; i++)
	{
		movedLetter += stack[i];
	}

	for (int i = howmany; i < lenghtInput; i++)
	{
		temp += stack[i];
	}

	stack = "";
	stack = temp;
	temp = "";
	return stack;

}

std::string PartTwo::add(std::string stack, std::string letter)
{
	int lenghtInput = stack.length();
	std::string temp = "";

	temp += letter;

	for (int i = 0; i < lenghtInput; i++)
	{
		temp += stack[i];
	}
	stack = "";
	stack = temp;
	temp = "";
	return stack;
}
