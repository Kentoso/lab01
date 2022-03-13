#pragma once
#include <string>
#include <fstream>
#define CIN_IGNORE 2147483647

void getValue(int& value, const char* prompt);

void doubleArray(int*& arrStart, int*& workAreaEnd, int*& arrEnd);

void processArray(int task, int* arrStart, int*& workAreaEnd, int* arrEnd);

void task42(int* arrStart, int*& workAreaEnd, int* arrEnd, int newValue);

void task75(int* arrStart, int*& workAreaEnd, int* arrEnd, int newValue);