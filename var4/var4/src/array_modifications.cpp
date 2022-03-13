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

