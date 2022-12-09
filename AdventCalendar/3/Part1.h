#pragma once
#include <iostream>


class PartOne
{
private:
	std::string inputFilename;
	
	int lenghtLine;
	int linePrioritieValue;
	int totalsum;

	char commonC;

	void openFile();
	int getPriorite();

public:
	PartOne(std::string filename);

};

