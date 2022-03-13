#include <iostream>
#include "../include/array_modifications.h"

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

bool inputNumbers(int(&arr)[ARRAY_LENGTH], int& n) {
	int numbersSet = 0;
	int input;
	for (int i = 0; i < n; i++)
	{
		std::cout << "You are inputting a value for the integer with index " << i << std::endl;
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cout << "Ending input. Numbers set: " << numbersSet << std::endl;
			break;
		}
		numbersSet++;
		arr[i] = input;
	}
	n = numbersSet;
	return numbersSet != 0;
}

bool randomNumbers(int(&arr)[ARRAY_LENGTH], int& n) {
	int numbersSet = 0;
	int workArea = (rand() % n) + 1;
	std::cout << "Work area of the array: " << workArea << std::endl;
	for (int i = 0; i < workArea; i++)
	{
		arr[i] = rand() % 20;
		numbersSet++;
	}
	n = numbersSet;
	return numbersSet != 0;
}