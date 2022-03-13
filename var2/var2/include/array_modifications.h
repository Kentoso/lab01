#pragma once
#define CIN_IGNORE 2147483647
#define ARRAY_LENGTH 13

void getValue(int& value, const char* prompt);

bool inputNumbers(int(&arr)[ARRAY_LENGTH], int& n);

bool randomNumbers(int(&arr)[ARRAY_LENGTH], int& n);

void processArray(int task, int* arrStart, int*& workAreaEnd, int* arrEnd);

void task42(int* arrStart, int*& workAreaEnd, int* arrEnd, int newValue);

void task75(int* arrStart, int*& workAreaEnd, int* arrEnd, int newValue);