// AdventCalendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Part1.h"
#include "Part2.h"

using namespace std;

int main()
{
	string filename = "inputCalories.txt";

	//TEST DAY ONE
	cout << "TEST DAY ONE:\n";
	cout << "====================================================================================\n";
	cout << "PART ONE...\n";
	cout << "The elf with the most calories has a total of \n";
	PartOne PartOneTest(filename);
	cout << " calories!\n\n";

	//TEST DAY TWO
	cout << "PART TWO\n";
	cout << "The three elves with the most calories have a total of \n";
	PartTwo PartTwoTest(filename);
	cout << " calories!\n\n";

	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
