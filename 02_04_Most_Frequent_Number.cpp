// 02_04_Most_Frequent_Number.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include <string>
#include<cmath>   
#include<iomanip>                       
using namespace std;

int BiggerCountFinder(int arr[], int arrSize)
{
	int max_count = 0;
	for (int i = 0; i < arrSize; i ++)
	{
		if (arr[i] > max_count)
		{
			max_count = arr[i];
		}
	}
	return max_count;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int * parr = new int[10]();

	int n;
	cin >> n;
	int number;
	for (int i = 0; i < n; i ++)
	{
		cin >> number;
		parr[number] ++;
	}
	int biggest_count_of_repeating_number = BiggerCountFinder(parr, 10);

	for (int i = 0; i < 10; i++)
	{
		if (parr[i] == biggest_count_of_repeating_number)
		{
			cout << i << " ";
		}
	}
	cout << endl;
	delete[] parr;
    return 0;
}

