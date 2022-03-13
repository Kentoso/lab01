#include <iostream>
#include <fstream>
#include <iomanip>
#include "../include/array_modifications.h"

void outGreetingsMessage() {
	std::cout << "Lab 1: working with C++ containers (variant 3 {42, 75})" << std::endl;
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

void inputFileToArray(int*& arrStart, int*& workAreaEnd, int*& arrEnd) {
	std::string path;
	do
	{
		std::cout << "Input path to the file with numbers. (leave empty to use in.txt)" << std::endl;
		path = getFilePath(".\\in.txt");

	} while (path == "\0");
	std::ifstream inputFile(path);
	int i = 0;
	std::string value;
	bool is = inputFile.good();
	while (inputFile >> value)
	{
		if (workAreaEnd == arrEnd)
		{
			doubleArray(arrStart, ++workAreaEnd, arrEnd);
		}
		else
		{
			workAreaEnd++;
		}
		arrStart[i] = std::stoi(value);
		i++;
	}

}



void outputArrayToFile(int*& arrStart, int*& workAreaEnd, int*& arrEnd) {
	std::string outPath;
	do
	{
		std::cout << "Write output file path. (leave empty to use out.txt)" << std::endl;
		std::cin.ignore();
		outPath = getFilePath(".\\out.txt");
	} while (outPath == "\0");
	std::ofstream outputStream(outPath);
	for (int i = 0; i < workAreaEnd - arrStart; i++)
	{
		if (i % 5 == 0 && i != 0)
		{
			outputStream << "\n";
		}
		outputStream << std::setw(12) << std::right << arrStart[i] << " ";
	}
}

int main() {
	outGreetingsMessage();
	int* arrStart = new int[100];
	int* workAreaEnd = arrStart;
	int* arrEnd = arrStart + 100;
	try
	{
		inputFileToArray(arrStart, workAreaEnd, arrEnd);
		if (arrStart == workAreaEnd)
		{
			return 1;
		}
		int task = taskSelector();
		processArray(task, arrStart, workAreaEnd, arrEnd);
	}
	catch (int e)
	{
		if (e == 1)
		{
			return 1;
		}
	}
	outputArrayToFile(arrStart, workAreaEnd, arrEnd);

	delete[] arrStart;
	std::cout << "Done" << std::endl;
	return 0;
}