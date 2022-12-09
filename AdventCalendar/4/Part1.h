#pragma once
#include <iostream>


class PartOne
{
private:
	std::string inputFilename;
	
	int lenghtLine;
	std::string first;
	std::string frangeI;
	std::string frangeF;

	std::string second;
	std::string srangeI;
	std::string srangeF;

	int totalsum;


	void openFile();
	bool isFullyContained(int one, int two, int three, int four);

public:
	PartOne(std::string filename);

};

