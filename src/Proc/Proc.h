#define NOMINMAX
#include <iostream>
#include <windows.h>
#include "thread.h"

#include <string>

constexpr DWORD MINMAXSLEEPTIME = 7;
constexpr DWORD AVERAGESLEEPTIME = 12;

struct Arguments
{
	int max = 0;
	int min = 0;

	int* arr = nullptr;
	size_t n = 0;

	double average = 0.0f;
};

DWORD WINAPI MinMaxWinApi(LPVOID lpParam);

DWORD WINAPI AverageWinApi(LPVOID lpParam);

void MinMax(int* arr, size_t n, int& max, int& min);

void Average(int* arr, size_t n, double& avg);

