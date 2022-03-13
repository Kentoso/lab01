#pragma once
#include <string>
#include <fstream>
#include <vector>
#define CIN_IGNORE 2147483647

void getValue(int& value, const char* prompt);

void doubleArray(int*& arrStart, int*& workAreaEnd, int*& arrEnd);

void processArray(int task, std::vector<int>& vec);

void task42(std::vector<int>& vec, int newValue);

void task75(std::vector<int>& vec, int newValue);