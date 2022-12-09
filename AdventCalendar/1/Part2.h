#pragma once
#include <iostream>


class PartTwo
{
private:
	std::string inputFilename;
	int mostCalories;
	int secondMostCalories;
	int thirdMostCalories;

	void openFile();
	bool isBiggerFirst(int inputNumber);
	bool isBiggerSecond(int inputNumber);
	bool isBiggerThird(int inputNumber);
	

public:
	PartTwo(std::string filename);
};

