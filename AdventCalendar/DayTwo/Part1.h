#pragma once
#include <iostream>


class PartOne
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
	int addition();
	

public:
	PartOne(std::string filename);
};

