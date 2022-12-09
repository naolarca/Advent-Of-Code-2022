#pragma once
#include <iostream>


class PartTwo
{
private:
	std::string inputFilename;

	int lenghtLine;
	int linePrioritieValue;
	int totalsum;

	std::string FirstElf;
	std::string SecondElf;
	std::string ThirdElf;
	
	std::string tempCommon;
	char commonC;

	void openFile();
	int getPriorite(char c);

public:
	PartTwo(std::string filename);

};

