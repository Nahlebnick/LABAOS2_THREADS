#include "Proc.h"

DWORD WINAPI MinMaxWinApi(LPVOID lpParam)
{
	Arguments* lpData = static_cast<Arguments*>(lpParam);

	lpData->max = lpData->arr[0];
	lpData->min = lpData->arr[0];

	for (size_t i = 1; i < lpData->n; i++)
	{
		if (lpData->arr[i] < lpData->min)
			lpData->min = lpData->arr[i];
		if (lpData->arr[i] > lpData->max) lpData->max = lpData->arr[i];
		Sleep(MINMAXSLEEPTIME);
	}
	std::cout << "\t=====End result=====\n";
	std::string res = "Min - " + std::to_string(lpData->min) + "; Max - " + std::to_string(lpData->max);
	std::cout << res << std::endl;
	return 0;
}

DWORD WINAPI AverageWinApi(LPVOID lpParam)
{
	Arguments* lpData = (Arguments*)(lpParam);
	if (!lpData || !lpData->n)
	{
		return -1;
	}

	lpData->average = 0;

	for (size_t i = 0; i < lpData->n; i++)
	{
		lpData->average += lpData->arr[i];
		Sleep(AVERAGESLEEPTIME);
	}
	lpData->average /= lpData->n;
	std::cout << "\t=====End result=====\n";
	std::cout << "Average - " << lpData->average << std::endl;
	return 0;
}

void MinMax(int* arr, size_t n, int& max, int& min)
{
	Arguments arg;

	if (!arr)
	{
		throw std::runtime_error("Incorrect data passed to the MinMax");
	}

	arg.arr = arr;
	arg.n = n;

	Thread MinMaxThread(MinMaxWinApi, &arg);
	MinMaxThread.join();

	max = arg.max;
	min = arg.min;
}

void Average(int* arr, size_t n, double& avg)
{
	Arguments arg;
	if (!arr)
	{
		throw std::runtime_error("Incorrect data passed to the Average");
	}
	arg.arr = arr;
	arg.n = n;

	Thread AverageThread(AverageWinApi, &arg);
	AverageThread.join();

	avg = arg.average;
}




