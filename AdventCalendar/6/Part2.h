#pragma once
#include <iostream>


class PartTwo
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

	std::string movedLetter;

	std::string retrieve(std::string stack, int howmany);
	std::string add(std::string stack, std::string letter);

	void openFile();

public:
	PartTwo(std::string filename);

};

