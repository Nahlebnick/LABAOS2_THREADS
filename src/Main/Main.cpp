// Main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Proc.h"
#include "inputUtils.h"

void PrintArray(int* arr, size_t n)
{
    std::cout << "Elements of the array\n";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << (i + 1) << ") " << arr[i] << '\t';
    }
    std::cout << std::endl;
}

int main()
{
    int min, max;
    double average;
    int* arr;
    int n;
    std::cout << "Enter size of array" << std::endl;
    
    inputValue(n);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    try
    {
        arr = new int[n];
        EnterArray(arr, n);
        MinMax(arr, n, max, min);
        Average(arr, n, average);

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }    
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] == min || arr[i] == max) arr[i] = average;
    }
    std::cout << "Array after exchanging min/max values with average value\n";
    PrintArray(arr, n);
    delete[] arr;
    return 0;
    
}