#include "pch.h"
#include "proc.cpp"

TEST(MinMaxTest, FindsMinMax)
{
	Arguments arg;
	int* arr;

	size_t size = 5;

	arr = new int[size];
	arr[0] = 15;
	arr[1] = 88;
	arr[2] = 322;
	arr[3] = -2;
	arr[4] = 2;

	arg.arr = arr;
	arg.n = size;

	MinMaxWinApi(&arg);

	EXPECT_EQ(arg.max, 322);
	EXPECT_EQ(arg.min, -2);
	delete[] arr;
}

TEST(MinMaxTest, ThrowsOnInvalidArgs)
{
	EXPECT_THROW(MinMaxWinApi(nullptr), std::runtime_error);
}

TEST(AverageTest, CalculatesCorrectAverage)
{
	int arr[] = { 2, 4, 6, 8 };
	Arguments arg;
	arg.arr = arr;
	arg.n = 4;

	AverageWinApi(&arg);

	EXPECT_EQ(arg.average, 5.0);
}

TEST(AverageTest, ReturnsErrorCodeOnNullData)
{
	DWORD res = AverageWinApi(nullptr);
	EXPECT_EQ(res, 1);
}

TEST(AverageTest, ReturnsZeroOnSuccess)
{
	int arr[] = { 10, 20, 30 };
	Arguments arg;
	arg.arr = arr;
	arg.n = 3;

	DWORD res = AverageWinApi(&arg);
	EXPECT_EQ(res, 0);
	EXPECT_DOUBLE_EQ(arg.average, 20.0);
}