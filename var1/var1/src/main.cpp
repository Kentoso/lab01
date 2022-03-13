#include <iostream>
#include <iomanip>
#include <cmath>
#include "../include/array_modifications.h"

int menu() {
	std::cout << "What do you want to do?: \n1 - fill the array with pseudorandom numbers.\n2 - input numbers yourself.\n9 - end the execution of this program." << std::endl;
	bool repeat = false;
	char action;
	do
	{
		std::cin >> action;
		switch (action)
		{
		case '1':
			return 1;
		case '2':
			return 2;
		case '9':
			return 9;
		default:
			repeat = true;
			std::cout << "Try again" << std::endl;
			break;
		}
	} while (repeat);
}

void outGreetingsMessage() {
	std::cout << "Lab 1: working with C++ containers (variant 1 {42, 75})" << std::endl;
	std::cout << "Group: K-15" << std::endl;
	std::cout << "Author: Demian Samus" << std::endl;
}

int countDigits(int number) {
	int length = 1;
	while (number /= 10) length++;
	return length;
}

void outputArray(int* arr, int n) {
	int digits = 0, cellWidth = 0, lineWidth = 0;
	for (int i = 0; i < n; i++)
	{
		digits = countDigits(arr[i]);
		cellWidth = std::max(digits + 5, 12);
		std::cout << '|';
		if (i != 0)
		{
			if (i % 5 == 0)
			{
				std::cout << std::endl;
				std::cout << '|';
				for (int j = 0; j < lineWidth + 4; j++)
				{
					std::cout << '-';
				}
				std::cout << '|';
				std::cout << std::endl;
				std::cout << '|';
				lineWidth = 0;
			}

		}
		std::cout << std::setw(cellWidth) << std::right << arr[i];
		lineWidth += cellWidth;
	}
	std::cout << '|';
}

int main() {
	const int N = ARRAY_LENGTH;
	int workArea = N;
	int arr[N]{ 0 };
	outGreetingsMessage();
	int menuSelection = menu();
	bool result = false;

	if (menuSelection == 1)
	{
		srand(time(0));
		result = randomNumbers(arr, workArea);
	}
	else if (menuSelection == 2)
	{
		result = inputNumbers(arr, workArea);
	}
	else if (menuSelection == 9)
	{
		std::cout << "Ending the execution..." << std::endl;
		return 0;
	}
	if (result)
	{
		std::cout << "Array: " << std::endl;
		outputArray(arr, workArea);
	}
	else
	{
		std::cout << "Sorry, but input was unsuccessfull (zero numbers were set)" << std::endl;
	}
	return 0;
}