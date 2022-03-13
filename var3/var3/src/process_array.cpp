#include "../include/array_modifications.h"
#include <cmath>
#include <iostream>
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

void shiftElements(int* arrStart, int*& workAreaEnd, int* arrEnd, int index) {
	if (workAreaEnd == arrEnd) return;
	for (int* i = workAreaEnd; i > arrStart + index; i--)
	{
		*i = *(i - 1);
	}
	workAreaEnd++;
}

void processArray(int task, int* arrStart, int*& workAreaEnd, int* arrEnd) {
	if (workAreaEnd == arrEnd)
	{
		doubleArray(arrStart, workAreaEnd, arrEnd);
	}
	int newValue = -1;
	getValue(newValue, "Input new value");
	switch (task)
	{
		case 42: 
			task42(arrStart, workAreaEnd, arrEnd, newValue);
			break;
		case 75:
			task75(arrStart, workAreaEnd, arrEnd, newValue);
			break;
	}
}

void task42(int* arrStart, int*& workAreaEnd, int* arrEnd, int newValue) {
	int maxIndex = -1, maxValue = -1;
	int* minIndex = new int[workAreaEnd - arrStart];
	int minIndexLength = 0;
	int minValue = CIN_IGNORE;
	for (int* i = arrStart; i < workAreaEnd; i++)
	{
		if (*i > maxValue)
		{
			maxIndex = i - arrStart;
			maxValue = *i;
		}
		if (*i < minValue)
		{
			minValue = *i;
		}
	}
	for (int* i = arrStart; i < workAreaEnd; i++)
	{
		if (*i == minValue)
		{
			if (i - arrStart > maxIndex)
			{
				minIndex[minIndexLength] = i - arrStart + 1;
			}
			else
			{
				minIndex[minIndexLength] = i - arrStart;
			}
			minIndexLength++;
		}
	}
	if (workAreaEnd == arrEnd)
	{
		doubleArray(arrStart, workAreaEnd, arrEnd);
	}
	shiftElements(arrStart, workAreaEnd, arrEnd, maxIndex + 1);
	arrStart[maxIndex + 1] = newValue;
	for (int i = 0; i < minIndexLength; i++)
	{
		if (workAreaEnd == arrEnd)
		{
			doubleArray(arrStart, workAreaEnd, arrEnd);
		}
		shiftElements(arrStart, workAreaEnd, arrEnd, minIndex[i]);
		arrStart[minIndex[i]] = newValue;
		for (int j = i; j < minIndexLength; j++)
		{
			minIndex[j]++;
		}
	}
	delete[] minIndex;
}

void task75(int* arrStart, int*& workAreaEnd, int* arrEnd, int newValue) {
	int* primeIndex = new int[workAreaEnd - arrStart];
	int primeIndexLength = 0;
	for (int* i = arrStart; i < workAreaEnd; i++)
	{
		if (isPrime(*i))
		{
			primeIndex[primeIndexLength] = i - arrStart;
			primeIndexLength++;
		}	
	}
	for (int i = 0; i < primeIndexLength; i++)
	{
		shiftElements(arrStart, workAreaEnd, arrEnd, primeIndex[i]);
		arrStart[primeIndex[i]] = newValue;
		for (int j = i; j < primeIndexLength; j++)
		{
			primeIndex[j]++;
		}
		if (workAreaEnd == arrEnd)
		{
			doubleArray(arrStart, workAreaEnd, arrEnd);
		}
	}
	delete[] primeIndex;
}