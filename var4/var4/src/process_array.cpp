#include "../include/array_modifications.h"
#include <cmath>
#include <iostream>
#include <vector>
bool isPrime(int number) {
	if (number < 2)
	{
		return false;	
	}
	for (int i = 2; i <= std::sqrt(number); i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

void processArray(int task, std::vector<int>& vec) {
	int newValue = -1;
	getValue(newValue, "Input new value");
	switch (task)
	{
		case 42: 
			task42(vec, newValue);
			break;
		case 75:
			task75(vec, newValue);
			break;
	}
}

void task42(std::vector<int>& vec, int newValue) {
	int maxIndex;
	int maxValue = -1;
	std::vector<int> minIndex;
	int minValue = CIN_IGNORE;
	for (auto a = vec.begin(); a < vec.end(); a++)
	{
		if (*a > maxValue)
		{
			maxValue = *a;
			maxIndex = a - vec.begin();
		}
		if (*a < minValue)
		{
			minValue = *a;
		}
	}
	for (auto i = vec.begin(); i < vec.end(); i++)
	{
		if (*i == minValue)
		{
			minIndex.push_back(i - vec.begin() + (int)(i - vec.begin() > maxIndex));
		}
	}
	vec.insert(vec.begin() + maxIndex + 1, newValue);
	for (auto i = minIndex.begin(); i < minIndex.end(); i++)
	{
		vec.insert(vec.begin() + *i, newValue);
		for (auto j = i; j < minIndex.end(); j++)
		{
			(*j)++;
		}
	}
}

void task75(std::vector<int>& vec, int newValue) {
	std::vector<int> primeIndex;
	for (auto i = vec.begin(); i < vec.end(); i++)
	{
		if (isPrime(*i))
		{
			primeIndex.push_back(i - vec.begin());
		}
	}
	for (auto i = primeIndex.begin(); i < primeIndex.end(); i++)
	{
		vec.insert(vec.begin() + *i, newValue);
		for (auto j = i; j < primeIndex.end(); j++)
		{
			(*j)++;
		}
	}
}