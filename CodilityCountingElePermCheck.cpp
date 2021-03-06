// CodilityCountingElePermCheck.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "vector"
#include "algorithm"

int solution(std::vector<int> &A)
{
	std::sort(A.begin(), A.end());
	for (int loopcnt = 0; loopcnt < A.size(); ++loopcnt)
	{
		//Permutaion does not contain 0, so starting from 1
		if (A[loopcnt] == loopcnt + 1) 
		{
			continue;
		}
		else
		{
			return 0; //failed
		}
	}
	return 1;//success
}

bool checkers(int &numOfElements)
{
	if (numOfElements == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool inputVector(std::vector<int> &A,int &numOfElements)
{
	std::cout << "Enter the number of elements: " << std::endl;
	std::cin >> numOfElements;

	if (checkers(numOfElements))
	{
		std::cout << "Enter the contents of elements: " << std::endl;
		for (int input = 0; input < numOfElements; ++input)
		{
			std::cin >> A[input];
		}
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	std::vector<int> A = {4,1,3};

	int numOfElements = 0;

	bool inputs = true;
	inputs = inputVector(A, numOfElements);

	if (inputs == true)
	{
		int status = solution(A);
		std::cout << "Return Status: " << status << std::endl;
	}
	else
	{
		std::cout << "The vector is empty" << std::endl;
	}
    return 0;
}

