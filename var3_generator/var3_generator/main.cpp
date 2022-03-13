#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <ctime>
#include <random>
using namespace std;

void input(int& value, const char* prompt) {
	std::cout << prompt << std::endl;
	do
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(UINT32_MAX, '\n');
		}
		cin >> value;
	} while (cin.fail());
}

void pathInput(ofstream& outFile) {
	string outPath;
	do
	{
		cout << "Input file path." << std::endl;
		cin >> outPath;
		outFile.open(outPath);
	} while (!outFile.good());
}

int main() {
	std::cout << "Welcome to input file generator." << std::endl;
	int length;
	input(length, "Please input the length of your file.");
	int maxVal;
	input(maxVal, "Please input max random value.");
	ofstream file;
	pathInput(file);
	for (int i = 0; i < length; i++)
	{
		file << std::rand() % maxVal + 1 << " ";
	}
	return 0;
}