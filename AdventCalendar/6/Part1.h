#pragma once
#include <iostream>


class PartOne
{
private:
	std::string inputFilename;
	

	char letter1;
	char letter2;
	char letter3;
	char letter4;

	int position;

	void openFile();

public:
	PartOne(std::string filename);

};

