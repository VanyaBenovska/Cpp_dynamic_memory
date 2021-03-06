// 04_01_Compare_Arrays_POINTERs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<sstream>
#include<iomanip>                       
using namespace std;

int * AllocateIntArrMem(int vSize)
{
	int * ptrV = new int[vSize];
	return ptrV;
}

int CountElements(string line) {
	istringstream iss(line);
	int count = 0, num;
	while (iss >> num)
	{
		count++;
	}
	return count;
}
void FillElements(int * pArr, int numberElements, string line)
{
	istringstream iss(line);
	int num;
	int i = 0;
	while (iss >> num)
	{
		pArr[i] = num;
		i++;
	}
}

bool AreEqual(int * pArr1, int * pArr2, int arrSize)
{
	for (int i = 0; i <arrSize; i++)
	{
		if (pArr1[i] != pArr2[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	string line;
	getline(cin, line);

	int numElements1 = CountElements(line);
	int * pArr1 = AllocateIntArrMem(numElements1);
	FillElements(pArr1, numElements1, line);

	getline(cin, line);
	int numElements2 = CountElements(line);
	int * pArr2 = AllocateIntArrMem(numElements2);
	FillElements(pArr2, numElements2, line);

	if (numElements1 != numElements2)
	{
		cout << "not equal" << endl;
	}
	else
	{
		if (AreEqual(pArr1, pArr2, numElements1))
		{
			cout << "equal" << endl;
		}
		else
		{
			cout << "not equal" << endl;
		}
	}
	delete[] pArr1;
	delete[] pArr2;
	return 0;
}
