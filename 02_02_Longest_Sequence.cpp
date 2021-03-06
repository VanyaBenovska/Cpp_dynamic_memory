// 02_02_Longest_Sequence.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include <string>
#include<iomanip>                       
using namespace std;

int CountFinder(int arr[], const int& arrSize)
{
	int number_to_which_count_looking = arr[arrSize - 1];
	int count = 0;
	for (int i = 0; i < arrSize; i ++)
	{
		if(arr[i] == number_to_which_count_looking)
		{
			count++;
		}
	}
	return count;
}

int * CopyElements(int destarr[], int& destSize, int currarr[], int& currSize)
{
	for (int i = 0; i < currSize; i ++)
	{
		destarr[i] = currarr[i];
	}
	return destarr;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;
	int * parr = new int[0];

	//int number;	
	int best_counts_repeatedNumber, nextNum, best_count = 0;
	
	for (int i = 0; i < n; i ++)
	{
		int * newParr = new int[i + 1];
		int newSize = i + 1;
		int currsize = i;

		cin >> nextNum;
		CopyElements(newParr , newSize, parr , currsize);
		newParr[i] = nextNum;
		delete[] parr;
		parr = newParr;

		int newCount = CountFinder(parr, newSize);
		if (newCount >= best_count)
		{
			best_counts_repeatedNumber = nextNum;
			best_count = newCount;
		}

	}

	for (int i = 0; i < best_count; i ++)
	{
		cout << best_counts_repeatedNumber << " ";
	}
	cout << endl;
    return 0;
}

