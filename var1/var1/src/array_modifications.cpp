#include <iostream>
#include "../include/array_modifications.h"


bool inputNumbers(int(&arr)[ARRAY_LENGTH], int& n) {
	int numbersSet = 0;
	int input;
	for (int i = 0; i < n; i++)
	{
		std::cout << "You are inputting a value for the integer with index " << i << std::endl;
		std::cin >> input;
		if (std::cin.bad() || std::cin.fail())
		{
			std::cout << "Ending input. Numbers set: " << numbersSet << std::endl;
			std::cin.clear();
			std::cin.ignore(CIN_IGNORE, '\n');
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
		arr[i] = rand();
		numbersSet++;
	}
	n = numbersSet;
	return numbersSet != 0;
}