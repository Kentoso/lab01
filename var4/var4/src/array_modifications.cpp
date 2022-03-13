#include <iostream>
#include "../include/array_modifications.h"

void doubleArray(int*& arrStart, int*& workAreaEnd, int*& arrEnd) {
	int length = arrEnd - arrStart;
	int workArea = workAreaEnd - arrStart;

	int* newArrStart = new(std::nothrow) int[2 * length];
	if (newArrStart == NULL)
	{
		std::cout << "MEMORY ALLOC: " << workAreaEnd - arrStart << " " << arrEnd - arrStart << " FAILED" << std::endl;
		throw 1;
	}
	for (int* i = arrStart; i < workAreaEnd; i++)
	{
		newArrStart[i - arrStart] = *i;
	}

	delete[] arrStart;
	arrStart = newArrStart;
	workAreaEnd = arrStart + workArea;
	arrEnd = arrStart + 2 * length;
	std::cout << "MEMORY ALLOC: " << workAreaEnd - arrStart << " " << arrEnd - arrStart << std::endl;
}

void getValue(int& value, const char* prompt) {
	std::cout << prompt << std::endl;
	bool repeat = false;
	do
	{
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(CIN_IGNORE, '\n');
		}
		std::cin >> value;
		repeat = false;
		if (std::cin.fail())
		{
			repeat = true;
			std::cout << "Try again" << std::endl;
		}
	} while (repeat);
}

