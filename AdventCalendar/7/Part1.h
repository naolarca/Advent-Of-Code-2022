#pragma once
#include <iostream>


class PartOne
{
private:
	std::string inputFilename;
	std::string outputFilename;
	

	std::string cd;
	std::string command;
	std::string directory;

	bool isNode(std::string dir);
	void openFile();
	void writeFile(std::string line);

public:
	PartOne(std::string filename);

};

