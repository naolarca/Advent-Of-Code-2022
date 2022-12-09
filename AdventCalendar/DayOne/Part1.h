#pragma once
#include <iostream>


class PartOne
{
private:
	std::string inputFilename;
	int mostCalories;

	void openFile();
	bool isBigger(int inputNumber);
	

public:
	PartOne(std::string filename);
};

