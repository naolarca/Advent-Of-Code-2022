#pragma once
#include <iostream>


class PartOne
{
private:
	std::string inputFilename;
	
	//int lenghtLine;

	std::string stack1;
	std::string stack2;
	std::string stack3;
	std::string stack4;
	std::string stack5;
	std::string stack6;
	std::string stack7;
	std::string stack8;
	std::string stack9;

	std::string finalCrates;

	char movedLetter;

	std::string retrieve(std::string stack);
	std::string add(std::string stack, char letter);

	void openFile();

public:
	PartOne(std::string filename);

};

