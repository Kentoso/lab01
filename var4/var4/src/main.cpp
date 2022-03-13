#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../include/array_modifications.h"

void outGreetingsMessage() {
	std::cout << "Lab 1: working with C++ containers (variant 4 {42, 75})" << std::endl;
	std::cout << "Group: K-15" << std::endl;
	std::cout << "Author: Demian Samus" << std::endl;
}

int taskSelector() {
	int task = 0;
	while (true) {
		getValue(task, "Select task (42, 75)");
		if (task == 42 || task == 75)
		{
			return task;
		}
		else {
			std::cout << "This value is not valid." << std::endl;
		}
	}
}

std::string getFilePath(std::string defaultPath) {
	std::string filePath;
	std::getline(std::cin, filePath);
	if (filePath == "") return defaultPath;
	//check if file exists (or is accessible)
	std::ifstream file(filePath.c_str());
	if (file.good()) return filePath;
	else {
		std::cout << "File with the path does not exist." << std::endl;
		return "\0";
	}
}

void inputFileToArray(std::vector<int>& vec) {
	std::string path;
	do
	{
		std::cout << "Input path to the file with numbers. (leave empty to use in.txt)" << std::endl;
		path = getFilePath(".\\in.txt");

	} while (path == "\0");
	std::ifstream inputFile(path);
	std::string value;
	while (inputFile >> value)
	{
		vec.push_back(std::stoi(value));
	}

}

void outputArrayToFile(std::vector<int> vec) {
	std::string outPath;
	do
	{
		std::cout << "Write output file path. (leave empty to use out.txt)" << std::endl;
		std::cin.ignore();
		outPath = getFilePath(".\\out.txt");
	} while (outPath == "\0");
	std::ofstream outputStream(outPath);
	int c = 0;
	for (auto i = vec.begin(); i < vec.end(); i++)
	{
		int element = *i;
		if (c % 5 == 0 && c != 0)
		{
			outputStream << "\n";
		}
		outputStream << std::setw(12) << std::right << element << " ";
		c++;
	}
}

int main() {
	outGreetingsMessage();
	std::vector<int> vec;
	inputFileToArray(vec);
	if (vec.size() == 0)
	{
		return 1;
	}
	int task = taskSelector();
	processArray(task, vec);
	outputArrayToFile(vec);
	std::cout << "Done" << std::endl;
	return 0;
}