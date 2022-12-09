#pragma once
#include <iostream>


class PartTwo
{
private:
	std::string inputFilename;
	int rockValue;
	int paperValue;
	int scissorValue;

	int lost;
	int draw;
	int win;

	int lineScore;
	long totalScore;

	void openFile();


public:
	PartTwo(std::string filename);
};

