#pragma once
#include <iostream>


class PartTwo
{
private:
	std::string inputFilename;

	std::string packet14;

	int position;

	bool isUnique(std::string packet);
	void openFile();

public:
	PartTwo(std::string filename);

};

